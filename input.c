#include </opt/homebrew/include/GL/glut.h>
#include <stdlib.h>

void moveCamera();

void keyPressed(unsigned char key, int x, int y) {
  switch (key) {
  case 27:
    exit(0);
    break;
  }
}

void specialKeyPress(int key, int x, int y) {
  switch (key) {
  case GLUT_KEY_DOWN:
    moveCamera();
    break;
  }
}
