const uint8_t voltage_pin = A0; const uint8_t current_pin = A5; const uint8_t relay1=6; const uint8_t relay2=2; const uint8_t relay3=3; const uint8_t relay4=4; const uint8_t relay5=5;

double current=0; double voltage=0; double rms_current=0; double rms_voltage=0; double power=0;

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
 // rms_current=rms_Current();
  //Serial.println(rms_current);
  rms_voltage=rms_Voltage();
   Serial.println(rms_voltage);
   //power=rms_current*rms_voltage;
   //Serial.println(power);
   
}
double rms_Current(){
 double current=0;
 for(int i=0;i<500;i++){
  current+=(((analogRead(current_pin)-493)*1.243)/80)-.2;
  delayMicroseconds(250);
 }
 return current/500;
 }
 
 double rms_Voltage(){
 double voltage=0;
  for(int i=0;i<1800;i++){
  voltage
  +=((analogRead(voltage_pin)-400));
  delayMicroseconds(250);
 }
 return voltage/1800;}
