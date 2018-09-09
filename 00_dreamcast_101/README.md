# Dreamcast 101

Here are some must have knowledge you need to have before you start Dreamcast programming.

### KallistiOS

The library behind most of the DC homebrew scene is [KallistiOS](http://gamedev.allusion.net/softprj/kos/)(KOS).
In order to get anything running on the DC, we'll need to compile KOS and link it to your code.

The included `makefile` in the 02 folder will do this for you.

### Programming language

KOS works both with C and C++. I'm more versed in C, so this is what I'll use for the tutorials. This being said, if you know how to work with C++, you could adapt those example pretty easily.

Also, I've been successfully working with LUA within my C code. I might include a LUA-C example later.

### Testing your code

There are many way to test your code. The easiest is to run it in a emulator, this being said, you might run into some strange behaviors once you get your code running on console. There is a `makeCD.sh` script included that will transform your programs into .CDI. These .CDI will work wonderfully with [redream](https://redream.io) or [lxdream](http://www.lxdream.org/download.php) but won't work if you burn them. More on that later.

There will also be a tutorial to get your code on your machine using DC-IP-LOAD

### PVR (graphic chip) info

### Sound chip
