bool checkWall(int  x, int y, int level ) {
  if (level == 1) {
    return map1[y][x];
  } else if (level == 2) {
    return map2[y][x];
  } else if (level == 3) {
    return map3[y][x];
  }
}
