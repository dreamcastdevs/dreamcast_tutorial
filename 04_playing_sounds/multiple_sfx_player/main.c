/******************************************************
Let's try to load as much sound as we can and play them.

Author: lerabot/magnes
Date  : 09/09/2018
*****************************************************/
#include <kos.h>
#include <stdio.h>
#include <stdlib.h>

extern uint8      romdisk[]; //Create a romsick pointer
KOS_INIT_ROMDISK  (romdisk); //Init. the romdisk. Everything in the romdisk folder is now located at /rd/ on your DC.
uint32_t          p_buttons;  //Saves the previous button states

//This simple function will check if a button has been pressed
int buttonPressed(cont_state_t *state, uint16 key) {
  if (state->buttons & key && !(p_buttons & key)) { //Compares to the current state and the previous buttons states.
      p_buttons |= state->buttons; // If true, it will "add" the buttons to the pressed buttons
      return(1);
  }
  return(0);
}

int main() {
  maple_device_t  *cont;     //controller
  cont_state_t    *state;    //state of inputs

  while(1) {

    // Refresh the controller data
    cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);
    // Check key status
    state = (cont_state_t *)maple_dev_status(cont);

    // If the state/controller is unavailable
    if(!state) {
        printf("Error reading controller\n");
        break;
    }

    /***************************

    NOT DONEEEE

    ***************************/
  }
  return(0);
}
