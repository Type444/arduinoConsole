// Display a loading animation on the LCD
void loading() {
  // Loop through each column of the LCD and display a block character
  for (int i = 0; i < 20; i++) {
    lcd.setCursor(i, 2);
    lcd.write(0xFF); // 0xFF is equivalent to 0b11111111
    // Display the current progress as a percentage
    lcd.setCursor(6, 1);
    lcd.print("Loading " + String(i * 5) + "%");
    delay(100);
  }
}
