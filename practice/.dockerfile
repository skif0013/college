FROM python:3.9-slim

WORKDIR /app

COPY . .

RUN pip install --no-cache-dir fastapi uvicorn requests python-dotenv

CMD ["uvicorn", "api_request:app", "--host", "0.0.0.0", "--port", "8000"]