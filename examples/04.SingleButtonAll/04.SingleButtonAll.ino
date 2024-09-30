/*
 * Created by ArduinoGetStarted.com, modified by Viden Djurs
 *
 * This example code is in the public domain
 *
 * Master for original library: https://arduinogetstarted.com/tutorials/arduino-button-library
 *
 * This example:
 *   + uses debounce for a button.
 *   + reads state of a button
 *   + detects the pressed and released events of a button
 */

#include <ezButton.h>
#include <Keyboard.h>

ezButton button1(2, 'x');  // create ezButton object that attaches to pin 2 and sends 'x' key
ezButton button2(3, 'y');  // create ezButton object that attaches to pin 3 and sends 'y' key

void setup() {
  Keyboard.begin();
}

void loop() {
  button1.loop();
  button2.loop();

  if (button1.isPressed()) {
    // Simulates 'x' keypress
    Serial.println("Button 1 is pressed, 'x' key sent");
  }

  if (button1.isReleased()) {
    // Stops pressing the 'x' key
    Serial.println("Button 1 is released, 'x' key released");
  }

  if (button2.isPressed()) {
    // Simulates 'y' keypress
    Serial.println("Button 2 is pressed, 'y' key sent");
  }

  if (button2.isReleased()) {
    // Stops pressing the 'y' key
    Serial.println("Button 2 is released, 'y' key released");
  }
}
