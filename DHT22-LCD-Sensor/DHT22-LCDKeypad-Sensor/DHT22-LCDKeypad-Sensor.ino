
/**
* Tiago Santos
* dark_storm@groundzero.com.pt
* http://space.groundzero.com.pt
* Free to share
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
  // Wait a few seconds between measurements.
  get_sens();
}
void get_sens()
  {
  delay(2000);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  int t = dht.readTemperature();

  lcd.setCursor(0, 1);
  lcd.write(1);
  lcd.print(" ");
  lcd.print(t);
  lcd.print((char)223); //degree sign
  lcd.print("C     ");
  lcd.write(2);
  lcd.print(" ");
  lcd.print(h);
  lcd.print("%");
}
