#include "graphics.hpp"
#include "hashtable.hpp"
#include <GL/glut.h>
#include <fmt/color.h>
Cell *cells[10][4];
HashMap *h;

void simWindow();
void display();
void idle() { display(); }
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  h = new HashMap;
  for (int i = 9, y = 10; i >= 0; i--, y += 48) {
    cells[i][0] = new Cell(10, y, 50, 40, "");
    cells[i][1] = new Cell(70, y, 173, 40, "");
    cells[i][2] = new Cell(253, y, 100, 40, "");
    cells[i][3] = new Cell(353, y, 217, 40, " ");
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
      fflush(stdout);
      fmt::print(
          fg(fmt::color::red) | fmt::emphasis::bold,
          "[ERR] Close the simulation window to exit the application.\n");
      simulation.join();
      exit(0);
    }
    }
  }
  // h->insertNode(cells, "shyam", 213);
  // h->insertNode(cells, "nachiketh", 213);
  // h->insertNode(cells, "nisthara", 213);
  // h->insertNode(cells, "deepika", 213);
  // h->insertNode(cells, "kusumavathi", 213);
  // h->insertNode(cells, "samarth", 213);
  // h->insertNode(cells, "vilas", 213);
  // h->insertNode(cells, "karthik", 213);
  // h->insertNode(cells, "jai ganesh", 213);
  // h->insertNode(cells, "shashank", 213);
  // h->deleteNode(cells, "parijaatam");
  simulation.join();
  cout << endl;
  return 0;
}

void simWindow() {
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(650, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Simulation Window");
  glutDisplayFunc(display);
  glutIdleFunc(idle);
  glClearColor(0.180, 0.204, 0.250, 1.0);

  gluOrtho2D(0.0, 650.0, 0.0, 500.0);
  glutMainLoop();
}
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for (int i = 0; i < 10; i++) {
    if (cells[i][0] == NULL || cells[i][1] == NULL || cells[i][2] == NULL) {
      continue;
    }
    cells[i][0]->display();
    cells[i][1]->display();
    cells[i][2]->display();
    cells[i][3]->display();
  }
  glFlush();
}
