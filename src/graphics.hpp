#ifndef GRAPHICS_H_
#define GRAPHICS_H_
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;
class Cell {
  string data;
  bool is_highlighted;
  int x, y, width, height;

public:
  Cell(int x, int y, int weight, int height, string data);
  Cell(string data);
  void hightlight(bool val);
  void display();
  void print();
  void setText(string text);
};
#endif // GRAPHICS_H_
