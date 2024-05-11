#include </opt/homebrew/include/GL/glut.h>
#include </opt/homebrew/include/GLFW/glfw3.h>

void display();
void keyPressed(unsigned char key, int x, int y);

int main(int argc, char **argv) {
  glutInit(&argc, argv);

  glutCreateWindow("Test");
  glutDisplayFunc(display);

  glutKeyboardFunc(keyPressed);

  glutMainLoop();
  return 0;
}
