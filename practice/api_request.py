import requests

url = "https://ubilling.net.ua/aerialalerts/"

try:
    response = requests.get(url)
    print(f"HTTP status code: {response.status_code}")

    if response.status_code == 200:
        data = response.json()
        kyiv_alert = data["states"]["м. Київ"]["alertnow"]

        if kyiv_alert:
            print("WARNING! Air raid alert in Kyiv")
        else:
            print("No air raid alert in Kyiv")
    else:
        print("Error retrieving data from the API")





except requests.exceptions.RequestException as e:
    print(f"Connection error: {e}")