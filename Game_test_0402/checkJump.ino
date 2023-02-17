const int jump_button_pin = 8;
const int jump_start_x = 3;
const int jump_start_y = 2;
const int jump_mid_x = 3;
const int jump_mid_y = 1;
const int jump_end_x = 3;
const int jump_end_y = 0;

bool checkJump(bool isJumping) {
  if ((!digitalRead(jump_button_pin)) && (!isJumping)) {
    lcd.setCursor(jump_start_x, jump_start_y);
    lcd.print(" ");
    lcd.setCursor(jump_mid_x, jump_mid_y);
    lcd.printByte(0);
    delay(10);
    lcd.setCursor(jump_mid_x, jump_mid_y);
    lcd.print(" ");
    lcd.setCursor(jump_end_x, jump_end_y);
    lcd.printByte(0);
    JumpTime = millis();
    return true;
  }
  return false;
}
