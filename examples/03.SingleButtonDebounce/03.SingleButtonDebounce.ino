/*
 * Created by ArduinoGetStarted.com, modified by Viden Djurs
 *
 * This example code is in the public domain
 *
 * Master for original library: https://arduinogetstarted.com/tutorials/arduino-button-library
 *
 * This example reads the state of a button with debounce and print it to Serial Monitor.
 */

#include <ezButton.h>
#include <Keyboard.h>

ezButton button(2, 'c');  // create ezButton object that attaches to pin 2 and sends 'c' key

void setup() {
  Keyboard.begin();
  button.setCountMode(COUNT_FALLING); // count when the button is pressed
}

void loop() {
  button.loop(); // Must call the loop function first

  if (button.isPressed()) {
    // Simulates 'c' keypress
    Serial.println("The button is pressed, 'c' key sent");
  }

  if (button.isReleased()) {
    // Stops pressing the 'c' key
    Serial.println("The button is released, 'c' key released");
  }

  Serial.print("Button pressed ");
  Serial.print(button.getCount());
  Serial.println(" times");
}
