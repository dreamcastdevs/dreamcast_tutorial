/******************************************************
Intro to GLdc using basic Quads/Triangle with glBegin() and glEnd()

Author: kazade
Date  : 09/09/2018
*****************************************************/

#include <GL/gl.h>
#include <GL/glkos.h>
#include <GL/glu.h>

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
    glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LESS);				// The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
    glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();				// Reset The Projection Matrix

    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

    glMatrixMode(GL_MODELVIEW);
}

/* The main drawing function. */
void DrawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
    glLoadIdentity();				// Reset The View

    glTranslatef(-1.5f,0.0f,-6.0f);		// Move Left 1.5 Units And Into The Screen 6.0

    // Draw a triangle
    glBegin(GL_POLYGON);				      // Start drawing a polygon
    glColor3f(  1.0f, 1.0f, 1.0f);    // Set the polygon color
    glVertex3f( 0.0f, 1.0f, 0.0f);		// Top
    glVertex3f( 1.0f,-1.0f, 0.0f);		// Bottom Right
    glVertex3f(-1.0f,-1.0f, 0.0f);		// Bottom Left
    glEnd();					                // Done with the polygon

    glTranslatef(3.0f,0.0f,0.0f);		  // Move Right 3 Units

    // Draw a quad (quadrilateral)
    glBegin(GL_QUADS);				        // Start drawing a polygon (4 sided)
    glColor3f(  0.0f, 1.0f, 0.0f);    // Set the polygon color
    glVertex3f(-1.0f, 1.0f, 0.0f);		// Top Left
    glColor3f(  0.0f, 1.0f, 1.0f);    // Set the polygon color
    glVertex3f( 1.0f, 1.0f, 0.0f);		// Top Right
    glColor3f(  0.5f, 0.0f, 0.7f);    // Set the polygon color
    glVertex3f( 1.0f,-1.0f, 0.0f);		// Bottom Right
    glColor3f(  0.0f, 0.4f, 0.9f);    // Set the polygon color
    glVertex3f(-1.0f,-1.0f, 0.0f);		// Bottom Left
    glEnd();					                // Done with the polygon

    // Swap buffers to display, since we're double buffered.
    glKosSwapBuffers();
}

int main(int argc, char **argv)
{
    glKosInit();              //Mandatory function to start KOS and set some GL params
    InitGL(640, 480);         //Create a "window" at the DC resolution

    while(1) {
        DrawGLScene();
    }

    return 0;
}
