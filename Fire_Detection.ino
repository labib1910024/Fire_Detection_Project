#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Define sensor and buzzer pins
#define FIRE_SENSOR_PIN 2 // Connect fire sensor D0 output to digital pin 2
#define SMOKE_SENSOR_PIN A0 // Connect smoke sensor analog output to analog pin A0
#define BUZZER_PIN 3 // Connect buzzer to digital pin 3

// Create LCD object
LiquidCrystal_I2C lcd(0x27,16,2); // Adjust address if necessary

void setup() {
  // Initialize LCD
  lcd.begin(); // Initialize the LCD
  lcd.backlight();

  // Set sensor pins as input
  pinMode(FIRE_SENSOR_PIN, INPUT);
  pinMode(SMOKE_SENSOR_PIN, INPUT);
  // Set buzzer pin as output
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read digital value from fire sensor
  int fireSensorValue = digitalRead(FIRE_SENSOR_PIN);
  // Read analog value from smoke sensor
  int smokeSensorValue = analogRead(SMOKE_SENSOR_PIN);

  // Print smoke sensor value to serial monitor
  Serial.print("Smoke Sensor Value: ");
  Serial.println(smokeSensorValue);

  if (fireSensorValue == LOW) {
    // Fire detected!
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("FIRE DETECTED!");
    lcd.setCursor(0, 1);
    lcd.print("ALERT!");
    digitalWrite(BUZZER_PIN, HIGH);

    // Additional check for smoke sensor
    if (smokeSensorValue > 300) { // Adjust threshold as needed
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SMOKE DETECTED!");
      lcd.setCursor(0, 1);
      lcd.print("ALERT!");
    }
  } else {
    // No fire detected
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No Fire");

    // Check for smoke presence even if no fire is detected
    if (smokeSensorValue > 230) { // Adjust threshold as needed
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SMOKE DETECTED!");
      lcd.setCursor(0, 1);
      lcd.print("ALERT!");
      digitalWrite(BUZZER_PIN, HIGH);
    } else {
      digitalWrite(BUZZER_PIN, LOW);
    }
  }

  delay(500); // Delay for 500 milliseconds to reduce LCD updates
}
