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
  gluLookAt(5, 10, 5, 0, 0, 0, 0, 1, 0);

  // Rendering code for the cube and ground plane
  glBegin(GL_QUADS);

  // Cube
  // Front face
  glColor3f(1.0f, 0.0f, 0.0f); // Red
  glVertex3f(-1.0f, 0.0f, 1.0f);
  glVertex3f(1.0f, 0.0f, 1.0f);
  glVertex3f(1.0f, 2.0f, 1.0f);
  glVertex3f(-1.0f, 2.0f, 1.0f);
  // Back face
  glColor3f(0.0f, 1.0f, 0.0f); // Green
  glVertex3f(-1.0f, 0.0f, -1.0f);
  glVertex3f(1.0f, 0.0f, -1.0f);
  glVertex3f(1.0f, 2.0f, -1.0f);
  glVertex3f(-1.0f, 2.0f, -1.0f);
  // Top face
  glColor3f(0.0f, 0.0f, 1.0f); // Blue
  glVertex3f(-1.0f, 2.0f, -1.0f);
  glVertex3f(1.0f, 2.0f, -1.0f);
  glVertex3f(1.0f, 2.0f, 1.0f);
  glVertex3f(-1.0f, 2.0f, 1.0f);
  // Bottom face
  glColor3f(1.0f, 1.0f, 0.0f); // Yellow
  glVertex3f(-1.0f, 0.0f, -1.0f);
  glVertex3f(-1.0f, 0.0f, 1.0f);
  glVertex3f(1.0f, 0.0f, 1.0f);
  glVertex3f(1.0f, 0.0f, -1.0f);
  // Right face
  glColor3f(1.0f, 0.0f, 1.0f); // Magenta
  glVertex3f(1.0f, 0.0f, -1.0f);
  glVertex3f(1.0f, 2.0f, -1.0f);
  glVertex3f(1.0f, 2.0f, 1.0f);
  glVertex3f(1.0f, 0.0f, 1.0f);
  // Left face
  glColor3f(0.0f, 1.0f, 1.0f); // Cyan
  glVertex3f(-1.0f, 0.0f, -1.0f);
  glVertex3f(-1.0f, 0.0f, 1.0f);
  glVertex3f(-1.0f, 2.0f, 1.0f);
  glVertex3f(-1.0f, 2.0f, -1.0f);

  // Ground plane
  glColor3f(0.2f, 0.2f, 0.2f);  // Gray
  glNormal3f(0.0f, 1.0f, 0.0f); // Normal vector pointing upwards
  glVertex3f(-5.0f, 0.0f, -5.0f);
  glVertex3f(-5.0f, 0.0f, 5.0f);
  glVertex3f(5.0f, 0.0f, 5.0f);
  glVertex3f(5.0f, 0.0f, -5.0f);

  glEnd();

  glutSwapBuffers();
}
