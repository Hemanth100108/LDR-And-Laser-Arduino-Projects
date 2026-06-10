#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define LDR_DO 2
#define LED_PIN 8

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  pinMode(LDR_DO, INPUT);
  pinMode(LED_PIN, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.clearDisplay();
  display.display();
}

void loop() {
  int ldrState = digitalRead(LDR_DO);

  // HIGH = DARK, LOW = BRIGHT
  if (ldrState == HIGH) {
    digitalWrite(LED_PIN, HIGH);   // LED ON in DARK
  } else {
    digitalWrite(LED_PIN, LOW);    // LED OFF in BRIGHT
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 10);
  display.print("LDR STATUS: ");

  if (ldrState == HIGH) {
    display.println("DARK");
  } else {
    display.println("BRIGHT");
  }

  display.setCursor(0, 35);
  display.print("LED STATUS: ");

  if (digitalRead(LED_PIN) == HIGH) {
    display.println("ON");
  } else {
    display.println("OFF");
  }

  display.display();
  delay(200);
}