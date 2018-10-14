### What to look for

Here, we're using the Dreamcast controller to interact with the scene.

Keep an eye open for the `maple_device_t` and `cont_state_t`. The maple device keep track of that's plugged in (VMU, keyboard, etc) while the states keep tracks of it's buttons and joystick.

You'll need to call `(cont_state_t *)maple_dev_status(cont)` if you want to pool data on each frame.

Here's the [KOS reference](http://gamedev.allusion.net/docs/kos-2.0.0/structcont__state__t.html) if you need to know what the `state` holds.

Using the D-PAD is simple. You usually want people to hold it to move around. Using something like `if(state->buttons & CONT_DPAD_UP)` will usually do the trick.

The joystick are also quite simple. `state->joyx` will return a number between -127 and +127.

Button A will change the color of the square. Since we need a single button press, you'll need to check the difference between the previous inputs and the current one. There are many way to do this.

There's a simple function called `buttonPress(cont_state_t *state, int key)` which will take a "state" and a button key code which will check if but button is newly pressed. For this to work, you need `p_buttons &= state->buttons;` at the end of your code. This will keep track of the newly pressed buttons.

### Makefile

Simply use `make`

Run in lxdream using `make run`
