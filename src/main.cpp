#include "graphics.hpp"
#include "hashtable.hpp"
#include <GL/glut.h>
// Driver method to test map class
void init();
void display();
void simulation_start(int *argc, char **argv);
Cell *cells[10][3];
int main(int argc, char *argv[]) {
  simulation_start(&argc, argv);
  return 0;
}
void init() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
  gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}
void display() {
  sleep(1);
  static int index = 9;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  HashMap *h = new HashMap;
  h->insertNode("shyam", 23);
  h->insertNode("nachiketh", 46);
  h->insertNode("samarth", 46);
  h->insertNode("deepika", 92);
  h->insertNode("nisthara", 184);
  h->insertNode("karthik", 230);
  h->insertNode("Manoj", 231);
  h->insertNode("prathvi", 232);
  h->insertNode("shashank", 233);
  h->insertNode("chinnu", 234);
  for (int i = 9, y = 10; i >= 0; i--, y += 48) {
    cells[i][0] = new Cell(10, y, 50, 40, to_string(i));
    cells[i][1] = new Cell(70, y, 173, 40, h->getKey(i));
    cells[i][2] = new Cell(253, y, 100, 40, to_string(h->getValue(i)));
    cells[index][0]->hightlight(true);
    cells[index][1]->hightlight(true);
    cells[index][2]->hightlight(true);
  }
  for (int i = 9; i >= 0; i--) {
    cells[i][0]->display();
    cells[i][1]->display();
    cells[i][2]->display();
  }
  glutPostRedisplay();
  index++;
  index %= 10;
  glFlush();
}
void simulation_start(int *argc, char **argv) {
  glutInit(argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("     ");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}
