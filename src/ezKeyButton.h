#ifndef ezKeyButton_h
#define ezKeyButton_h

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

class ezKeyButton
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
		ezKeyButton(int pin);                 // Constructor for pin only
		ezKeyButton(int pin, char key);       // Constructor for pin and keyboard key
		ezKeyButton(int pin, int mode);       // Constructor for pin with mode
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
