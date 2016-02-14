#pragma once

#include <GL/gl.h>

#include <vector>

struct Color
{
	Color( GLubyte gr, GLubyte gg, GLubyte gb ) {
		r = gr;
		g = gg;
		b = gb;
	}
	Color():Color( 0, 0, 0 ) {}

	GLubyte r;
	GLubyte g;
	GLubyte b;
};

struct Point
{
	GLint x;
	GLint y;
};

struct Triangle
{
	std::vector<Point> points;
};
