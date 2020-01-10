# Drawing using GLDC

[GLdc](https://gitlab.com/simulant/GLdc) is a openGL implementation for the Dreamcast that is actively developed by Kazade.

**!! Make sure you clone this repo in the `addons` folder !!**

`cd /opt/toolchains/dc/kos/addons`

`git clone https://gitlab.com/simulant/GLdc.gitt`

### Building GLDC

Once the folder is cloned

`cd GLdc && make defaultall && make create_kos_link`

You can now link GLdc using -lGLdc
