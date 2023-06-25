#include <LiquidCrystal.h> // Import the library for LCD display

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // Declare integer constants for Arduino pin assignments to LCD
const int buttonPin = 6;                                    // Declare a variable for the button pin number

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Declare a variable of type LiquidCrystal

int led_red = 8; // Declare variables for LED pins
int led_yellow = 9;
int led_green = 10;

int buttonPushCounter = 0; // Declare variables for button events
int buttonState = 0;
int lastButtonState = 0;

/**

@brief Initializes the setup once at the beginning.
*/
void setup()
{
    pinMode(led_red, OUTPUT); // Configure LED pins as outputs
    pinMode(led_yellow, OUTPUT);
    pinMode(led_green, OUTPUT);

    lcd.begin(16, 2);          // Start the LCD display (16 columns and 2 rows)
    lcd.print("Kolor diody:"); // Display text on the LCD (first row)

    pinMode(buttonPin, INPUT); // Initialize the button pin as input
}

/**

@brief Executes continuously in a loop.
*/
void loop()
{
    buttonState = digitalRead(buttonPin); // Read the button signal

    if (buttonState != lastButtonState)
    { // Compare the button state to the previous state
        if (buttonState == HIGH)
        { // If the state changes (high voltage received), increment the counter
            buttonPushCounter++;
        }
    }
    lastButtonState = buttonState; // Save the current state as the last state for the next loop iteration

    if (buttonPushCounter % 3 == 0) // If the button counter is divisible by 3 with a remainder of 0, execute the following block of code
    {
        lcd.setCursor(0, 1);        // Set the cursor position to the first column of the second row
        lcd.print("Zielona ");      // Display the color of the currently lit LED
        digitalWrite(led_red, LOW); // Set 5V (HIGH) to the green LED pin and 0V (LOW) to the other LEDs
        digitalWrite(led_yellow, LOW);
        digitalWrite(led_green, HIGH);
    }
    else if (buttonPushCounter % 3 == 1) // If the button counter is divisible by 3 with a remainder of 1, execute the following block of code
    {
        lcd.setCursor(0, 1);        // Set the cursor position to the first column of the second row
        lcd.print("Zolta ");        // Display the color of the currently lit LED
        digitalWrite(led_red, LOW); // Set 5V (HIGH) to the yellow LED pin and 0V (LOW) to the other LEDs
        digitalWrite(led_yellow, HIGH);
        digitalWrite(led_green, LOW);
    }
    else // If the above conditions are not met (remainder of dividing the button counter by 3 is 2), execute the following block of code
    {
        lcd.setCursor(0, 1);         // Set the cursor position to the first column of the second row
        lcd.print("Czerwona ");      // Display the color of the currently lit LED
        digitalWrite(led_red, HIGH); // Set 5V (HIGH) to the red LED pin and 0V (LOW) to the other LEDs
        digitalWrite(led_yellow, LOW);
        digitalWrite(led_green, LOW);
    }
}