// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

// set pin numbers for menu buttons
const int MenuNext = 8;     // the number of the pushbutton pin
const int MenuSelect = 9;
int MenuStateNext = 0;
int MenuStateSelect = 0;
int ChooseState=1;
int SelectState=0;
bool StartGame=0;

void setup() {
  //output monitor ini
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  //initialize the pushbutton pin as an input
  pinMode(MenuNext, INPUT);
  pinMode(MenuSelect, INPUT);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Player1");
  lcd.setCursor(0, 1);
  lcd.print("Ready !");
  lcd.setCursor(9, 0);
  lcd.print("Player2");
  lcd.setCursor(9, 1);
  lcd.print("Ready !");
  //BUTTONS: read the state of the pushbutton value:
  MenuStateNext = digitalRead(MenuNext);
  MenuStateSelect = digitalRead(MenuSelect);

  }


