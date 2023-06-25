// Importing the library for controlling the LCD display
#include <LiquidCrystal.h>

// Declaration of integer constants - assigning Arduino pins to corresponding LCD pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

// Declaration of a LiquidCrystal variable
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Declaration of variables (LEDs) and assignment of pins to them
int led_red = 8;
int led_yellow = 9;
int led_green = 10;

/**
 * Function: setup
 * ----------------
 * This function is called once at the beginning to perform the initial setup.
 * It configures the LED pins as outputs, initializes the LCD, and displays a message on it.
 */
void setup()
{
  pinMode(led_red, OUTPUT);    // Configuring the red LED pin as an output
  pinMode(led_yellow, OUTPUT); // Configuring the yellow LED pin as an output
  pinMode(led_green, OUTPUT);  // Configuring the green LED pin as an output

  lcd.begin(16, 2);        // Initializing the LCD with a size of 16x2
  lcd.print("LED Color:"); // Displaying the message "LED Color:" on the LCD
}

/**
 * Function: loop
 * --------------
 * This function is called repeatedly in an infinite loop.
 * It cycles through the LEDs, turning them on one at a time and displaying the color on the LCD.
 * Each LED is turned on for 2 seconds before moving to the next one.
 */
void loop()
{
  lcd.setCursor(0, 1);           // Setting the cursor position to the first column of the second row
  lcd.print("Green     ");       // Displaying the text "Green" on the LCD
  digitalWrite(led_red, LOW);    // Turning off the red LED
  digitalWrite(led_yellow, LOW); // Turning off the yellow LED
  digitalWrite(led_green, HIGH); // Turning on the green LED
  delay(2000);                   // Pause the program for 2 seconds

  lcd.setCursor(0, 1);            // Setting the cursor position to the first column of the second row
  lcd.print("Yellow    ");        // Displaying the text "Yellow" on the LCD
  digitalWrite(led_red, LOW);     // Turning off the red LED
  digitalWrite(led_yellow, HIGH); // Turning on the yellow LED
  digitalWrite(led_green, LOW);   // Turning off the green LED
  delay(2000);                    // Pause the program for 2 seconds

  lcd.setCursor(0, 1);           // Setting the cursor position to the first column of the second row
  lcd.print("Red       ");       // Displaying the text "Red" on the LCD
  digitalWrite(led_red, HIGH);   // Turning on the red LED
  digitalWrite(led_yellow, LOW); // Turning off the yellow LED
  digitalWrite(led_green, LOW);  // Turning off the green LED
  delay(2000);                   // Pause the program for 2 seconds
}