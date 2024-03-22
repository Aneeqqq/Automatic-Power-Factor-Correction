const uint8_t voltage_pin = A0; const uint8_t current_pin = A5; const uint8_t relay1 = 6; const uint8_t relay2 = 2; const uint8_t relay3 = 3; const uint8_t relay4 = 4; const uint8_t relay5 = 5;

double current = 0; double voltage = 0; double rms_current = 0; double rms_voltage = 0; double cmp_power_old = 0; double cmp_power_cap = 0; double reactive_power = 0;
uint8_t loopman = 0; uint8_t capacitors = 0;
bool load = false;
void setup() {
  Serial.begin(2000000);
  for (int i = 2; i < 7; i++) {
    pinMode(i, OUTPUT);
    delay(200);
    digitalWrite(i, LOW);
    delay(200);
  }
  pinMode(voltage_pin, INPUT);
  pinMode(current_pin, INPUT);
 }

 void loop() {
  rms_current = rms_Current();
  Serial.println(rms_current);
  rms_voltage = rms_Voltage();
  //Serial.println(rms_voltage);
  cmp_power_old = (rms_current * rms_voltage) + 10;
  //Serial.println(cmp_power_old);
  for (loopman; loopman <= 31 ; ++loopman) {
    if (loopman == 5) {
      digitalWrite(relay1, HIGH);
      rms_current = rms_Current();
      rms_voltage = rms_Voltage();
      cmp_power_cap = (rms_current * rms_voltage) + 10;
      digitalWrite(relay1, LOW);
      loopman = 0;
    }
    else {
      ++loopman;
      break;
    }}
if (cmp_power_old<cmp_power_cap){
  load=true;    
}
   else{
    load=false
   }
   if(load){
    reactive_power=(((cmp_power_old*cmp_power_old)-(cmp_power_new*cmp_power_new))-106.9075)/20.64;
    capacitors=reactive_power/10.33;
    if(capacitors>4){
      capacitors=4
    }
    for(capacitors;capacitor>0;--capacitors){
      digitalWrite(capacitors,HIGH);
    }
   }
}
    double rms_Current() {
      current = 0;
     for (int i = 0; i < 500; i++) {
    current += -((((analogRead(current_pin) - 493) * 1.243) / 80) - .2);//callibrations
       delayMicroseconds(250);
   }
  return current / 500;}

 double rms_Voltage() {
  voltage = 0;
  for (int i = 0; i < 1800; i++) {
    voltage
    += ((analogRead(voltage_pin) - 400));
    delayMicroseconds(250);
  }
  return voltage / 700;
}
