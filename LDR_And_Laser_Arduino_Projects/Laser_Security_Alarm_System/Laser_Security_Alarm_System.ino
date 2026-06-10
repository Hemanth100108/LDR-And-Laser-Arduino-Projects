#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define LDR_PIN     2
#define RESET_PIN   3
#define LASER_PIN   7
#define LED_PIN     8
#define BUZZER_PIN  9

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int intrusionCount = 0;
bool beamBroken = false;

void setup() {
  pinMode(LDR_PIN, INPUT);
  pinMode(RESET_PIN, INPUT_PULLUP);
  pinMode(LASER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LASER_PIN, HIGH);  // Laser ON

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(10, 20);
  display.println("START");
  display.display();
  delay(1000);
}

void loop() {

  int beamState = digitalRead(LDR_PIN);

  // Reset counter button
  if (digitalRead(RESET_PIN) == LOW) {
    intrusionCount = 0;
    delay(300);
  }

  // Intrusion detected
  if (beamState == HIGH && !beamBroken) {

    intrusionCount++;
    beamBroken = true;

    digitalWrite(LED_PIN, HIGH);

    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Beam restored
  if (beamState == LOW) {
    beamBroken = false;
    digitalWrite(LED_PIN, LOW);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  if (beamState == HIGH) {

    // ALERT SCREEN
    display.setTextSize(1);

    display.setCursor(15, 0);
    display.println("SECURITY ALERT");

    display.setTextSize(2);
    display.setCursor(10, 20);
    display.println("ALERT!");

    display.setTextSize(1);
    display.setCursor(20, 45);
    display.println("INTRUDER!");

    display.setCursor(20, 56);
    display.print("Count:");
    display.print(intrusionCount);
  }
  else {

    // DASHBOARD
    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("Security System");

    display.setCursor(0, 16);
    display.print("Light : OK");

    display.setCursor(0, 28);
    display.print("Beam  : OK");

    display.setCursor(0, 40);
    display.print("Count : ");
    display.print(intrusionCount);

    display.setCursor(0, 52);
    display.print("Mode  : Armed");
  }

  display.display();
  delay(100);
}