#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define BUTTON_PIN 2
#define LASER_PIN 7

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

bool laserState = false;
bool lastButtonState = HIGH;
int switchCount = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LASER_PIN, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  digitalWrite(LASER_PIN, LOW);
}

void loop() {
  bool buttonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && buttonState == LOW) {
    laserState = !laserState;
    digitalWrite(LASER_PIN, laserState);

    switchCount++;
    delay(200); // debounce
  }

  lastButtonState = buttonState;

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(15, 0);
  display.println("Laser Control");

  display.setCursor(0, 25);
  display.print("Status : ");
  display.println(laserState ? "ON" : "OFF");

  display.setCursor(0, 45);
  display.print("Count  : ");

  if (switchCount < 10) display.print("0");
  display.println(switchCount);

  display.display();
}