#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "vector.h"
#include "pixel.h"

#define GL_SCREEN_W     480
#define GL_SCREEN_H     360

typedef struct
{
    V3 pos, rotation;
} Camera; Camera camera = {(V3){0, 0, 0}, (V3){0, 0, 0}};

void InitFunc()
{
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    gluOrtho2D(0, GL_SCREEN_W, GL_SCREEN_H, 0);
    glPointSize(GL_PIXEL_SIZE);
}

void DisplayFunc()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glTranslatef(-camera.pos.x, -camera.pos.y, -camera.pos.z);
    glRotatef(camera.rotation.x, 1, 0, 0);
    glRotatef(camera.rotation.y, 0, 1, 0);
    glRotatef(camera.rotation.z, 0, 0, 1);

    glColor3f(1, 1, 1);
    for (int i = 0; i < 20; ++i)
        Pixel((V2){i, i});

    glPopMatrix();
    glutSwapBuffers();
    glutPostRedisplay();
}

void KeyboardFunc(unsigned char key, int _, int __)
{
    return;
}

void KeyboardUpFunc(unsigned char key, int _, int __)
{
    return;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(GL_SCREEN_W, GL_SCREEN_H);

    glutCreateWindow("Sample 2D");

    InitFunc();

    glutDisplayFunc(DisplayFunc);
    glutKeyboardFunc(KeyboardFunc);
    glutKeyboardUpFunc(KeyboardUpFunc);

    glutMainLoop();

    return 0;
}
