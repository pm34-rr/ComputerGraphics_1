#include "Primitive.h"

Primitive::Primitive():
	_color( 255, 0, 0 ),
	_pointSize( 1.0 )
{
	// TODO_1: set up begin values
	_triangle.points.resize( 3 );
}

void Primitive::setPoint( const Point & pt, int i )
{
	_triangle.points[i] = pt;
}

const Point & Primitive::point( int i )
{
	return _triangle.points[i];
}

void Primitive::setColor( const Color & clr )
{
	_color = clr;
}

const Color & Primitive::getColor()
{
	return _color;
}

void Primitive::setPointSize( GLfloat pointSize )
{
	_pointSize = pointSize;
}

GLfloat Primitive::pointSize()
{
	return _pointSize;
}

void Primitive::draw()
{
	glColor3ub( _color.r, _color.g, _color.b );
	glBegin( GL_TRIANGLES );
	for ( int i = 0; i < 3; ++i )
		glVertex2i( _triangle.points[i].x, _triangle.points[i].y );
	glEnd();
}
