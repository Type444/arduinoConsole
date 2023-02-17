bool checkJump( bool jumpState) {
  if ((!digitalRead(button_pin)) && (!jumpState)) {
    Serial.println("Прыжок");
    lcd.setCursor(3, 3);
    lcd.print(" ");
    lcd.setCursor(3, 2);
    lcd.printByte(0);
    delay(10);
    lcd.setCursor(3, 2);
    lcd.print(" ");
    lcd.setCursor(3, 1);
    lcd.printByte(0);
    JumpTime = millis();
    return true;
  }
}
