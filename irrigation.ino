#define soil A0
//#define TDS A1
//#define ph A2
#define water_min A3
#define water_max A4

//#define pump_drain 4
#define pump_soil 3
#define pump_ground 5 

void setup()
{
  pinMode(soil, INPUT);
 // pinMode(TDS, INPUT);
  //pinMode(ph, INPUT);
  pinMode(water_max, INPUT);
  pinMode(water_min, INPUT);
 // pinMode(pump_drain, OUTPUT);
  pinMode(pump_ground, OUTPUT);
  pinMode(pump_soil, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  delay(100);
  if(digitalRead(water_min) == LOW && digitalRead(water_max) == LOW)
  {
    digitalWrite(pump_ground, HIGH);
  }
  else
  {
    digitalWrite(pump_ground, LOW);
  }
  float moisture = map(analogRead(soil), 0, 1023, 100, 0);
  Serial.println(moisture);
  if(moisture <= 45)
  {
    digitalWrite(pump_soil, HIGH);
  }
  else
  {
    digitalWrite(pump_soil, LOW);
  }
 /* float pH_val = map(analogRead(ph), 0, 1023, 4, 10); // change
  float TDS_val = map(analogRead(TDS), 0, 1023, 500, 1500); // change
   Serial.print(pH_val);
   Serial.print("/t");
   Serial.println(TDS_val);
  if((pH_val <= 6 || pH_val >= 8 || TDS_val >= 700) && digitalRead(water_min) == HIGH)
  {
    digitalWrite(pump_drain, HIGH);
  }
  else
  {
    digitalWrite(pump_drain, LOW);
  }
  
}*/
}
