CC = gcc
CFLAGS = -framework OpenGL -framework GLUT -L/opt/homebrew/lib -lGLEW -I/opt/homebrew/include -DGL_SILENCE_DEPRECATION

main: main.c
	$(CC) $(CFLAGS) main.c -o main

