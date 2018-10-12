#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <png/png.h>
#include <GL/gl.h>
#include <GL/glkos.h>
#include <GL/glext.h>
#include <GL/glu.h>

#include "gl_png.h"

#define CLEANUP(x) { ret = (x); goto cleanup; }

int png_to_gl_texture(texture *tex, char *filename) {
	int ret = 0;
	FILE * file = 0;
	uint8_t * data = 0;
	png_structp parser = 0;
	png_infop info = 0;
	png_bytep * row_pointers = 0;

	png_uint_32 w, h;
	int bit_depth;
	int color_type;


	if(!tex || !filename) {
		CLEANUP(1);
	}

	file = fopen(filename, "rb");
	if(!file) {
		CLEANUP(2);
	}

	parser = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
	if(!parser) {
		CLEANUP(3);
	}

	info = png_create_info_struct(parser);
	if(!info) {
		CLEANUP(4);
	}

	if(setjmp(png_jmpbuf(parser))) {
		CLEANUP(5);
	}

	png_init_io(parser, file);
	png_read_info(parser, info);
	png_get_IHDR(parser, info, &w, &h, &bit_depth, &color_type, 0, 0, 0);

	if((w & (w-1)) || (h & (h-1)) || w < 8 || h < 8) {
		CLEANUP(6);
	}

	if(png_get_valid(parser, info, PNG_INFO_tRNS) || (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8) || color_type == PNG_COLOR_TYPE_PALETTE) {
		png_set_expand(parser);
	}
	if(bit_depth == 16) {
		png_set_strip_16(parser);
	}
	if(color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_GRAY_ALPHA) {
		png_set_gray_to_rgb(parser);
	}
	png_read_update_info(parser, info);

	int rowbytes = png_get_rowbytes(parser, info);
	rowbytes += 3 - ((rowbytes-1) % 4); // align to 4 bytes

	data = malloc(rowbytes * h * sizeof(png_byte) + 15);
	if(!data) {
		CLEANUP(7);
	}

	row_pointers = malloc(h * sizeof(png_bytep));
	if(!row_pointers) {
		CLEANUP(8);
  }

	// set the individual row_pointers to point at the correct offsets of data
	for(png_uint_32 i = 0; i < h; ++i) {
		row_pointers[h - 1 - i] = data + i * rowbytes;
	}

	png_read_image(parser, row_pointers);

	// Generate the OpenGL texture object
	GLuint texture_id;
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	GLenum texture_format = (color_type & PNG_COLOR_MASK_ALPHA) ? GL_RGBA : GL_RGB;
	//GLenum texture_format = GL_RGB;
	glTexImage2D(GL_TEXTURE_2D, 0, texture_format, w, h, 0, texture_format,   GL_UNSIGNED_BYTE, data);

	tex->id = texture_id;
	tex->w = w;
	tex->h = h;
	tex->u = 0.f;
	tex->v = 0.f;
	tex->uSize = tex->vSize = 1.f;
	tex->xScale = tex->yScale = 1.f;
	tex->format = texture_format;
	tex->min_filter = tex->mag_filter = GL_LINEAR;
	tex->blend_source = GL_SRC_ALPHA;
	tex->blend_dest = GL_ONE_MINUS_SRC_ALPHA;

cleanup:
	if(parser) {
		png_destroy_read_struct(&parser, info ? &info : 0, 0);
	}

	if(row_pointers) {
		free(row_pointers);
	}

	if(data) {
		free(data);
	}

	if(file) {
		fclose(file);
	}

	return ret;
}


void draw_textured_quad(texture *tex, float x, float y, float z) {
	GLfloat texW = 1;
	GLfloat texH = 1;
	//texW = 10;
	//texH = 10;
	GLfloat x0 = x - texW / 2;
	GLfloat y0 = y - texH / 2;
	GLfloat x1 = x + texW / 2;
	GLfloat y1 = y + texH / 2;
	GLfloat u = tex->u;
	GLfloat v = tex->v;
	GLfloat xS = tex->uSize;
	GLfloat yS = tex->vSize;


	GLfloat vertex_data[] = {
		/* 2D Coordinate, texture coordinate */
		x0, y1, z,
		x1, y1, z,
		x1, y0, z,
		x0, y0, z
	};

	GLfloat uv_data[] = {
		/* 2D Coordinate, texture coordinate */
		u, v + yS,
		u + xS, v + yS,
		u + xS, v,
		u, v
	};

	GLfloat normal_data[] = {
		/* 2D Coordinate, texture coordinate */
		0.0, 0.0, 1.0,
		0.0, 0.0, 1.0,
		0.0, 0.0, 1.0,
		0.0, 0.0, 1.0
	};

	GLfloat color_data[] = {
		/* 2D Coordinate, texture coordinate */
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f
	};

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex->id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, tex->min_filter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, tex->mag_filter);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer			(3, GL_FLOAT, 0, vertex_data);
	glTexCoordPointer		(2, GL_FLOAT, 0, uv_data);
	glNormalPointer			(GL_FLOAT, 0, normal_data);
	glColorPointer			(4, GL_FLOAT, 0, color_data);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDrawArrays(GL_QUADS, 0, 4);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}
