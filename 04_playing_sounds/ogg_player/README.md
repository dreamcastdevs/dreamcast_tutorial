### What to look for

This is a very barebone .ogg player witgh simple controls.
DPAD will increase/decrese volume and A/B will start/stop.

The snd libraries (ogg/mp3) will stream mono/stereotrack. When I say stream, I mean that will handle filling the sound buffer with your audio file and playing it in a seemless way. It's very useful for background music if you want to store your sound on `/cd`

(Note that if you use the mp3 library you might need to make your project open source due to legal stuff of the library that the mp3 port depends on)

### Makefile

Simply use `make`

Run in lxdream using `make run`
