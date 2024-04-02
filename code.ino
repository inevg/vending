#include <Keypad.h>
#include <Wire.h>
// #include <LiquidCrystal_I2C.h>

int motor1pin1 = 36;
int motor1pin2 = 38;

int motor2pin1 = 40;
int motor2pin2 = 42;

int motor3pin1 = 44;
int motor3pin2 = 46;

int motor4pin1 = 48;
int motor4pin2 = 50;

const byte ROWS = 4; 
const byte COLS = 3; 

String pad;
String p1 = "1";
String p2 = "2";
String p3 = "3";
String p4 = "4";

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {34, 32, 30, 28}; 
byte colPins[COLS] = {26, 24, 22}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


char keypressed;

  //char customKey = customKeypad.getKey();

void setup() {
  //motor setup
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT); 
  /*
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Keypad");
  lcd.setCursor(0, 1);
  lcd.print("Test");
  delay(1000);
  lcd.clear();
  */
}
void loop() {
  analogWrite(7, 100);
  analogWrite(8, 100);
  analogWrite(9, 100);
  analogWrite(10, 100);
  // put your main code here, to run repeatedly:
  readKeypad();
  if (keypressed == '#') {
    if (pad == p1) {
      // lcd.setCursor(0, 1);
      // lcd.print("Product 1 selected");
      //turning on motor 1
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
      delay(200);
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);
    }else if(pad==p2){
      // lcd.setCursor(0, 1);
      // lcd.print("Product 2 selected");
      //turning on motor 2
      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
      delay(200);
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW);
    }else if(pad==p3){
      // lcd.setCursor(0, 1);
      // lcd.print("Product 3 selected");
      //turning on motor 3
      digitalWrite(motor3pin1, HIGH);
      digitalWrite(motor3pin2, LOW);
      delay(200);
      digitalWrite(motor3pin1, LOW);
      digitalWrite(motor3pin2, LOW);
    }else if(pad==p4){
      // lcd.setCursor(0, 1);
      // lcd.print("Product 4 selected");
      //turning on motor 4
      digitalWrite(motor4pin1, HIGH);
      digitalWrite(motor4pin2, LOW);
      delay(200);
      digitalWrite(motor4pin1, LOW);
      digitalWrite(motor4pin2, LOW);
    }else {
      //lcd.setCursor(0, 1);
      //lcd.print("Invalid code");
    }
  } if (keypressed == '*') {
    pad = "";
    // lcd.clear();
  }
  // lcd.setCursor(0, 0);
  // lcd.print(pad);
  delay(100);
}
void readKeypad() {
  keypressed = customKeypad.getKey(); //deteksi penekanan keypad
  if (keypressed != '#') {
    String konv = String(keypressed);
    pad += konv;
  }
}