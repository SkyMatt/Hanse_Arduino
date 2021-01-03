// include the library code:
#include <LiquidCrystal.h>
#include <Hanse.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// set pin numbers for menu buttons
const int MenuNext = 14;     // the number of the pushbutton pin
const int MenuSelect = 15;   // the number of the pushbutton pin
int MenuStateNext = 0;
int MenuStateSelect = 0;
int ChooseState=1;
int SelectState=0;
bool StartGame=0;
int omejitev=5;

void setup() {
  //output monitor ini
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  //initialize the pushbutton pin as an input
  pinMode(MenuNext, INPUT);
  pinMode(MenuSelect, INPUT);
  //set cursor position on default position (">")
  lcd.setCursor(0, 1);
  lcd.print(">");
  // //deklaracija pinou za input (16,17,18,19)
  for(int i=16;i<20;i++) {
  pinMode(i, INPUT);
  digitalWrite(i, HIGH);
  }
}


void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Main menu:");
  //LCD: set the cursor to column 0, line 1
  //LCD: line 1 is the second row, since counting begins with 0
  lcd.setCursor(1, 1);
  lcd.print("Play!");
  lcd.setCursor(11, 1);
  lcd.print("Help!");
  
  //BUTTONS: read the state of the pushbutton value:
  MenuStateNext = digitalRead(MenuNext);
  MenuStateSelect = digitalRead(MenuSelect);
  //Menu movement of char ">" and setting the variable to the menu selection ("Play!" or "Help!")
  if(MenuStateNext == HIGH){
      if(ChooseState == 1){
        lcd.setCursor(0, 1);
        lcd.print(" ");
        lcd.setCursor(10, 1);
        lcd.print(">");
        ChooseState=2;
      }
      else {
        lcd.setCursor(10, 1);
        lcd.print(" ");
        lcd.setCursor(0, 1);
        lcd.print(">");
        ChooseState=1;
      }
      Serial.print(MenuStateNext);
      Serial.print(ChooseState);
      delay(250);
  }
  //Menu selection of ("Play!" or "Help!") when pressed button select and further output on lcd
  if(MenuStateSelect == HIGH) {
    lcd.clear();
    if(ChooseState == 1) {
      lcd.print("Game is starting!!!");
      lcd.setCursor(0,1);
      for(int i=0;i<16;i++){
        lcd.print(">");
        delay(250);
      }
      StartGame=1;
      lcd.clear();
      //the game is in this loop, when game ends variable StartGame=0 and game stops
      while(StartGame==1){
        lcd.setCursor(0, 0);
        lcd.print("Player1");
        lcd.setCursor(9, 0);
        lcd.print("Player2");
        delay(1000);
        lcd.setCursor(0, 1);
        lcd.print("Ready !");
        delay(1000);
        lcd.setCursor(9, 1);
        lcd.print("Ready !");
        delay(1000);
        //metod naredi igro!!!
        lcd.clear();
        Igralec metod;
Igralec denis;
lcd.print("Goal: ");
lcd.print(omejitev);
delay(2000);
lcd.clear();
do{
lcd.print("P1:");
lcd.setCursor(10,0);
lcd.print("P2:");
denis.vnos(0);
lcd.setCursor(0,1);
lcd.print(denis.stanjeO());
metod.vnos(2);
lcd.setCursor(10,1);
lcd.print(metod.stanjeO());
metod.rezultat(denis);
delay(1000);
lcd.clear();
}while(metod.stanjeO()<omejitev && denis.stanjeO()<omejitev);
lcd.clear();
lcd.print("Goal reached");
lcd.setCursor(0,1);
if(metod.stanjeO()<denis.stanjeO())
{
  lcd.print("P1 wins! ");
  lcd.setCursor(10,1);
  lcd.print(denis.stanjeO());
  }
else if(metod.stanjeO()>denis.stanjeO()) {
  lcd.print("P2 wins!");
  lcd.setCursor(10,1);
  lcd.print(metod.stanjeO());
}
else lcd.print("Both win!");
delay(5000);
       StartGame=0;
        }
    }
    else {
      //if you chose "Help!"
      lcd.print("Rules:");
      lcd.setCursor(0, 1);
      lcd.print("Turn around!");
      //how long can you be in help!
      delay(5000);
    }
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(">");
    ChooseState=1;
    }
  }

