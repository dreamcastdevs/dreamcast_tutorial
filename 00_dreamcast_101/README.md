# Dreamcast 101

### KallistiOS

The library behind most of the DC homebrew scene is [KallistiOS](http://gamedev.allusion.net/softprj/kos/)(KOS).
In order to get anything running on the DC, we'll need to compile KOS and link it to your code.

There are exemple on how to do this in the **02** folder.

### Programming language

KOS works both with C and C++. I'm more versed in C, so this is what I'll use for the tutorials. This being said, if you know how to work with C++, you could adapt those example pretty easily.

Also, I've been successfully working with LUA within my C code. I might include a LUA-C example later.

### Testing your code

There are many way to test your code. The easiest is to run it in a emulator, this being said, you might run into some strange behaviors once you get your code running on console.

There is a `makeCD.sh` script included that will transform your programs into .CDI files. These .CDI will work  with [redream](https://redream.io) or [lxdream](http://www.lxdream.org/download.php) but won't work if you burn them just yet. You can read more about that in the **07** sections

There will also be a tutorial to get your code on your machine using DC-IP-LOAD

### PVR

The PVR is the graphic chip in your Dreamcast. It's capable of wonderful thing (for 1999) but it has some limitation. It has 8MB of vram and by default, can only use power of 2 texture (from 8x8 up to 2084x2084) to name only those two.  There's multiple ways to use the PVR, KOS gives us a bunch of function in pvr.h, but for the scope of these tutorial we'll be using [GLdc](https://github.com/Kazade/GLdc.git), a modern OpenGL port written by Kazade.

We'll start using GLdc as soon as the **02** tutorial.

You can read more about specs [here](https://segaretro.org/Sega_Dreamcast/Technical_specifications#Graphics)

### Sound chip

Coming soon
