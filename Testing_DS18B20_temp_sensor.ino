//Welcome to Handsonpractical
    #include <OneWire.h>
    #include <DallasTemperature.h>
    #include<LiquidCrystal_I2C.h>
    #define ONE_WIRE_BUS 6
    
    OneWire oneWire(ONE_WIRE_BUS);
    DallasTemperature sensors(&oneWire);
    LiquidCrystal_I2C lcd(0x27,20, 4);
    float temp=0;
    float maxValue=0;
    
    void setup()
    {
      lcd.backlight();
      lcd.init();
      lcd.begin(20,4);
      lcd.setCursor(6,0);
      lcd.print("Welcome");
      lcd.setCursor(9,1);
      lcd.print("To");
      lcd.setCursor(2,2);
      lcd.print("Hands on Practical");
      delay(2000);
      sensors.begin();
      Serial.begin(9600);
      
    }
    void loop()
    {
      sensors.requestTemperatures();
      temp=sensors.getTempCByIndex(0);
      if (temp > maxValue)
      {
        maxValue= temp;
      }
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Temperature: ");
      lcd.print(temp);
      lcd.print((char)223);// used to print degree character on LCD
      lcd.print("C");
      
      lcd.setCursor(0,3);
      lcd.print("Max Temp: ");
      lcd.setCursor(13,3);
      lcd.print(maxValue);
      lcd.print((char)223);
      lcd.print("C");
    delay(1000);
    }
