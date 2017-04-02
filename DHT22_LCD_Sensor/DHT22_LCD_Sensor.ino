/**
* Tiago Santos
* dark_storm@groundzero.com.pt
* http://space.groundzero.com.pt
* Free to share
**/

#include "DHT.h"
#include "LiquidCrystal.h"

#define DHTPIN 6     // what digital pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

#define blue 8
#define green 9
#define red 10

DHT dht(DHTPIN, DHTTYPE);
LCDKeypad lcd;

void setup() {
  Serial.begin(9600);
  pinMode(blue,OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red,OUTPUT);
  
  dht.begin();
  lcd.begin(16, 2);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) ){
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Humid.: ");
  lcd.print(h);
  lcd.print(" %");
  lcd.setCursor(0, 1);
  lcd.print("Temp. : ");
  lcd.print(t);
  lcd.print(" C");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  if( t < 20 )
  {
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
  }
  else
  {
    if(t > 30)
    {
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
      digitalWrite(red, HIGH);      
    }
    else
    {
      digitalWrite(blue, LOW);
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);    
    }
  }
}
