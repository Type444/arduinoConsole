void Google_Dino() {
  // Initialize jump state and obstacle position
  static bool jumpState = false;
  static int obstaclePos = 19;

  // Move the obstacle at a regular interval
  if (millis() % 500 < 10 ) {
    // Clear the obstacle's old position
    if (obstaclePos < 19) {
      lcd.setCursor(obstaclePos + 1, 3);
      lcd.print(" ");
    }

    // Set the obstacle's new position and check if it has reached the end of the screen
    lcd.setCursor(obstaclePos, 3);
    lcd.printByte(1);
    if (obstaclePos == 0) {
      lcd.setCursor(obstaclePos, 3);
      lcd.print(" ");
      obstaclePos = 19;
    }
    obstaclePos--;
  }

  // Check if the jump button has been pressed and execute the jump if necessary
  if ((!jumpState) && ((millis() - JumpTime) > 2000)) {
    jumpState = checkJump(jumpState);
  }

  // Check if the player has hit the obstacle and end the game if necessary
  if ((obstaclePos == 3) && (!jumpState)) {
    lcd.clear();
    lcd.setCursor(5, 2);
    lcd.print("GAME OVER!");
    delay(2000);
    menu_on = true;
  }

  // Execute the jump and return to the ground if the jump button has been pressed
  if (jumpState) {
    if ((millis() - JumpTime) > 1000) {
      lcd.setCursor(3, 1);
      lcd.print(" ");
      lcd.setCursor(3, 2);
      lcd.print(" ");
      lcd.setCursor(3, 3);
      lcd.printByte(0);
      jumpState = false;
    }
  }
}
