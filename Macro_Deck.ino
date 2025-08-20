#include <Adafruit_NeoPixel.h>
#include <Keyboard.h>

#define LED_PIN     0        // Pin connected to NeoPixels
#define NUM_LEDS    7        // Number of NeoPixels
#define BUTTON_PIN  6        // Button connected to pin 6
// #define BUTTON_PIN1 7       // Button connected to pin 7
// #define BUTTON_PIN2 8        // Button connected to pin 8
// #define BUTTON_PIN3 9        // Button connected to pin 9
// #define BUTTON_PIN4 10       // Button connected to pin 10
// #define BUTTON_PIN5 11       // Button connected to pin 12
// #define BUTTON_PIN6 13       // Button connected to pin 13

Adafruit_NeoPixel pixels(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
bool lastState = HIGH;  // for pin 6 (create more diff name for other pins)

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); // BUTTON INPUT UP 
  // pinMode(BUTTON_PIN1, INPUT_PULLUP); // BUTTON1 INPUT UP
  // pinMode(BUTTON_PIN2, INPUT_PULLUP); // BUTTON2 INPUT UP
  // pinMode(BUTTON_PIN3, INPUT_PULLUP); // BUTTON3 INPUT UP
  // pinMode(BUTTON_PIN4, INPUT_PULLUP); // BUTTON4 INPUT UP
  // pinMode(BUTTON_PIN5, INPUT_PULLUP); // BUTTON5 INPUT UP
  // pinMode(BUTTON_PIN6, INPUT_PULLUP); // BUTTON6 INPUT UP

  // now neopixel
  pixels.begin();
  pixels.clear();
  pixels.setBrightness(0);
  Keyboard.begin();
}

void loop() { // Loop Start 

bool currentState = (digitalRead(BUTTON_PIN) == HIGH); // For Pin 6


if (currentState != lastState) { // E for Pin 6
    if (currentState == LOW) {
    Keyboard.press('e');
    pixels.setPixelColor(0, pixels.Color(0, 255, 0)); // Green LED on 0
    pixels.setBrightness(100);
    pixels.show();
    delay(5);
    Keyboard.release('e');
    pixels.clear();
    pixels.show();
    } else {
        pixels.clear();
        pixels.show();
        pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    }
    pixels.clear();
} // End for First IF statement (Pin 6)

lastState = currentState; // Saved for next loop (Pin 6)

}