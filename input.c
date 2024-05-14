#include "header.h"
#include <math.h>
#include <stdlib.h>

// Movement speed and rotation speed
float moveSpeed = 0.8f;
float rotSpeed = 10.0f;

void keyPressed(unsigned char key, int x, int y) {
  switch (key) {
  case 27:
    exit(0);
    break;
  case 'w':
    camX += moveSpeed * sin(camRotY * M_PI / 180.0f);
    camZ -= moveSpeed * cos(camRotY * M_PI / 180.0f);
    break;
  case 's':
    camX -= moveSpeed * sin(camRotY * M_PI / 180.0f);
    camZ += moveSpeed * cos(camRotY * M_PI / 180.0f);
    break;
  case 'd':
    camX += moveSpeed * sin((camRotY + 90.0f) * M_PI / 180.0f);
    camZ -= moveSpeed * cos((camRotY + 90.0f) * M_PI / 180.0f);
    break;
  case 'a':
    camX += moveSpeed * sin((camRotY - 90.0f) * M_PI / 180.0f);
    camZ -= moveSpeed * cos((camRotY - 90.0f) * M_PI / 180.0f);
    break;
  }
  glutPostRedisplay();
}

void moveCamera(int key, int x, int y) {
  switch (key) {
  case GLUT_KEY_RIGHT:
    camRotY += rotSpeed;
    break;
  case GLUT_KEY_LEFT:
    camRotY -= rotSpeed;
    break;
  case GLUT_KEY_DOWN:
    camRotX += rotSpeed;
    break;
  case GLUT_KEY_UP:
    camRotX -= rotSpeed;
    break;
  }
  glutPostRedisplay();
}
