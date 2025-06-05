# Используем официальный Python образ
FROM python:3.9-slim

# Рабочая директория внутри контейнера
WORKDIR /app

# Копируем файл с приложением
COPY api_request.py /app/

# Устанавливаем зависимости
RUN pip install --no-cache-dir fastapi uvicorn requests

# Открываем порт 8000
EXPOSE 8000

# Команда запуска uvicorn с перезагрузкой (для dev можно убрать в продакшн)
CMD ["uvicorn", "api_request:app", "--host", "0.0.0.0", "--port", "8000"]