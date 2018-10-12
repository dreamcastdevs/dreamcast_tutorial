#ifndef __GL_PNG_H__
#define __GL_PNG_H__

#include <GL/gl.h>

typedef struct _texture {
	GLuint 		id;							// pointer to the texture ID (usefull for freeing them)
	GLenum 		format;					// color format
	GLenum 		min_filter;
	GLenum 		mag_filter;
	GLenum		blend_source;
	GLenum		blend_dest;
	int			 	w, h; 					// width / height of texture image
	float 		u, v; 					// uv Cordinate
	float 		uSize, vSize; 	// uv Size
	float 		xScale, yScale; // render Scale
	float 		a; 							// alpha

} texture;

// converts a png into a GL compatible texture.
int 	png_to_gl_texture(texture *tex, char *filename);

//	draws a texture
void 	draw_textured_quad(texture *tex, float x, float y, float z);

#endif
