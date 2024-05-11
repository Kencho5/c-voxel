#include </opt/homebrew/include/GL/glut.h>
#include </opt/homebrew/include/GLFW/glfw3.h>

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  // rendering code goes here
  glFlush();
}

void keyPressed(unsigned char key, int x, int y) {
  if (key == 27) {
    exit(0);
  }
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);

  glutCreateWindow("Test");
  glutDisplayFunc(display);

  glutKeyboardFunc(keyPressed);

  glutMainLoop();
  return 0;
}
