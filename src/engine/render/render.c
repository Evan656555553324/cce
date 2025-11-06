#include <engine.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <GL/gl.h>

void cce_setup_2d_projection(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void cce_draw_pixel(int x, int y, int size, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + size, y);
    glVertex2i(x + size, y + size);
    glVertex2i(x, y + size);
    glEnd();
}

void cce_draw_pixel_grid(int pixel_size, int screen_width, int screen_height)
{
    int cols = screen_width / pixel_size;
    int rows = screen_height / pixel_size;
    
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {

            float r = 0.4f;
            float g = ((rand() % 50) / 100.0f) + 0.4f;
            float b = 0;
            
            cce_draw_pixel(x * pixel_size, y * pixel_size, pixel_size, r, g, b);
        }
    }
}