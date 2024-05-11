#include "header.h"
#include </opt/homebrew/include/GL/glut.h>
#include <stdlib.h>

void keyPressed(unsigned char key, int x, int y) {
  switch (key) {
  case 27:
    exit(0);
    break;
  }
}

void moveCamera(int key, int x, int y) {
  float cameraSpeed = 1.0f;
  switch (key) {
  case GLUT_KEY_LEFT:
    cameraX -= cameraSpeed;
    break;
  case GLUT_KEY_RIGHT:
    cameraX += cameraSpeed;
    break;
  case GLUT_KEY_UP:
    cameraZ -= cameraSpeed;
    break;
  case GLUT_KEY_DOWN:
    cameraZ += cameraSpeed;
    break;
  }
  glutPostRedisplay();
}
