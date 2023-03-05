#include <LiquidCrystal_I2C.h>


//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif
uint8_t spaceship[8] = {
  0b01000,
  0b00100,
  0b00010,
  0b11111,
  0b11111,
  0b00010,
  0b00100,
  0b01000
};
uint8_t asteroid[8] = {
  0b00000,
  0b00000,
  0b01110,
  0b11111,
  0b11111,
  0b01110,
  0b00000,
  0b00000
};
uint8_t enemy[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b01111,
  0b11111,
  0b01111,
  0b00000,
  0b00000
};

uint8_t dino[8] = {
  0b00000,
  0b00111,
  0b10111,
  0b10110,
  0b11111,
  0b01010,
  0b01010,
  0b00000
};
uint8_t cactus[8] = {
  0b00000,
  0b10100,
  0b10100,
  0b11101,
  0b00101,
  0b00111,
  0b00100,
  0b00000
};




int curs = 1;
int x = 0;
int y = 0;
int port_x = 0;
int port_y = 1;
int level = 1;
int button_pin = 8;
bool menu_on = true;
uint32_t JumpTime = 0;


bool checkWall(int  x, int y, int level);
void labyrinth(bool cur_map[4][20]);
void menu();
void loading();
bool map1 [4] [20] =
{
  {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1},
  {0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0},
  {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
};
bool map2 [4][20] =
{
  {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1},
  {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
  {0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0},
  {0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
};
bool map3 [4][20] =
{
  {1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1},
  {0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0},
  {0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};


void setup()
{
  Serial.begin(9600);
  pinMode(button_pin, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, dino);
  lcd.createChar(1, cactus);
  lcd.createChar(2, spaceship);
  lcd.createChar(3, asteroid);
  lcd.createChar(4, enemy);
  loading();
  menu();

}


void loop()
{
  // static int level = 1;



}
