const int button = 2;
const int led = 13;
int status = false;

void setup(){
pinMode(led, OUTPUT);
pinMode(button, INPUT_PULLUP);
Serial.begin(9600);
}

void loop(){

if (digitalRead(button) == false) {
status = !status;
digitalWrite(led, status);
} while(digitalRead(button) == false);
delay(100);
if(status == true) {
  Serial.println("OFF");
  }
  else {
    Serial.println("ON");
    }
}
