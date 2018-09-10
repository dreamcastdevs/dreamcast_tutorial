# Drawing using GLDC

[Kazade's GLdc](https://github.com/Kazade/GLdc) is a openGL implementation for the Dreamcast that is actively developed.

Make sure you clone this repo in the `addons` folder

`cd /opt/toolchains/dc/kos/addons`

`git clone https://github.com/Kazade/GLdc.git`

### Building GLDC

Once the folder is cloned

`cd GLdc && make defaultall && make create_kos_link`

You can now link GLdc using -lGLdc
