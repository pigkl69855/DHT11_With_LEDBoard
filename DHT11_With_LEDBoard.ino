#include <dht.h>   
  
#define dht_dpin A0 //no ; here. Set equal to channel sensor is on   
  
dht DHT;   

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
int i=1;
void setup(){   

lcd.begin(16, 2);

lcd.setCursor(0, 0); // 設定游標位置在第一行行首
lcd.print("opening");


delay(2000);//Wait rest of 1000ms recommended delay before   
//accessing sensor   
} 
  
void loop(){   
//This is the "heart" of the program.   
DHT.read11(dht_dpin);   
  


lcd.clear();
lcd.setCursor(0, 0);
lcd.print("humidity = ");
lcd.print(DHT.humidity);   
lcd.print("% ");
lcd.setCursor(0, 1);
lcd.print("temp = ");
lcd.print(DHT.temperature);   
lcd.print("C ");
lcd.print(i);
if (i==1){
  i++;
  }
else{
  i--;
}
  


delay(1000);//讀取資料的頻率   
}// end loop()  
