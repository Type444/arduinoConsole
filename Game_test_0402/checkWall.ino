// Check if a wall is present at the specified coordinates on the current level
bool checkWall(int x, int y, int level) {
  // Get the current level map
  bool (*map)[20];
  if (level == 1) {
    map = map1;
  } else if (level == 2) {
    map = map2;
  } else if (level == 3) {
    map = map3;
  } else {
    Serial.println("Invalid level: " + String(level));
    return true;
  }

  // Check if a wall is present at the specified coordinates
  bool wall = map[y][x];
  if (wall) {
    Serial.println("Wall detected at x=" + String(x) + ", y=" + String(y) + ", level=" + String(level));
  }

  return wall;
}
