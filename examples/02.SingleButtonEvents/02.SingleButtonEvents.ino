/*
 * Created by ArduinoGetStarted.com, modified by Viden Djurs
 *
 * This example code is in the public domain
 *
 * Master for original library: https://arduinogetstarted.com/tutorials/arduino-button-library
 *
 * This example detects the pressed and released events of a button without debounce.
 */

#include <ezButton.h>
#include <Keyboard.h>

ezButton button(7, 'b');  // create ezButton object that attaches to pin 7 and sends 'b' key

void setup() {
  Keyboard.begin();
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
}

void loop() {
  button.loop(); // Must call the loop function first

  if (button.isPressed()) {
    // Simulates 'b' keypress
    Serial.println("The button is pressed, 'b' key sent");
  }

  if (button.isReleased()) {
    // Stops pressing the 'b' key
    Serial.println("The button is released, 'b' key released");
  }
}
