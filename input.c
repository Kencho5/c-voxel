#include </opt/homebrew/include/GL/glut.h>
#include <stdlib.h>

void keyPressed(unsigned char key, int x, int y) {
  if (key == 27) {
    exit(0);
  }
}
