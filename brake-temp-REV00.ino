#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MAX31855.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Adafruit_MAX31855 temp-FR(MAX1_CLK, MAX1_CS, MAX1_DO);
Adafruit_MAX31855 temp-FL(MAX2_CLK, MAX2_CS, MAX2_DO);
Adafruit_MAX31855 temp-RR(MAX3_CLK, MAX3_CS, MAX3_DO);
Adafruit_MAX31855 temp-RL(MAX4_CLK, MAX4_CS, MAX4_DO);

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(1); // Wait until Serial is ready
  Serial.println("MAX31855 test");

  if (!temp-FR.begin() || !temp-FL.begin() || !temp-RR.begin() || !temp-RL.begin()) {
    Serial.println("One or more MAX31855 not found. Please check wiring!");
    while (1);
  }

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  double c1 = temp-FR.readCelsius();
  double c2 = temp-FL.readCelsius();
  double c3 = temp-RR.readCelsius();
  double c4 = temp-RL.readCelsius();

  if (isnan(c1) || isnan(c2) || isnan(c3) || isnan(c4)) {
    Serial.println("Something wrong with thermocouples!");
  } else {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("Front Right:");
    display.print(c1);
    display.println(" C");
    display.println();
    display.println("Front Left:");
    display.print(c2);
    display.println(" C");
    display.println();
    display.println("Rear Right:");
    display.print(c3);
    display.println(" C");
    display.println();
    display.println("Rear Left:");
    display.print(c4);
    display.println(" C");
    display.display();
  }
  
  delay(1000); // Wait 1 second
}
