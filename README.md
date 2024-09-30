## Fork changes
This fork includes the Arduino Keyboard library to make it easier to create buttons that acts as a keyboard.

## ezButton Library for Arduino, ESP32, ESP8266...
This library is designed to make it easy to use push button, momentary switches, toggle switch, magnetic contact switch (door sensor)..​. It is easy to use for not only beginners but also experienced users.

__ezKeyButton__ stands for __Easy Keyboard Button__


Features
----------------------------
* UPDATED FROM ORIGINAL ezButton LIBRARY: make it easier to create buttons that acts as a keyboard. Uses the write and release functions in the Keyboard.h Arduino library.
* Uses the internal pull-up resistor by default to avoid the floating value
* Supports debounce to eliminate the chattering phenomenon
* Supports the pressed and released events
* Supports the counting (for FALLING, RISING and BOTH)
* Easy to use with multiple buttons
* All functions are non-blocking 
* Support internal pull-up/pull-down, external pull-up/pull-down

Available Examples
----------------------------
These examples are modified to suit this library. Only four examples are included here. For more examples see the original ezButton library.

* [01.SingleButton](https://arduinogetstarted.com/library/button/example/arduino-single-button)
* [02.SingleButtonEvents](https://arduinogetstarted.com/library/button/example/arduino-single-button-events)
* [03.SingleButtonDebounce](https://arduinogetstarted.com/library/button/example/arduino-single-button-debounce)
* [04.SingleButtonAll](https://arduinogetstarted.com/library/button/example/arduino-single-button-all)



Available Functions
----------------------------
* setDebounceTime()
* getState()
* getStateRaw()
* isPressed() with Keyboard.write();
* isReleased() with Keyboard.release();
* setCountMode()
* getCount()
* resetCount()
* loop()

References
----------------------------
* [ezButton Library Reference](https://arduinogetstarted.com/tutorials/arduino-button-library)
