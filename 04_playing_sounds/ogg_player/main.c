/******************************************************
This is inspired by the sample in the libogg

Author: lerabot/magnes
Date  : 12/10/2018
*****************************************************/
#include <kos.h>
#include <stdint.h>
#include <oggvorbis/sndoggvorbis.h>

extern uint8    romdisk[]; //Create a romdisk pointer
KOS_INIT_ROMDISK(romdisk); //Init. the romdisk. Everything in the romdisk folder is now located at /rd/ on your DC.

uint32_t p_buttons;       //Saves the previous button states

//This simple function will check if a button has been pressed
int buttonPressed(cont_state_t *state, uint16 key) {
  if (state->buttons & key && !(p_buttons & key)) { //Compares to the current state and the previous buttons states.
      p_buttons |= state->buttons; // If true, it will "add" the buttons to the pressed buttons
      return(1);
  }
  return(0);
}

int main() {
  maple_device_t  *cont;     //Controller
  cont_state_t    *state;    //State of inputs

  snd_stream_init();        //Init the SND_Stream which allow to stream audio from long audio source.
  sndoggvorbis_init();      //Init the OggVorbis streams.

  int new_volume = 150;

  //You only need to call the start function once. This will play your song.
  sndoggvorbis_start("/rd/test.ogg", 1); //Plays the sound source, 1 is loop.


  while(1) {
    //Classic controller stuff
    cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);
    state = (cont_state_t *)maple_dev_status(cont);
    if(!state) {
        printf("Error reading controller\n");
        break;
    }

    //Pressing B will stop the song.
    if(buttonPressed(state, CONT_B) && sndoggvorbis_isplaying())
      sndoggvorbis_stop();

    //Pressing A will start the song.
    if(buttonPressed(state, CONT_A) && !sndoggvorbis_isplaying())
      sndoggvorbis_start("/rd/test.ogg", 1);

    //You can use the UP and DOWN dpad to raise or lower the volume.
    if(buttonPressed(state, CONT_DPAD_DOWN)) {
      new_volume += 10;
      sndoggvorbis_volume(new_volume);
    }
    if(buttonPressed(state, CONT_DPAD_UP)) {
      new_volume -= 10;
      sndoggvorbis_volume(new_volume);
    }

    p_buttons &= state->buttons;  //This operation will set p_buttons as the latest changes in states.
  }
  sndoggvorbis_shutdown()
  return(0);
}
