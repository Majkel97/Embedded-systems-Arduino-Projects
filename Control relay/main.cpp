/**
 * This program controls a relay using an Arduino board and displays the relay status on an LCD.
 */

#include <LiquidCrystal.h> // Import the library for controlling the LCD display

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // Assign Arduino pins to the corresponding LCD pins

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Declare an object of type LiquidCrystal

int ledpin = 6; // Declare a variable to control the relay and assign the pin

/**
 * Function executed once at the beginning to initialize the program.
 */
void setup()
{
	pinMode(ledpin, OUTPUT); // Configure the pin connected to the relay as output
	lcd.begin(16, 2);		 // Initialize the LCD display (size: 16 x 2)
	lcd.print("Przekaznik"); // Display text on the LCD
	Serial.begin(9600);		 // Open the serial console
}

/**
 * Function to control the relay state and display status on the LCD.
 * @param relayState The state to set the relay (HIGH or LOW).
 * @param lcdText The text to display on the LCD.
 * @param serialText The text to print to the serial console.
 * @param delayTime The delay duration in milliseconds.
 */
void controlRelay(int relayState, const char *lcdText, const char *serialText, int delayTime)
{
	digitalWrite(ledpin, relayState); // Set the relay state
	lcd.setCursor(0, 1);			  // Set the cursor position to the second line and first column
	lcd.print(lcdText);				  // Display text on the LCD
	Serial.println(serialText);		  // Print text to the serial console
	delay(delayTime);				  // Delay
}

/**
 * Function executed repeatedly in an infinite loop.
 */
void loop()
{
	controlRelay(HIGH, "zalaczony", "Przekaznik zalaczony", 5000); // Turn on the relay for 5 seconds

	controlRelay(LOW, "wylaczony", "Przekaznik wylaczony", 5000); // Turn off the relay for 5 seconds
}