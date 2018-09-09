# How to compile the KOS toolchain

*This has been testing under Linux Mint 18 on 9/9/2018*

First, you need to chmod the kos_setup_script.sh

`chmod +x kos_setup_script.sh`

then run it using

`./kos_setup_script.sh`

This script will take a long time to complete as it is downloading a bunch of dependencies and installing them.

### Known Issues

You might have some problem with make_banner.sh. If you do, delete the content of both make_banner.sh and banner.h and type run the script again using `./kos_setup_script.sh`


### Compiling done.

When KOS is done compiling, it should open it's documentation and print this message in the terminal

` Welcome to KOS!
Please check out the example in /opt/toolchains/dc/kos/examples/dreamcast/kgl/nehe/nehe02 to get started.
After editing main.c, type "make" to create an ELF executable. Run it using an emulator.
KOS documentation is at http://gamedev.allusion.net/docs/kos-current.
When you start a new shell, please type -source /opt/toolchains/dc/kos/environ.sh- in order to set the environment variables.
`

Your DC toolchain should now be at `/opt/toolchains/dc`, so making a link or an alias to get there fast would be useful.

You can make an alias to access your KOS folder using

`alias Dreamcast="cd /opt/toolchains/dc/kos"`

This will allow you to type Dreamcast in your terminal to move directly into your toolchain folder. Of course you can change Dreamcast for whatever you like.
