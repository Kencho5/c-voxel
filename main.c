#include "header.h"

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Test");

  initVBOs();

  // Enable depth testing
  glEnable(GL_DEPTH_TEST);

  glutTimerFunc(0, update, 0);

  glutDisplayFunc(display);
  glutKeyboardFunc(keyPressed);
  glutSpecialFunc(moveCamera);

  glutMainLoop();
  return 0;
}
