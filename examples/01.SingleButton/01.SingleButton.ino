/*
 * Created by ArduinoGetStarted.com, modified by Viden Djurs
 *
 * This example code is in the public domain
 *
 * Master for original library: https://arduinogetstarted.com/tutorials/arduino-button-library
 *
 * This example reads the state of a button without debounce and print it to Serial Monitor.
 */

#include <ezButton.h>
#include <Keyboard.h>

ezButton button(2, 'a');  // create ezButton object that attaches to pin 2 and sends 'a' key

void setup() {
  Keyboard.begin();
}

void loop() {
  button.loop(); // Must call the loop function first

  if (button.isPressed()) {
    // Simulates 'a' keypress
    Serial.println("The button is pressed, 'a' key sent");
  }

  if (button.isReleased()) {
    // Stops pressing the 'a' key
    Serial.println("The button is released, 'a' key released");
  }
}
