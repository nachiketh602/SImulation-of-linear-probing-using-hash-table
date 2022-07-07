#ifndef GRAPHICS_H_
#define GRAPHICS_H_
#include "config.hpp"
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;
class Cell {
  string data;
  bool isHighlighted;
  bool isBordered;
  int x, y, width, height;

public:
  Cell(int x, int y, int weight, int height, string data);
  Cell(string data);
  void hightlighted(bool val);
  void bordered(bool val);
  void display();
  void print();
  void setText(string text);
  void clearText();
};
#endif // GRAPHICS_H_
