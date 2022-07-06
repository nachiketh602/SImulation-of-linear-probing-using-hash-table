#include "graphics.hpp"
void drawPixel(int m, int n) {
  glColor3ub(255, 200, 106);
  glBegin(GL_POINTS);
  glVertex2i(m, n);
  glEnd();
}
void edgeDetect(GLint x1, GLint y1, GLint x2, GLint y2, GLint *le, GLint *re) {
  float mx, x, temp;
  int i;
  if ((y2 - y1) < 0) {
    temp = y1;
    y1 = y2;
    y2 = temp;
    temp = x1;
    x1 = x2;
    x2 = temp;
  }
  if ((y2 - y1 != 0)) {
    mx = (x2 - x1) / (y2 - y1);
  } else {
    mx = x2 - x1;
  }
  x = x1;
  for (i = y1; i < y2; i++) {
    if (x < le[i]) {
      le[i] = x;
    }
    if (x > re[i]) {
      re[i] = x;
    }
    x += mx;
  }
}
void scanfill(int x, int y, int width, int height) {
  int le[500], re[500];
  for (int i = 0; i < 500; i++) {
    le[i] = 500;
    re[i] = 0;
  }
  edgeDetect(x, y, x + width, y, le, re);
  edgeDetect(x + width, y, x + width, y + height, le, re);
  edgeDetect(x + width, y + height, x, y + height, le, re);
  edgeDetect(x, y + height, x, y, le, re);
  for (int y = 0; y < 500; y++) {
    for (int i = le[y]; i <= re[y]; i++) {
      drawPixel(i, y);
    }
  }
}
void renderRectangle(int x, int y, int width, int height) {
  glBegin(GL_LINE_LOOP);
  glVertex2i(x, y);
  glVertex2i(x + width, y);
  glVertex2i(x + width, y + height);
  glVertex2i(x, y + height);
  glEnd();
}

void renderText(string data, int x, int y) {
  glRasterPos2i(x + 20, y + 15);
  for (int i = 0; i < data.length(); i++) {
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)data[i]);
  }
}

Cell::Cell(int x, int y, int width, int height, string data) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->data = data;
  this->isHighlighted = false;
  this->isBordered = true;
}

Cell::Cell(string data) { this->data = data; }

void Cell::display() {
  if (this->isHighlighted) {
    glColor3ub(255, 0, 0);
  }
  renderRectangle(this->x, this->y, this->width, this->height);
  if (this->data == "" || this->data == "-1") {
    scanfill(this->x, this->y, this->width, this->height);
  } else {
    renderText(this->data, this->x, this->y);
  }
  glColor3ub(255, 255, 255);
}
void Cell::print() {
  cout << this->data << " at " << this->x << " and " << this->y << endl;
}
void Cell::hightlighted(bool val) { this->isHighlighted = val; }
void Cell::bordered(bool val) { this->isBordered = val; }
void Cell::setText(string text) { this->data = text; }
void Cell::clearText() { this->data = ""; }
