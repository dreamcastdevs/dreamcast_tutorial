### What to look for

Everything is in the DrawGLScene function.

Please note the `glTranslateF` function which translate the whole scene at -6.0 in the z coordinate. A common error is to draw your scene at 0.0 z, which could be where your camera actually is, resulting in a black screen (or not just seeing your polygons)

### Makefile

Simply use `make`

Run in lxdream using `make run`
