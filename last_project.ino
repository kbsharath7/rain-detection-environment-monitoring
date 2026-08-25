#define BLYNK_TEMPLATE_ID "TMPL3EDeTDcBK"
#define BLYNK_TEMPLATE_NAME "IoT Rain detection and Environment Detection system"
#define BLYNK_AUTH_TOKEN "Z2dl2yv-ePHFvmo2ecAPxyfjJAGDqxEQ"

#include <WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "realme";
char pass[] = "0987654321";

LiquidCrystal_I2C lcd(0x27, 16, 2);
BlynkTimer timer;

// Pin Definitions
#define LDR      34
#define RAIN     33
#define RELAY1   25
#define RELAY2   14
#define BUZZER   5

void sendSensor()
{
  int ldrValue = analogRead(LDR);
  int rainValue = analogRead(RAIN);

  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print("   Rain: ");
  Serial.println(rainValue);

 
  Blynk.virtualWrite(V0, ldrValue);
  Blynk.virtualWrite(V1, rainValue);

  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
  digitalWrite(BUZZER, LOW);

  String lcdMessage = "System Normal";


  if (ldrValue > 1500)
  {
    digitalWrite(RELAY1, HIGH);
    Blynk.virtualWrite(V2, 1);
    lcdMessage = "Dark Detected";
  }
  else
  {
    Blynk.virtualWrite(V2, 0);
  }

  // Rain Condition
  if (rainValue < 2000)
  {
    digitalWrite(RELAY2, HIGH);
    Blynk.virtualWrite(V3, 1);

    if (lcdMessage == "Dark Detected")
      lcdMessage = "Dark & Rain";
    else
      lcdMessage = "Rain Detected";
  }
  else
  {
    Blynk.virtualWrite(V3, 0);
  }

  // Climate Rainy
  if ((ldrValue > 1500) && (rainValue < 2000))
  {
    digitalWrite(BUZZER, HIGH);
    Blynk.virtualWrite(V4, 1);
    lcdMessage = "Climate Rainy";
  }
  else
  {
    Blynk.virtualWrite(V4, 0);
  }

  // LCD Display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(lcdMessage);

  lcd.setCursor(0, 1);
  lcd.print("L:");
  lcd.print(ldrValue);
  lcd.print(" R:");
  lcd.print(rainValue);

  Blynk.virtualWrite(V5, lcdMessage);
}

void setup()
{
  Serial.begin(115200);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
  digitalWrite(BUZZER, LOW);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Connecting...");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WiFi Connected");
  delay(1000);

  lcd.clear();
  lcd.print("System Ready");

  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}