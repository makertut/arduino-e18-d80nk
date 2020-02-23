#include <Wire.h>

#include <LiquidCrystal_I2C.h>



#define counter_pin 7

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display



bool item_detected = false;

int  item_counter = 0;



void setup()

{

  Serial.begin(9600);

  pinMode( counter_pin , INPUT);



  lcd.init();                      // initialize the lcd



  // Print a message to the LCD.

  lcd.backlight();

  lcd.setCursor(0,0);

  lcd.print("Hello, world!");

  lcd.setCursor(2,1);

  lcd.print("Ready... :)");

  delay(3000);

}





void loop()

{

  int val = digitalRead( counter_pin );

  if( (item_detected == false) && ( val == 0 )){

        item_detected = true;

        item_counter++;

        updateCounter();

  }

   

  else if( (item_detected == true) && ( val == 1 )){

        item_detected = false;

     

  }

}

void updateCounter(){



     lcd.clear();

     lcd.setCursor(0,0);

     lcd.print("Item count");

     lcd.setCursor(0,1);

     lcd.print(item_counter);

}
