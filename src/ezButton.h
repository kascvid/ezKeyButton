/*
 * Copyright (c) 2019, ArduinoGetStarted.com. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * - Neither the name of the ArduinoGetStarted.com nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ARDUINOGETSTARTED.COM "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ARDUINOGETSTARTED.COM BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ezButton_h
#define ezButton_h

#include <Arduino.h>
#include <Keyboard.h>  // Include the Arduino Keyboard library

#define COUNT_FALLING 0
#define COUNT_RISING  1
#define COUNT_BOTH    2

// Constants for button modes
#define INTERNAL_PULLUP  INPUT_PULLUP
#ifdef INPUT_PULLDOWN
#define INTERNAL_PULLDOWN INPUT_PULLDOWN
#else
#define INTERNAL_PULLDOWN INPUT
#endif

#define EXTERNAL_PULLUP   0xFE
#define EXTERNAL_PULLDOWN 0xFF

class ezButton
{
	private:
		int btnPin;
		char btnKey;              // Variable to store the keyboard key
		unsigned long debounceTime;
		unsigned long count;
		int countMode;
		int pressedState;         // State when the button is considered pressed
		int unpressedState;       // State when the button is considered unpressed

		int previousSteadyState;  // Previous steady state from the input pin, used to detect press/release events
		int lastSteadyState;      // Last steady state from the input pin
		int lastFlickerableState; // Last flickerable state from the input pin

		unsigned long lastDebounceTime; // Last time the output pin was toggled

	public:
		ezButton(int pin);                 // Constructor for pin only
		ezButton(int pin, char key);       // Constructor for pin and keyboard key
		ezButton(int pin, int mode);       // Constructor for pin with mode
		void setDebounceTime(unsigned long time);  // Set debounce time
		int getState(void);                // Get the stable state of the button
		int getStateRaw(void);             // Get the raw state of the button
		bool isPressed(void);              // Check if button is pressed and trigger key press
		bool isReleased(void);             // Check if button is released and trigger key release
		void setCountMode(int mode);       // Set the mode for counting events
		unsigned long getCount(void);      // Get the count of button presses
		void resetCount(void);             // Reset the button press count
		void loop(void);                   // Main loop function to handle debounce and state tracking
};

#endif
