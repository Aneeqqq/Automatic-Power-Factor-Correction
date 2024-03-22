const uint8_t voltage_pin = A0; const uint8_t current_pin = A5;const uint8_t relay1=6; const uint8_t relay2=2; const uint8_t relay3=3; const uint8_t relay4=4; const uint8_t relay5=5;

void setup() {
Serial.begin(2000000);
for(int i=2;i<7;i++){
  pinMode(i,OUTPUT);
  delay(200);
  digitalWrite(i,LOW);
  delay(200);
}
}

void loop() {
//Serial.println(analogRead(voltage_pin));
Serial.println(analogRead(current_pin)-500);
}
