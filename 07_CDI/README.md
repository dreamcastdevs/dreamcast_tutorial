# CDI + Packaging
<<<<<<< HEAD

Please take a look at `makeCD.sh`. It's simple script that I made that will create a self-bootable .CDI file and run in in your favorite emulator (or console!)

You can change the value of **PROJECT_NAME** to whatever you see fit.

**TARGET** must match your Makefile's **TARGET**. I usually build my program under `main.elf`

### cdi4dc (prerequisite)
[cdi4dc](https://sourceforge.net/projects/img4dc/) is a small tool that SiZious made in order to make self-booting .CDI files.

The `makeCD.sh` script uses it to create .CDI out of the .ISO images.

Make sure that your version of cdi4cd is set to executable `chmod +x cdi4dc` and that it is in the correct directory. The script is set to look for the executable in `$KOS_BASE/utils/cdi4cd/`

You could also put a sym-link in your `/usr/bin/` and call it directly.

### IP.BIN (prerequisite)

This little file is needed if you're gonna make any Dreamcast disc. It conatins all the usefull info the Dreamcast needs in order to boot. You can take a look at Marcus's site for further info -> [IP.BIN reference](http://mc.pp.se/dc/ip.bin.html)

If you open `IP.BIN` with a hex editor, you'll be able to change your game's name and the developer ID.

I've included a copy of `IP.BIN` in this folder

### dc-load-ip

[dc-load-ip](https://github.com/thentenaar/dc-load-ip) is a tool used to send your games into your dreamcast.
=======
Explain makeCD.sh!

[IP.BIN ref](http://mc.pp.se/dc/ip.bin.html)
>>>>>>> cde00e41e007b5f62e328df745b00bd56e6d3721
