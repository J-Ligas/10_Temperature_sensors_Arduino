#include <OneWire.h>
#include <DallasTemperature.h>
//#include <LiquidCrystal.h>
//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define DATO 13 //This is for Digital Pin
float Tp; //Average temperature
int Tiempo=0; //Set time = 0
OneWire ourWire (DATO);
DallasTemperature sensors (&ourWire);
//Put TMAX(SENSORX) TMIN(SENSORX) Tp Temperature difference between MAX Y MIN(Between SENSORS X)
DeviceAddress sensor1 = { 0x28, 0x28, 0x63, 0xE2, 0x12, 0x19, 0x01, 0x1D };
DeviceAddress sensor2 = { 0x28, 0x26, 0xBC, 0x79, 0x97, 0x04, 0x03, 0xC4 };
DeviceAddress sensor3 = { 0x28, 0x0E, 0x02, 0x79, 0x97, 0x05, 0x03, 0xFA };
DeviceAddress sensor4 = { 0x28, 0x2E, 0xEE, 0xEB, 0x12, 0x19, 0x01, 0x1B };
DeviceAddress sensor5 = { 0x28, 0x6E, 0xBC, 0x79, 0x97, 0x04, 0x03, 0x10 };
DeviceAddress sensor6 = { 0x28, 0xF1, 0xFF, 0x79, 0x97, 0x14, 0x03, 0xCE };
DeviceAddress sensor7 = { 0x28, 0x89, 0x54, 0x99, 0x12, 0x19, 0x01, 0x9F };
DeviceAddress sensor8 = { 0x28, 0x35, 0x6F, 0xBC, 0x12, 0x19, 0x01, 0xE0 };
DeviceAddress sensor9 = { 0x28, 0xE3, 0xF8, 0x79, 0x97, 0x11, 0x03, 0x55 };
DeviceAddress sensor10 = { 0x28, 0xEF, 0xC5, 0x79, 0x97, 0x04, 0x03, 0x53 };
void setup (){
  Serial.begin (9600); 
  //lcd.begin(16, 2);
  sensors.begin ();
  sensors.setResolution (sensor1, 13);
  sensors.setResolution (sensor2, 13);
  sensors.setResolution (sensor3, 13);
  sensors.setResolution (sensor4, 13);
  sensors.setResolution (sensor5, 13);
  sensors.setResolution (sensor6, 13);
  sensors.setResolution (sensor7, 13);
  sensors.setResolution (sensor8, 13);
  sensors.setResolution (sensor9, 13);
  sensors.setResolution (sensor10, 13);
}

void printTemperature(DeviceAddress deviceAddress){
  float TempC = sensors.getTempC(deviceAddress);
  if (TempC == -127){
  Serial.print (" Existe un error en el hardware "); //Error with connection or shortcircuit WARNING!!
  }
  else {
    Serial.print(TempC);
  }
  }
void loop (void){
  Serial.print(Tiempo);
  Serial.print(",");
  sensors.requestTemperatures();
  printTemperature(sensor1);
  Serial.print(",");
  printTemperature(sensor2);
  Serial.print(",");
  printTemperature(sensor3);
  Serial.print(",");
  printTemperature(sensor4);
  Serial.print(",");
  printTemperature(sensor5);
  Serial.print(",");
  printTemperature(sensor6);
  Serial.print(",");
  printTemperature(sensor7);
  Serial.print(",");
  printTemperature(sensor8);
  Serial.print(",");
  printTemperature(sensor9);
  Serial.print(",");
  printTemperature(sensor10);
  Serial.print("\n");
  delay(30000);
  Tiempo=Tiempo+30;
}
//YOU CAN USE ALL THE PRINTS IF YOU WANT I JUST USE THE ABOVE... REGARDS!!
  /*Tp =(sensors.getTempC(sensor1)+sensors.getTempC(sensor2)+sensors.getTempC(sensor3)+sensors.getTempC(sensor4)+sensors.getTempC(sensor5)+sensors.getTempC(sensor6)+sensors.getTempC(sensor7)+sensors.getTempC(sensor8)+sensors.getTempC(sensor9)+sensors.getTempC(sensor10))/10;
  /*Serial.print("\t");
  Serial.print("\t");
  Serial.print("\t");
  Serial.print("\t");
  Serial.println(Tp,2);
  Serial.println("");*/
  /*float Tmax0 = max(sensors.getTempC(sensor1),sensors.getTempC(sensor2));
  float Tmax1 = max(Tmax0,sensors.getTempC(sensor3));
  float Tmax2 = max(Tmax1,sensors.getTempC(sensor4));
  float Tmax3 = max(Tmax2,sensors.getTempC(sensor5));
  float Tmax4 = max(Tmax3,sensors.getTempC(sensor6));
  float Tmax5 = max(Tmax4,sensors.getTempC(sensor7));
  float Tmax6 = max(Tmax5,sensors.getTempC(sensor8));
  float Tmax7 = max(Tmax6,sensors.getTempC(sensor9));
  float Tmax8 = max(Tmax7,sensors.getTempC(sensor10)); 
  float Tmin0 = min(sensors.getTempC(sensor1),sensors.getTempC(sensor2));
  float Tmin1 = min(Tmax0,sensors.getTempC(sensor3));
  float Tmin2 = min(Tmax1,sensors.getTempC(sensor4));
  float Tmin3 = min(Tmax2,sensors.getTempC(sensor5));
  float Tmin4 = min(Tmax3,sensors.getTempC(sensor6));
  float Tmin5 = min(Tmax4,sensors.getTempC(sensor7));
  float Tmin6 = min(Tmax5,sensors.getTempC(sensor8));
  float Tmin7 = min(Tmax6,sensors.getTempC(sensor9));
  float Tmin8 = min(Tmax7,sensors.getTempC(sensor10));
  float DeltaT_MAX = Tmax8-Tmin8;
  lcd.clear();
  lcd.print("P:");
  lcd.print(Tp);
  lcd.print(" MX:");
  lcd.print(Tmax8);
  lcd.setCursor(0,1);
  lcd.print("MN:");
  lcd.print(Tmin8); 
  lcd.print(" D:");
  lcd.print(DeltaT_MAX);
  delay (3000);
  } 
      /*if (sensors.getTempC(sensor1) == 85 && sensors.getTempC(sensor2) == 85 && sensors.getTempC(sensor3) == 85 && sensors.getTempC(sensor4) == 85 && sensors.getTempC(sensor5) == 85 && sensors.getTempC(sensor6) == 85 && sensors.getTempC(sensor7) == 85 && sensors.getTempC(sensor8) == 85 && sensors.getTempC(sensor9) == 85 && sensors.getTempC(sensor10) == 85) {
    delay(5000);
    }
    else{
  if (sensors.getTempC(sensor1)<=15){
digitalWrite(6, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
digitalWrite(7, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
  }
  if (sensors.getTempC(sensor2)<=15){
digitalWrite(6, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
digitalWrite(7, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
  }
  if (sensors.getTempC(sensor3)<=15){
digitalWrite(6, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
digitalWrite(7, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
  }
  if (sensors.getTempC(sensor4)<=15){
digitalWrite(6, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
digitalWrite(7, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
  }
  if (sensors.getTempC(sensor1)>=35){
digitalWrite(6, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
digitalWrite(7, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
  }
  if (sensors.getTempC(sensor2)>=35){
digitalWrite(6, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
digitalWrite(7, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
  }
  if (sensors.getTempC(sensor3)>=35){
digitalWrite(6, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
digitalWrite(7, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
  }
  if (sensors.getTempC(sensor4)>=35){
digitalWrite(6, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
digitalWrite(7, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
  }
  Tp =(sensors.getTempC(sensor1)+sensors.getTempC(sensor2)+sensors.getTempC(sensor3)+sensors.getTempC(sensor4))/4;
  Serial.print("\t");
  Serial.print("\t");
  Serial.print("\t");
  Serial.print("\t");
  Serial.println(Tp,2);
  Serial.println("");
  if (Tp >= 35){
digitalWrite(6, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
digitalWrite(7, LOW); 
Serial.println("Alerta temperatura excesiva checar SSR"); 
}
  }*/
  


