/******************************************************
This is a simple exemple to learn how to use the controller inputs.

This uses Kazade's GLdc and some part of his NeHe example.

Author: lerabot/magnes
Date  : 09/09/2018
*****************************************************/
#include <kos.h>
#include <GL/gl.h>
#include <GL/glkos.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>


float pos[2];                                   //rect position
float col[4] = {1.0f, 0.0f, 0.0f, 1.0f};        //rect color
float rot = 0.0f;
float speed = 0.3f;

maple_device_t  *cont;     //controller
cont_state_t    *state;    //state of inputs
uint32_t        p_buttons;   //previous buttons
uint32_t        n_buttons;   //new buttons

void drawRect(float x, float y) {
  glPushMatrix();
  glTranslatef(x, y,-30.0f);        //Translate the rect to X & Y
  glRotatef(rot, 0.0f, 0.0f, 1.0f); //Rotate around the Z axis
  glBegin(GL_QUADS);				        //Start drawing a polygon (4 sided)
  glColor3f(col[0], col[1], col[2]);//
  glVertex3f(-1.0f, 1.0f, 0.0f);		// Top Left
  glVertex3f( 1.0f, 1.0f, 0.0f);		// Top Right
  glVertex3f( 1.0f,-1.0f, 0.0f);		// Bottom Right
  glVertex3f(-1.0f,-1.0f, 0.0f);		// Bottom Left
  glEnd();					                // done with the polygon
  glPopMatrix();
}

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

//This simple function will check if a button has been pressed
int buttonPressed(uint16 key) {
  if (state->buttons & key && !(p_buttons & key)) { //Compares to the current state and the previous buttons states.
      p_buttons |= state->buttons; // If true, it will "add" the buttons to the pressed buttons
      return(1);
  }
  return(0);
}

int main() {

  glKosInit();              //Mandatory function to start KOS and set some GL params
  InitGL(640, 480);         //Create a "window" at the DC resolution

  pos[0] = 0.0f;           //position of cursor
  pos[1] = 0.0f;           //position of cursor

  time_t t;
  // Intializes random number generator. This is used for the random color
  srand((unsigned) time(&t));
  cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);
  state = (cont_state_t *)maple_dev_status(cont);
  p_buttons = n_buttons = 0;

  while(1) {
    // Check key status
    state = (cont_state_t *)maple_dev_status(cont);

    // If the state/controller is unavailable
    if(!state) {
        printf("Error reading controller\n");
        break;
    }

    //This is a simple way to use the DPAD
    if(state->buttons & CONT_DPAD_LEFT)
        pos[0] -= speed;

    if(state->buttons & CONT_DPAD_RIGHT)
        pos[0] += speed;

    if(state->buttons & CONT_DPAD_UP)
        pos[1] += speed;

    if(state->buttons & CONT_DPAD_DOWN)
        pos[1] -= speed;


    //We're using buttonPressed to prevent retriggering to happen.
    if(buttonPressed(CONT_A)) {
      col[0] = rand()%100 / 100.0f;
      col[1] = rand()%100 / 100.0f;
      col[2] = rand()%100 / 100.0f;
    }

    //Uncomment if you want to use the joystick to move the rect
    //pos[0] = state->joyx  / 10.0f;
    //pos[1] = -state->joyy / 10.0f;

    //Using the ltrig and rtrig is very similar to the joystick.
    rot += state->ltrig / 100.0f;
    rot -= state->rtrig / 100.0f;


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //Clear the screen
    glLoadIdentity();				                             //Reset The View
    drawRect(pos[0], pos[1]);                            //Draw the rectangle
    glKosSwapBuffers();                                  //Swap buffer (draw the current frame)

    p_buttons &= state->buttons;  //This operation will set p_buttons as the latest changes in states.
  }
  return(0);
}
