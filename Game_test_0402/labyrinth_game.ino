void labyrinth_game() {
  static int player_y;
  static int player_x;
  x = analogRead(port_x);
  y = analogRead(port_y);
  if ((((x > 750) || (x < 250)) || ((y > 750) || (y < 250)))) {
    lcd.setCursor(player_x, player_y);
    lcd.print(" ");
    if ((x > 750) && (player_x < 19)) {
      player_x++;
    }
    if ((x < 250) && (player_x > 0)) {
      player_x--;

    }
    if ((y > 750) && (player_y < 3)) {
      player_y++;
    }
    if ((y < 250) && (player_y > 0)) {
      player_y--;

    }
    if (checkWall(player_x, player_y, level)) {
      player_x = 0;
      player_y = 0;

    }
    lcd.setCursor(player_x, player_y);
    lcd.print("*");
    if ((player_x == 17) && (player_y == 0)) { //финеш уровня 1
      if (level == 1) {
        labyrinth(map2);
        level++;
        player_x = 0;
        player_y = 0;
      }
    }
  }

  if ((player_x == 17) && (player_y == 0)) { //финеш уровня 2
    if (level == 2) {
      labyrinth(map3);
      level++;
      player_x = 0;
      player_y = 0;
      
    }
  }

  if ((player_x == 18) && (player_y == 0)) { //финеш уровня 3
    if (level == 3) {
      lcd.clear();
      lcd.setCursor(5, 2);
      lcd.print("YOU WIN!!!");
      delay(2000);
      menu_on = true;
      level = 1;
      player_x = 0;
      player_y = 0;
    }
  }
  delay(200); 
}
