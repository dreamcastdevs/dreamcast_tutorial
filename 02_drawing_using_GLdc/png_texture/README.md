### What to look for

There's a new file called `gl_png.c`. It's a simplified version of what I use for [Reaperi Cycle](https://github.com/lerabot/reaperi_cycle). Keep in mind that this drawing code was written for a 2D engine.

There's 2 functions in there.

`png_to_gl_texture` takes a texture pointer and a path to a .png file.
`draw_textured_rect` which does exactly that. takes a texture pointer and x,y,z coordinates.

It's a very simplified version. There are no scaling, rotating, coloring or anything set in place, but it should be simple enough for you to figure out.

You can easily change `png_to_gl_texture` path and add your own image to the romdisk folder.

Images need to be in pow2 (32x32, 64x64, 128x128, up to 1024x1024). You could technically go higher but not with the png color formats.

### Compile

Simply use `make`

### Run

`lxdream main.elf`
