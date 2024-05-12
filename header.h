#ifndef HEADER_H
#define HEADER_H

#include </opt/homebrew/include/GL/glut.h>

extern float camX;
extern float camY;
extern float camZ;
extern float camRotX;
extern float camRotY;

void keyPressed(unsigned char key, int x, int y);
void moveCamera(int key, int x, int y);
void display();
void calculateFPS();
void update(int value);

#endif
