void labyrinth(bool cur_map[4][20]) {
  lcd.clear();
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < 20; i++) {
      if (cur_map[j][i] == true) {
        lcd.setCursor(i, j);
        lcd.write(255);
      }
    }
  }
}
