#include "graphics.hpp"
#include "hashtable.hpp"
#include <GL/glut.h>
#include <fmt/color.h>
Cell *cells[10][3];
HashMap *h;

void simWindow();
void display();
void deb_mouse(int btn, int state, int x, int y) {
  if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    cout << "(" << x << ", " << y << ")";
  }
}
void idle() { display(); }
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  h = new HashMap;
  for (int i = 0, y = 10; i < 10; i++, y += 48) {
    cells[i][0] = new Cell(10, y, 50, 40, "");
    cells[i][1] = new Cell(70, y, 173, 40, "");
    cells[i][2] = new Cell(253, y, 100, 40, "");
    cells[i][0]->bordered(true);
    cells[i][1]->bordered(true);
    cells[i][2]->bordered(true);
  }
  thread simulation(&simWindow);
  while (true) {
    string ch;
    cout << "\n\n";
    fmt::print(fg(fmt::color::floral_white) | fmt::emphasis::bold,
               "===MENU===\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your "
               "choice : ");
    cin >> ch;
    int val = atoi(ch.data());
    cout << "\n\n";
    if (val <= 0 || val > 4) {
      fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold,
                 "[WARN] Not a valid choice (VALID CHOICE RANGES FROM 1-4)");
      cout << "\n\n";
      continue;
    }
    switch (val) {
    case 1: {
      string key;
      int value;
      cout << "Enter the key : ";
      cin >> key;
      cout << "Enter the value : ";
      cin >> value;
      h->insertNode(cells, key, value);
      break;
    }
    case 2: {
      string key;
      cout << "Enter the key : ";
      cin >> key;
      h->deleteNode(cells, key);
      break;
    }
    case 3: {
      h->display();
      break;
    }
    case 4: {
      simulation.join();
      exit(0);
    }
    }
  }
  simulation.join();
  return 0;
}

void simWindow() {
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("  ");
  glutDisplayFunc(display);
  glutIdleFunc(idle);
  //  glutMouseFunc(deb_mouse);
  glClearColor(0.0, 0.0, 0.0, 0.0);
  gluOrtho2D(0.0, 500.0, 0.0, 500.0);
  glutMainLoop();
}
void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  for (int i = 0; i < 10; i++) {
    if (cells[i][0] == NULL || cells[i][1] == NULL || cells[i][2] == NULL) {
      continue;
    }
    cells[i][0]->display();
    cells[i][1]->display();
    cells[i][2]->display();
  }
  glFlush();
}
