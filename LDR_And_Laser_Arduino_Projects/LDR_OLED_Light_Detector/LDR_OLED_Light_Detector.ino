#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define LDR_DO 2

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  pinMode(LDR_DO, INPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.clearDisplay();
}

void loop() {
  int ldrState = digitalRead(LDR_DO);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  if (ldrState == HIGH) {
    display.setCursor(25, 25);
    display.println("DARK");
  } else {
    display.setCursor(15, 25);
    display.println("BRIGHT");
  }

  display.display();

  delay(200);
}