void spaseship_game() {
  static int i = 19;
  static int shoot_X = 19;
  static int shoot_Y = 0;
  static int player_y = 2;
  static int player_x = 1;
  int bombo_on = 1;
  static int straka = 0;

  const int input_delay = 300;
  static unsigned long last_move = 0;
  static unsigned long last_bullet_move = 0;
  static unsigned long last_ast_move = 0;

  int Joystick_Y = analogRead(1);
  int Joystick_X = analogRead(0);
  if ((millis() - last_move) > input_delay) {
    if ((Joystick_Y > 700) && (player_y < 3)) {
      lcd.setCursor(player_x, player_y);
      lcd.print(' ');
      player_y++;
      lcd.setCursor(player_x, player_y);
      lcd.printByte(2);
      last_move = millis();

    }
    if ((Joystick_Y < 300) && (player_y > 0)) {
      lcd.setCursor(player_x, player_y);
      lcd.print(' ');
      player_y--;
      lcd.setCursor(player_x, player_y);
      lcd.printByte(2);
      last_move = millis();

    }
    if ((Joystick_X > 700) && (player_x < 3)) {
      lcd.setCursor(player_x, player_y);
      lcd.print(' ');
      player_x++;
      lcd.setCursor(player_x, player_y);
      lcd.printByte(2);
      last_move = millis();

    }
    if ((Joystick_X < 300) && (player_x > 0)) {
      lcd.setCursor(player_x, player_y);
      lcd.print(' ');
      player_x--;
      lcd.setCursor(player_x, player_y);
      lcd.printByte(2);
      last_move = millis();

    }
  }


  if (!digitalRead(8)) {
    lcd.setCursor (shoot_X, shoot_Y);
    lcd.print(' ');
    shoot_Y = player_y;
    shoot_X = player_x + 1;
  }

  if ((millis() - last_bullet_move) > 180) {
    if ((shoot_X == i) && (shoot_Y == straka)) {
      bombo_on = false;
      i = 19 ;
      straka = random(0, 3);

    }
    last_bullet_move = millis();
    if (shoot_X < 19 ) {
      lcd.setCursor(shoot_X, shoot_Y );
      lcd.print(' ');
      shoot_X++;
      lcd.setCursor(shoot_X, shoot_Y );
      lcd.print('-');

    }

  }

  if ((shoot_X == i) && (shoot_Y == straka)) {
    bombo_on = false;
    i = 19 ;
    straka = random(0, 3);

  }

  

  Serial.println("Millis: " + String(millis()));
  Serial.println("last_ast_move: " + String(last_ast_move));
  if ((millis() - last_ast_move) > 300 ) {
    if ((shoot_X == i) && (shoot_Y == straka)) {
      bombo_on = false;
      i = 19 ;
      straka = random(0, 3);

    }
    last_ast_move = millis();
    Serial.println("Астероид сдвинут!");
    Serial.println("[A]Millis: " + String(millis()));
    Serial.println("[A]last_ast_move: " + String(last_ast_move));
    if (i < 19) {
      lcd.setCursor(i + 1, straka);
      lcd.print(" ");
    }

    lcd.setCursor(i, straka);
    lcd.printByte(3);
    if (i == 0) {
      lcd.setCursor(i, straka);
      lcd.print(" ");
      i = 19;
      straka = random(0, 3);
    }
    i--;

  }

  if (shoot_X == 19);
  lcd.setCursor (19, shoot_Y);
  lcd.print (' ');
}
