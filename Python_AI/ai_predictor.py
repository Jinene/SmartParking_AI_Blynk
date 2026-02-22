import requests
from datetime import datetime
import time

BLYNK_TOKEN = "YOUR_BLYNK_AUTH_TOKEN"
BLYNK_URL = f"http://blynk-cloud.com/{BLYNK_TOKEN}/get/V1,V2,V3,V4"

status_history = []

def get_slot_status():
    r = requests.get(BLYNK_URL)
    data = r.json()
    return data

def predict_busy_period(history):
    if len(history) < 5:
        return "Not enough data"
    avg_occupancy = sum(history[-5:])/len(history[-5:])
    if avg_occupancy > 0.75:
        return "High traffic expected"
    elif avg_occupancy < 0.25:
        return "Low traffic expected"
    return "Moderate traffic expected"

while True:
    status = get_slot_status()
    occupancy = sum(status)/len(status)
    status_history.append(occupancy)
    
    prediction = predict_busy_period(status_history)
    print(f"{datetime.now()} - Status: {status} - Prediction: {prediction}")
    
    time.sleep(10)  # Check every 10 seconds
