#include </opt/homebrew/include/GL/glut.h>

void display() {
  // Clear the color and depth buffers
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Set up perspective projection
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);

  // Set up the view transformation (position and orientation of the camera)
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

  // rendering code for 3D objects goes here
  glBegin(GL_QUADS);
  // Front face
  glColor3f(1.0f, 0.0f, 0.0f); // Red
  glVertex3f(-1.0f, -1.0f, 1.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);
  // Back face
  glColor3f(0.0f, 1.0f, 0.0f); // Green
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);
  glVertex3f(1.0f, 1.0f, -1.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);

  glEnd();
  glutSwapBuffers();
}
