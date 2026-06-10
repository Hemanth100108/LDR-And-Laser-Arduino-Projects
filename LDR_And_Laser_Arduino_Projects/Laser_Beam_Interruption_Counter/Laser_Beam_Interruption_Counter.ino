#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define LDR_PIN     2
#define RESET_PIN   3
#define LASER_PIN   7
#define BUZZER_PIN  9

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int intrusionCount = 0;
bool beamBroken = false;

void setup() {
  pinMode(LDR_PIN, INPUT);
  pinMode(RESET_PIN, INPUT_PULLUP);
  pinMode(LASER_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

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

  // Reset counter when button is pressed
  if (digitalRead(RESET_PIN) == LOW) {
    intrusionCount = 0;
    delay(300);
  }

  // Beam interrupted
  if (beamState == HIGH && !beamBroken) {

    intrusionCount++;
    beamBroken = true;

    // Special alert every 10 intrusions
    if (intrusionCount % 10 == 0) {

      for (int i = 0; i < 5; i++) {
        digitalWrite(BUZZER_PIN, HIGH);
        delay(200);

        digitalWrite(BUZZER_PIN, LOW);
        delay(100);
      }

    } else {

      // Normal short beep
      digitalWrite(BUZZER_PIN, HIGH);
      delay(150);

      digitalWrite(BUZZER_PIN, LOW);
    }
  }

  // Beam restored
  if (beamState == LOW) {
    beamBroken = false;
  }

  // OLED Display
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.println("Laser");

  display.setCursor(0, 18);
  display.println("Counter");

  display.setTextSize(1);
  display.setCursor(0, 48);
  display.print("Intrusions: ");

  if (intrusionCount < 10)
    display.print("0");

  display.print(intrusionCount);

  display.display();

  delay(50);
}