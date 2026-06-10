#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define LDR_PIN   2   // D0 from LDR module
#define LED_PIN   8   // Indicator LED
#define LASER_PIN 7   // Laser module signal pin

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LASER_PIN, OUTPUT);

  // Turn laser ON
  digitalWrite(LASER_PIN, HIGH);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.clearDisplay();
  display.display();
}

void loop() {
  int beamState = digitalRead(LDR_PIN);

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(20, 0);
  display.println("Beam Status");

  // For your LDR module:
  // LOW = Light detected
  // HIGH = No light detected

  if (beamState == LOW) {
    digitalWrite(LED_PIN, HIGH);

    display.setTextSize(2);
    display.setCursor(0, 30);
    display.println("DETECTED");
  }
  else {
    digitalWrite(LED_PIN, LOW);

    display.setTextSize(2);
    display.setCursor(20, 30);
    display.println("LOST!");
  }

  display.display();
  delay(100);
}