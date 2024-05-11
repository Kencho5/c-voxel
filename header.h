#ifndef HEADER_H
#define HEADER_H

#include </opt/homebrew/include/GL/glut.h>

extern float cameraX;
extern float cameraY;
extern float cameraZ;

void keyPressed(unsigned char key, int x, int y);
void specialKeyPress(int key, int x, int y);
void display();
void moveCamera();

#endif
