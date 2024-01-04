#include <LiquidCrystal.h> // LCD
#include <Servo.h> // Servo
#include <SPI.h> // Servo - RFID
#include <RFID.h> // RFID

int tmp = A5;
int pir = 2;
int led = A3;
int buzzer = A4;
int flamepin = 8;
int flame = HIGH;
int pirState = 0;
int i = 0;

RFID rfid(10, 9);
LiquidCrystal lcd(0, 1, 7, 6, 5, 4);

byte kart[5] = {195,151,102,64,114};
Servo myservo;
boolean card;

void setup()
{
  pinMode(tmp, INPUT);
  pinMode(pir, INPUT);
  pinMode(flamepin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  //Serial.begin(9600);
  lcd.begin(16, 2);
  SPI.begin();
  rfid.init();
  myservo.attach(3);
  myservo.write(100);

}

void loop()
{

  //flame
  flame = digitalRead(flamepin);
  if (flame == LOW )
  {
  Serial.println (" FLAME , FLAME , FLAME ");
  digitalWrite (buzzer, HIGH);
  }
   
  else
  {
  Serial.println (" no flame ");
  digitalWrite (buzzer, LOW);
  }

  //PIR
  pirState = digitalRead(pir);
  if (pirState == HIGH) {
    Serial.println("motion");
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  
  //temperature
  float val = analogRead(tmp);
  float milv = (val / 1024.0) * 5000;
  float cel = milv / 10;
  float farh = (cel * 9)/5 + 32;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TEMPERATURE");
  lcd.setCursor(0, 1);
  lcd.print(cel);
  lcd.print(" C  ");
  Serial.println(cel);
  lcd.print(farh);
  lcd.print(" F");
  if(cel > 30){
    digitalWrite(buzzer, HIGH);
  }
  else{
       digitalWrite(buzzer, LOW); }
  delay(500);
  
  // RFID
  if (rfid.isCard())
  {


    if (rfid.readCardSerial())
    {
      Serial.print("Found ID: ");
      Serial.print(rfid.serNum[0]);
      Serial.print(",");
      Serial.print(rfid.serNum[1]);
      Serial.print(",");
      Serial.print(rfid.serNum[2]);
      Serial.print(",");
      Serial.print(rfid.serNum[3]);
      Serial.print(",");
      Serial.println(rfid.serNum[4]);

    }
    for (int i = 1; i < 5; i++)
    {
      if (rfid.serNum[0] == kart[0] && rfid.serNum[1] == kart[1] && rfid.serNum[2] == kart[2] && rfid.serNum[3] == kart[3] && rfid.serNum[4] == kart[4])
      {
        card = true;
      }
      else {
        card = false;
      }
    }
    if (card == true)
    {
      Serial.println("Correct Card");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Door is opened");
      myservo.write(20);
      delay(5000);
      myservo.write(100);
    }
    else
    {
      Serial.println("Wrong Card");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Warning");
      lcd.setCursor(0, 1);
      lcd.print("Unauthorized person");
      for(i; i <10; i++){
        digitalWrite(buzzer, HIGH);
        delay(250);
        digitalWrite(buzzer, LOW);
        delay(250);
        }
        delay(3000);
    }
  }
}
