from fastapi import FastAPI, Query, Header, HTTPException
from fastapi.responses import JSONResponse, Response
import requests
import os
from dotenv import load_dotenv
import threading
import time
import json
from datetime import datetime


load_dotenv() 
app = FastAPI()

API_PASSWORD = os.getenv("API_PASSWORD")

ALERT_LOG_FILE = "alerts_stats.txt"

SOURCE_URL = "https://ubilling.net.ua/aerialalerts/"

def check_password(x_api_key: str):
    if not x_api_key or x_api_key != API_PASSWORD:
        raise HTTPException(status_code=401, detail="Unauthorized: Invalid or missing API key")

@app.get("/alerts")
def get_alert(sity: str = Query(None, alias="sity"), format: str = Query("json"), x_api_key: str = Header(None)):
    check_password(x_api_key)
    
    try:
        url = SOURCE_URL
        headers = {}

        if format.lower() == "xml":
            url += "?xml=true"
            response = requests.get(url)
            if response.status_code == 200:
                return Response(content=response.text, media_type="application/xml")
            else:
                return JSONResponse(status_code=500, content={"error": "Failed to retrieve XML data from external API"})

        response = requests.get(url)
        if response.status_code == 200:
            data = response.json()
            if sity:
                city_data = data.get("states", {}).get(sity)
                if city_data:
                    return {
                        "source": data.get("source"),
                        "cachedat": data.get("cachedat"),
                        "city": sity,
                        "alertnow": city_data["alertnow"],
                        "changed": city_data["changed"]
                    }
                else:
                    return JSONResponse(status_code=404, content={"error": f"City '{sity}' not found"})
            else:
                return data
        else:
            return JSONResponse(status_code=500, content={"error": "Failed to retrieve data from external API"})
    except Exception as e:
        return JSONResponse(status_code=500, content={"error": str(e)})

@app.get("/status")
def get_alert_stats(sity: str = Query(None, alias="sity")):
    stats = {}
    try:
        if not os.path.exists(ALERT_LOG_FILE):
            return JSONResponse(status_code=404, content={"error": "Stats file not found"})

        with open(ALERT_LOG_FILE, "r", encoding="utf-8") as f:
            lines = f.readlines()

        current_snapshot = {}
        for line in lines:
            line = line.strip()
            if not line:
                if current_snapshot:
                    for city, count in current_snapshot.items():
                        stats[city] = count
                    current_snapshot = {}
                continue

            if "Alerts today:" in line:
                continue

            if "|" in line:
                continue 

            if ":" in line:
                city, count = line.rsplit(":", 1)
                city = city.strip()
                count = int(count.strip())
                current_snapshot[city] = count

        if current_snapshot:
            for city, count in current_snapshot.items():
                stats[city] = count

        if sity:
            city_stats = stats.get(sity)
            if city_stats is None:
                return JSONResponse(status_code=404, content={"error": f"City '{sity}' not found in stats"})
            return {sity: city_stats}

        return stats

    except Exception as e:
        return JSONResponse(status_code=500, content={"error": str(e)})



def count_all_alerts():
    total_alerts_by_city = {}  
    active_alerts = {}         

    while True:
        try:
            response = requests.get(SOURCE_URL)
            if response.status_code == 200:
                data = response.json()
                states = data.get("states", {})

                now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

                for city, alert_info in states.items():
                    current_alert = alert_info.get("alertnow", False)


                    if city not in total_alerts_by_city:
                        total_alerts_by_city[city] = 0
                        active_alerts[city] = False


                    if current_alert and not active_alerts[city]:
                        total_alerts_by_city[city] += 1
                        active_alerts[city] = True
                    elif not current_alert:
                        active_alerts[city] = False


                with open(ALERT_LOG_FILE, "a", encoding="utf-8") as f:
                    f.write(f"{now} | Alerts today:\n")
                    for city, count in total_alerts_by_city.items():
                        f.write(f"  {city}: {count}\n")
                    f.write("\n")
        except Exception as e:
            print("Error while counting alerts:", str(e))

        time.sleep(10) 


def start_background_task():
    thread = threading.Thread(target=count_all_alerts, daemon=True)
    thread.start()

start_background_task()