#include <LiquidCrystal.h> // Import the library for LCD display

// Declaration of integer constants - assignment of Arduino pins to corresponding LCD pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int distancePin = 6;							// Declaration of the pin to which the distance sensor signal is connected
const int greenLED = 8, yellowLED = 9, redLED = 10; // Declaration of variables storing the pins to which the LEDs are connected
const int daleko = 250, blisko = 100;				// Declaration of obstacle distances from the distance sensor (in centimeters)

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Declaration of a variable of type LiquidCrystal

// Declaration of setup function - runs once at the beginning
void setup()
{
	pinMode(greenLED, OUTPUT); // Configure the pins to which the LEDs are connected as output pins
	pinMode(yellowLED, OUTPUT);
	pinMode(redLED, OUTPUT);
	lcd.begin(16, 2);	// Initialize the LCD screen (size: 16 x 2)
	Serial.begin(9600); // Open the serial console
}

// Declaration of loop function - runs continuously
void loop()
{
	long duration, cm; // Declaration of variables needed to read the object distance from the sensor

	// Set the distance sensor pin as output and send LOW>HIGH>LOW signal to read the distance
	pinMode(distancePin, OUTPUT);
	digitalWrite(distancePin, LOW);
	delayMicroseconds(2);
	digitalWrite(distancePin, HIGH);
	delayMicroseconds(5);
	digitalWrite(distancePin, LOW);

	// Set the distance sensor pin as input and retrieve distance data
	pinMode(distancePin, INPUT);
	duration = pulseIn(distancePin, HIGH);

	// Convert microseconds to centimeters using the defined function - the sensor provides distance in microseconds
	cm = microsecondsToCentimeters(duration);

	// The following conditional statements check if the object is far, close, or very close based on the predefined distance values.
	// If any of the conditions is met, the code inside the respective blocks is executed.
	// In each block, the distance along with a message is printed to the serial console,
	// displayed on the LCD, and one of the LEDs is lit based on the distance.
	Serial.print("Odleglosc: ");
	Serial.print(cm);
	Serial.print("cm");

	if (cm > daleko)
	{
		Serial.print(" - Daleko");
		lcd.setCursor(0, 1);
		lcd.print("Daleko       ");
		digitalWrite(greenLED, HIGH);
		digitalWrite(yellowLED, LOW);
		digitalWrite(redLED, LOW);
	}
	else if (cm > blisko)
	{
		Serial.print(" - Blisko");
		lcd.setCursor(0, 1);
		lcd.print("Blisko       ");
		digitalWrite(greenLED, LOW);
		digitalWrite(yellowLED, HIGH);
		digitalWrite(redLED, LOW);
	}
	else
	{
		Serial.print(" - Bardzo blisko");
		lcd.setCursor(0, 1);
		lcd.print("Bardzo blisko");
		digitalWrite(greenLED, LOW);
		digitalWrite(yellowLED, LOW);
		digitalWrite(redLED, HIGH);
	}

	Serial.println();
	lcd.setCursor(0, 0);
	lcd.print("Odlegosc = ");
	lcd.print(cm);
	lcd.print("cm  ");

	delay(1000); // Pause for 1 second - the distance reading and the entire code are executed every 1 second
}

// Declaration of function that converts microseconds to centimeters
// @param microseconds The duration in microseconds
// @return The distance in centimeters
long microsecondsToCentimeters(long microseconds)
{
	return microseconds / 29 / 2;
}