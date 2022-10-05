#ifndef PIXEL_H_
#define PIXEL_H_

#include <GL/gl.h>

#include "vector.h"

#define GL_PIXEL_SIZE   4

void Pixel(V2 pos)
{
    glBegin(GL_POINTS);
    glVertex2f(pos.x * GL_PIXEL_SIZE + (GL_PIXEL_SIZE * 0.5f), pos.y * GL_PIXEL_SIZE + (GL_PIXEL_SIZE * 0.5f));
    glEnd();
}

#endif // PIXEL_H_