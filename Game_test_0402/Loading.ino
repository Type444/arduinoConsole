void loading(){
   for (int i = 0; i < 20; i++) {
    lcd.setCursor(i, 2);
    lcd.write(0b11111111);
    lcd.setCursor(6, 1);
    lcd.print("Loading " + String(i * 5) + "%");
    delay(100);
  }
}
