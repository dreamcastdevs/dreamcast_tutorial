/******************************************************
This is a simple exemple to learn
how to draw texture on the screen.

This uses Kazade's GLdc and some part of his NeHe example.

Author: lerabot
Date  : 12/10/2018
*****************************************************/
#include <kos.h>
#include <GL/gl.h>
#include <GL/glkos.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include "gl_png.h"

extern uint8    romdisk[]; //Create a romsick pointer
KOS_INIT_ROMDISK(romdisk); //Init. the romdisk. Everything in the romdisk folder is now located at /rd/ on your DC.
texture t1;

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
    glClearDepth(1.0);				              // Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LESS);				            // The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST);			          // Enables Depth Testing
    glShadeModel(GL_SMOOTH);			          // Enables Smooth Color Shading

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();				// Reset The Projection Matrix
    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

    glMatrixMode(GL_MODELVIEW);
}

int main() {
  maple_device_t  *cont;     //controller
  cont_state_t    *state;    //state of inputs

  glKosInit();              //Mandatory function to start KOS and set some GL params
  InitGL(640, 480);         //Create a "window" at the DC resolution

  png_to_gl_texture(&t1, "/rd/controller.png"); //This function will load a PNG file into a texture <-------------------

  float angle = 0.0f;

  while(1) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //Clear the screen
    glLoadIdentity();				                              //Reset the View
    glPushMatrix();                                       //Push matrix
    glRotatef(angle, 0.0f, 0.0f, 1.0f);                   //Rotating the canevas
    angle += 0.25f;                                       //Increasing the angle
    draw_textured_quad(&t1, 0, 0, -5);                    //Draw the textured rectangle <--------------------------------
    glPopMatrix();                                        //Poping the matrix back in place.
    glKosSwapBuffers();                                   //Swap buffer (draw the current frame)

  }
  return(0);
}
