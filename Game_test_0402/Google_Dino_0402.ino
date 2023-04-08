void Google_Dino() {
  
  
  static bool jumpState = false;
  static int i = 19;
  if (millis() % 500 < 10 ) {
    lcd.setCursor(10,1);
    lcd.print(schet);
    if (i < 19) {
      lcd.setCursor(i + 1, 3);
      lcd.print(" ");
    }
    lcd.setCursor(i, 3);
    lcd.printByte(1);
    if (i == 0) {
      lcd.setCursor(i, 3);
      lcd.print(" ");
      i = 19;
    }
    i--;

  }
  if ((!jumpState) && ((millis() - JumpTime) > 2000)) {
    jumpState = checkJump(jumpState);
   
  }
  if ((i == 3) && (!jumpState)) {
    lcd.clear();
    lcd.setCursor(5, 2);
    lcd.print("GAME OVER!");
    delay(2000);
    menu_on = true;
    schet=0;
  }

  if (jumpState) {
    if ((millis() - JumpTime) > 1000) {
      lcd.setCursor(3, 1);
      lcd.print(" ");
      lcd.setCursor(3, 2);
      lcd.print(" ");
      lcd.setCursor(3, 3);
      lcd.printByte(0);
      jumpState = false;

      schet++;
      Serial.print(schet);
      lcd.setCursor(5,1);
      lcd.print("scor:");
    }
  }
}
