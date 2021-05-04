#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);
const int trigPin = 3;
const int echoPin = 2;
long duration;
float distanceCm, distancemeter;
void setup() {
  lcd.init();
  lcd.begin(16, 2); // Initializes the interface to the LCD display
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.0341 / 2;
  distancemeter = 0.9834 *(30.5-( duration * 0.0341 / 2));
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  Serial.println(distanceCm);
  lcd.print(distanceCm);
  lcd.print("cm");
  lcd.setCursor(0, 1);
  lcd.print("    ");
  lcd.print(distancemeter);
  lcd.print(" m3");
  delay(1000);
}
