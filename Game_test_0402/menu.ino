// Display the main menu
void menu() {
  // Display the menu options on the LCD screen
  menu_text();

  delay(500);

  for (;;) {
    // Read joystick input
    x = analogRead(port_y);

    // Move the cursor up or down based on joystick position
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
      Serial.println("Cursor position: " + String(curs));
      delay(500);
    }

    // Check if the joystick button has been pressed to select a menu option
    if (!digitalRead(button_pin)) {
      // If the first menu option is selected, start the labyrinth game
      if (curs == 1) {
        Serial.println("Starting labyrinth game...");
        labyrinth(map1);
        menu_on = false;
        while (menu_on == false) {
          labyrinth_game();
        }
        menu_text();
      }
      // If the second menu option is selected, start the spaceship game
      else if (curs == 2) {
        Serial.println("Starting spaceship game...");
        menu_on = false;
        lcd.clear();
        while (menu_on == false) {
          spaseship_game();
        }
        menu_text();
      }
      // If the third menu option is selected, start the Google Dino game
      else if (curs == 3) {
        menu_on = false;
        Serial.println("Starting Google Dino game...");
        lcd.clear();
        lcd.setCursor(3, 3);
        lcd.printByte(0);
        while (menu_on == false) {
          Google_Dino();
        }
        menu_text();
      }
    }
  }
}
