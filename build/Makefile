CC = gcc
CFLAGS = -framework OpenGL -framework GLUT -L/opt/homebrew/lib -lGLEW -I/opt/homebrew/include -DGL_SILENCE_DEPRECATION

SRCDIR = ..
BUILDDIR = .

SOURCES = $(SRCDIR)/main.c $(SRCDIR)/display.c $(SRCDIR)/fps.c $(SRCDIR)/input.c

TARGET = $(BUILDDIR)/main

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

.PHONY: clean

clean:
	rm -f $(TARGET)
