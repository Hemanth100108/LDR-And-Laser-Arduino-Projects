#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define LDR_PIN    2
#define LASER_PIN  7
#define LED_PIN    8
#define BUZZER_PIN 9

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  pinMode(LDR_PIN, INPUT);
  pinMode(LASER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Turn laser ON continuously
  digitalWrite(LASER_PIN, HIGH);

  // Alarm OFF initially
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.clearDisplay();
  display.display();
}

void loop() {

  int beamState = digitalRead(LDR_PIN);

  // For most LDR modules:
  // LOW  = Laser beam detected
  // HIGH = Beam interrupted

  if (beamState == LOW) {

    // Monitoring Mode
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(5, 0);
    display.println("SECURITY");

    display.setCursor(25, 20);
    display.println("MODE");

    display.setTextSize(1);
    display.setCursor(10, 50);
    display.println("MONITORING...");

    display.display();

    delay(100);
  }
  else {

    // Intruder Detected
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.println("!! ALERT !!");

    display.setTextSize(1);
    display.setCursor(20, 30);
    display.println("INTRUDER");

    display.setCursor(15, 45);
    display.println("DETECTED");

    display.display();

    // Buzzer ON
    digitalWrite(BUZZER_PIN, HIGH);

    // Blink LED
    digitalWrite(LED_PIN, HIGH);
    delay(200);

    digitalWrite(LED_PIN, LOW);
    delay(200);
  }
}