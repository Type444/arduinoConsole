void menu() {
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("PLAYSTATION");
  lcd.setCursor(1, 1);
  lcd.print("Saratov");
  lcd.setCursor(1, 2);
  lcd.print("Space Rase");
  lcd.setCursor(1, 3);
  lcd.print("Google Dino");
  delay(500);
  for (;;) {
    x = analogRead(port_y);

    if ((x > 750) || (x < 250)) {

      lcd.setCursor(0, curs);
      lcd.print(" ");
      if (x > 750) {
        curs++;
      }
      if (x < 250) {
        curs--;
      }
      if (curs > 3) {
        curs = 1;
      } else if (curs < 1) {
        curs = 3;
      }
      lcd.setCursor(0, curs);
      lcd.print(">");
      Serial.println("Позиция курсора: " + String(curs));
      delay(500);
    }
    if (!digitalRead(button_pin)) {
      if (curs == 1) {
        Serial.println("Запускаем лабиринт...");
        labyrinth(map1);
        menu_on = false;
        while (menu_on == false) {


          labyrinth_game();
        }
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("PLAYSTATION");
        lcd.setCursor(1, 1);
        lcd.print("Saratov");
        lcd.setCursor(1, 2);
        lcd.print("Spaceship");
        lcd.setCursor(1, 3);
        lcd.print("Google Dino");
      } else if (curs == 2) {
        Serial.println("Запускаем стрелялку...");
        menu_on = false;
        lcd.clear();
        while (menu_on == false) {
        
        spaseship_game();
        }
      } else if (curs == 3) {
        menu_on = false;
        Serial.println("Запускаем динозавр...");
        lcd.clear();
        lcd.setCursor(3, 3);
        lcd.printByte(0);
        while (menu_on == false) {
          Google_Dino();
        }

      }
    }
  }
}
