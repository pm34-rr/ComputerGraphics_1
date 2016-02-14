#pragma once

#include "Common.h"

class Primitive
{
public:
	Primitive();

	void			setPoint( const Point & pt, int i );
	const Point &	point( int i );

	void			setColor( const Color & clr );
	const Color &	getColor();

	void			setPointSize( GLfloat pointSize );
	GLfloat			pointSize();

	void			draw();

private:
	Triangle	_triangle;
	Color		_color;
	GLfloat		_pointSize;
	// TODO_2: add other types of changing
};

struct Collection
{
	std::vector<Primitive> primitives;

	Color	color;
};
