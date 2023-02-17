// Display a labyrinth on the LCD
void labyrinth(bool cur_map[4][20]) {
  // Clear the LCD before drawing the labyrinth
  lcd.clear();
  // Loop through each cell in the map and display a block character if it is a wall
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < 20; i++) {
      if (cur_map[j][i]) {
        lcd.setCursor(i, j);
        lcd.write(0xFF); // 0xFF is equivalent to 0b11111111
      }
    }
  }
}
