#include </opt/homebrew/include/GL/glut.h>
#include <stdio.h>

// Variables to track FPS
int frameCount = 0;
int currentTime = 0;
int previousTime = 0;

// Function to calculate FPS
void calculateFPS() {
  frameCount++;
  currentTime = glutGet(GLUT_ELAPSED_TIME);

  int timeInterval = currentTime - previousTime;

  if (timeInterval > 1000) {
    float fps = frameCount / (timeInterval / 1000.0f);
    printf("FPS: %.2f\n", fps);
    previousTime = currentTime;
    frameCount = 0;
  }
}

// Function called for each frame
void update(int value) {
  glutPostRedisplay();
  glutTimerFunc(0, update, 0); // No FPS cap
  calculateFPS();
}
