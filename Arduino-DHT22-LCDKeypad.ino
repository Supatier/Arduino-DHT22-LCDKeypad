
/**
Originaly by:
-------------------------------------------------
* Tiago Santos
* dark_storm@groundzero.com.pt
* http://space.groundzero.com.pt
* Free to share
-------------------------------------------------
Copyright 2017 Supatier

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**/

#include "DHT.h"
#include "LiquidCrystal.h"
#include <LCDKeypad.h>

#define DHTPIN 2     // what digital pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

byte term[8] = //icon for termometer
{
    B00100,
    B01010,
    B01010,
    B01110,
    B01110,
    B11111,
    B11111,
    B01110
};

byte pic[8] = //icon for water droplet
{
    B00100,
    B00100,
    B01010,
    B01010,
    B10001,
    B10001,
    B10001,
    B01110,
};
DHT dht(DHTPIN, DHTTYPE);
LCDKeypad lcd;

void setup() {
  dht.begin();
  lcd.begin(16, 2);
  lcd.createChar(1,term);
  lcd.createChar(2,pic);
}

void loop() {
  get_sens();
}
void get_sens()
  {
  delay(2000);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  lcd.setCursor(0, 1);
  lcd.write(1);
  lcd.print(" ");
  lcd.print(t,1);
  lcd.print((char)223); //degree sign
  lcd.print("C   ");
  lcd.write(2);
  lcd.print(" ");
  lcd.print(h);
  lcd.print("%");
}
