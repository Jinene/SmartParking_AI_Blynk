#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <NewPing.h>

// ----- WIFI & BLYNK -----
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// ----- SENSORS SETUP -----
#define NUM_SLOTS 4
#define MAX_DISTANCE 200 // cm

// Assign ultrasonic pins
#define TRIG1 13
#define ECHO1 12
#define TRIG2 14
#define ECHO2 27
#define TRIG3 26
#define ECHO3 25
#define TRIG4 33
#define ECHO4 32

NewPing sensors[NUM_SLOTS] = {
  NewPing(TRIG1, ECHO1, MAX_DISTANCE),
  NewPing(TRIG2, ECHO2, MAX_DISTANCE),
  NewPing(TRIG3, ECHO3, MAX_DISTANCE),
  NewPing(TRIG4, ECHO4, MAX_DISTANCE)
};

// Slot status
int slotStatus[NUM_SLOTS] = {0};

// Blynk LEDs
WidgetLED led1(V1);
WidgetLED led2(V2);
WidgetLED led3(V3);
WidgetLED led4(V4);

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  checkSlots();
  delay(1000);
}

void checkSlots() {
  for (int i = 0; i < NUM_SLOTS; i++) {
    int distance = sensors[i].ping_cm();
    slotStatus[i] = (distance > 0 && distance < 30) ? 1 : 0;
  }
  
  // Update Blynk LEDs
  led1.setValue(slotStatus[0] ? 255 : 0);
  led2.setValue(slotStatus[1] ? 255 : 0);
  led3.setValue(slotStatus[2] ? 255 : 0);
  led4.setValue(slotStatus[3] ? 255 : 0);

  // Serial monitor
  Serial.print("Slots: ");
  for(int i=0;i<NUM_SLOTS;i++){ Serial.print(slotStatus[i]); Serial.print(" "); }
  Serial.println();
}
