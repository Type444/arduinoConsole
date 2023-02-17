// Play the labyrinth game
void labyrinth_game() {
  // Initialize player coordinates
  static int player_x;
  static int player_y;

  // Read joystick values for x and y axis
  x = analogRead(port_x);
  y = analogRead(port_y);

  // If joystick position is outside of the dead zone, move the player
  if ((((x > 750) || (x < 250)) || ((y > 750) || (y < 250)))) {
    // Clear the player's old position
    lcd.setCursor(player_x, player_y);
    lcd.print(" ");
    
    // Move the player if the new position is within the boundaries of the map
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

    // Check if the player has hit a wall
    if (checkWall(player_x, player_y, level)) {
      // Reset the player's position to the beginning if they hit a wall
      player_x = 0;
      player_y = 0;
    }

    // Set the player's new position and display it on the LCD
    lcd.setCursor(player_x, player_y);
    lcd.print("*");

    // Check if the player has reached the end of the level
    if ((player_x == 17) && (player_y == 0)) {
      if (level == 1) {
        // If the player has reached the end of level 1, switch to level 2
        labyrinth(map2);
        level++;
        player_x = 0;
        player_y = 0;
      }
    }
  }

  // Check if the player has reached the end of level 2
  if ((player_x == 17) && (player_y == 0)) {
    if (level == 2) {
      // If the player has reached the end of level 2, switch to level 3
      labyrinth(map3);
      level++;
      player_x = 0;
      player_y = 0;
    }
  }

  // Check if the player has reached the end of level 3
  if ((player_x == 18) && (player_y == 0)) {
    if (level == 3) {
      // If the player has reached the end of level 3, display a "YOU WIN" message and return to the main menu
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

  // Add a delay to prevent rapid movement of the player character
  delay(200);
}
