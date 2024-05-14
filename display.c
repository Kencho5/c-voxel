#include "header.h"

// Define your vertex data for the entire cube
GLfloat cubeVertices[] = {
    // Front face
    -1.0f, 0.0f, 1.0f, // Vertex 1
    1.0f, 0.0f, 1.0f,  // Vertex 2
    1.0f, 2.0f, 1.0f,  // Vertex 3
    -1.0f, 2.0f, 1.0f, // Vertex 4

    // Back face
    -1.0f, 0.0f, -1.0f, // Vertex 5
    1.0f, 0.0f, -1.0f,  // Vertex 6
    1.0f, 2.0f, -1.0f,  // Vertex 7
    -1.0f, 2.0f, -1.0f, // Vertex 8

    // Top face
    -1.0f, 2.0f, 1.0f,  // Vertex 4
    1.0f, 2.0f, 1.0f,   // Vertex 3
    1.0f, 2.0f, -1.0f,  // Vertex 7
    -1.0f, 2.0f, -1.0f, // Vertex 8

    // Bottom face
    -1.0f, 0.0f, 1.0f,  // Vertex 1
    1.0f, 0.0f, 1.0f,   // Vertex 2
    1.0f, 0.0f, -1.0f,  // Vertex 6
    -1.0f, 0.0f, -1.0f, // Vertex 5

    // Right face
    1.0f, 0.0f, 1.0f,  // Vertex 2
    1.0f, 0.0f, -1.0f, // Vertex 6
    1.0f, 2.0f, -1.0f, // Vertex 7
    1.0f, 2.0f, 1.0f,  // Vertex 3

    // Left face
    -1.0f, 0.0f, 1.0f,  // Vertex 1
    -1.0f, 0.0f, -1.0f, // Vertex 5
    -1.0f, 2.0f, -1.0f, // Vertex 8
    -1.0f, 2.0f, 1.0f,  // Vertex 4
};

// Define your color data for the entire cube
GLfloat cubeColors[] = {
    // Front face (Red)
    1.0f,
    0.0f,
    0.0f,
    1.0f,
    0.0f,
    0.0f,
    1.0f,
    0.0f,
    0.0f,
    1.0f,
    0.0f,
    0.0f,

    // Back face (Green)
    0.0f,
    1.0f,
    0.0f,
    0.0f,
    1.0f,
    0.0f,
    0.0f,
    1.0f,
    0.0f,
    0.0f,
    1.0f,
    0.0f,

    // Top face (Blue)
    0.0f,
    0.0f,
    1.0f,
    0.0f,
    0.0f,
    1.0f,
    0.0f,
    0.0f,
    1.0f,
    0.0f,
    0.0f,
    1.0f,

    // Bottom face (Yellow)
    1.0f,
    1.0f,
    0.0f,
    1.0f,
    1.0f,
    0.0f,
    1.0f,
    1.0f,
    0.0f,
    1.0f,
    1.0f,
    0.0f,

    // Right face (Magenta)
    1.0f,
    0.0f,
    1.0f,
    1.0f,
    0.0f,
    1.0f,
    1.0f,
    0.0f,
    1.0f,
    1.0f,
    0.0f,
    1.0f,

    // Left face (Cyan)
    0.0f,
    1.0f,
    1.0f,
    0.0f,
    1.0f,
    1.0f,
    0.0f,
    1.0f,
    1.0f,
    0.0f,
    1.0f,
    1.0f,
};

// Define vertex data for the ground plane
GLfloat groundVertices[] = {-5.0f, 0.0f, -5.0f, -5.0f, 0.0f, 5.0f,
                            5.0f,  0.0f, 5.0f,  5.0f,  0.0f, -5.0f};

// VBO IDs
GLuint vboVertices, vboColors;

// VBO ID for ground plane
GLuint vboGroundVertices;

// Camera position and rotation
float camX = 0.0f, camY = 1.0f, camZ = 5.0f;
float camRotX = 0.0f, camRotY = 0.0f;

void initVBOs() {
  // Generate VBO IDs
  glGenBuffers(1, &vboVertices);
  glGenBuffers(1, &vboColors);
  glGenBuffers(1, &vboGroundVertices);

  // Bind VBO for vertices and transfer data
  glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
  glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices,
               GL_STATIC_DRAW);

  // Bind VBO for colors and transfer data
  glBindBuffer(GL_ARRAY_BUFFER, vboColors);
  glBufferData(GL_ARRAY_BUFFER, sizeof(cubeColors), cubeColors, GL_STATIC_DRAW);

  // Bind VBO for ground plane and transfer data
  glBindBuffer(GL_ARRAY_BUFFER, vboGroundVertices);
  glBufferData(GL_ARRAY_BUFFER, sizeof(groundVertices), groundVertices,
               GL_STATIC_DRAW);
}

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

  // Apply camera rotation
  glRotatef(camRotX, 1.0f, 0.0f, 0.0f);
  glRotatef(camRotY, 0.0f, 1.0f, 0.0f);

  // Apply camera position
  glTranslatef(-camX, -camY, -camZ);

  // Enable vertex and color arrays
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);

  // Bind VBO for vertices and colors of the cube
  glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
  glVertexPointer(3, GL_FLOAT, 0, 0);

  glBindBuffer(GL_ARRAY_BUFFER, vboColors);
  glColorPointer(3, GL_FLOAT, 0, 0);

  // Draw the cube
  glDrawArrays(GL_QUADS, 0, 24); // 6 faces * 4 vertices per face

  // Cleanup
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);

  // Bind VBO for ground plane
  glBindBuffer(GL_ARRAY_BUFFER, vboGroundVertices);
  glVertexPointer(3, GL_FLOAT, 0, 0);

  // Set color for ground plane
  glColor3f(0.2f, 0.2f, 0.2f); // Gray

  // Enable vertex array for ground plane
  glEnableClientState(GL_VERTEX_ARRAY);

  // Draw ground plane
  glDrawArrays(GL_QUADS, 0, 4);

  // Cleanup
  glDisableClientState(GL_VERTEX_ARRAY);

  glutSwapBuffers();
}
