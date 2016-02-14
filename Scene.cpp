#include "Scene.h"

#include <QtGui/QKeyEvent>
#include <QtGui/QMouseEvent>

#include <QtWidgets/QApplication>

Scene::Scene( QWidget * parent ):
	QOpenGLWidget( parent ),
	QOpenGLFunctions(),
	_lastCollection( -1 )
{
	startNewCollection();

	grabKeyboard();
}

void Scene::startNewCollection()
{
	Collection collection;
	collection.color = { 255, 0, 0 };
	_collections.push_back( collection );

	++_lastCollection;
	_lastPrimitive = -1;

	_pointSet = 0;
}

void Scene::movePoints( int offset, bool horizontal )
{

}

void Scene::mousePressEvent( QMouseEvent * event )
{
	if ( event->button() != Qt::LeftButton )
		return;

	Point pt{ event->pos().x(), height() - event->pos().y() };
	_buildingPrimitive.setPoint( pt, _pointSet );
	if ( _pointSet < 2 )
		++_pointSet;
	else {
		addPrimitive();
		_pointSet = 0;
	}
}

void Scene::keyPressEvent( QKeyEvent * event )
{
	int horizontalOffset = 0;
	int verticalOffset = 0;

	switch ( event->key() ) {
	case Qt::Key_Escape:
		qApp->exit( 0 );
		break;
	case Qt::Key_Left:
		horizontalOffset = -10;
		break;
	case Qt::Key_Right:
		horizontalOffset = 10;
		break;
	case Qt::Key_Up:
		verticalOffset = 10;
		break;
	case Qt::Key_Down:
		verticalOffset = -10;
		break;
	case Qt::Key_Space:
		startNewCollection();
		break;
	}

	if ( horizontalOffset != 0 )
		movePoints( horizontalOffset, true );
	else if ( verticalOffset != 0 )
		movePoints( verticalOffset, false );
}

void Scene::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor( 0, 0, 0, 1 );
}

void Scene::paintGL()
{
	glClearColor( 0, 0, 0, 1 );
	glClear( GL_COLOR_BUFFER_BIT );

	int j, nn;
	for ( int i = 0, n = _collections.size(); i < n; ++i ) {
		for ( j = 0, nn = _collections[i].primitives.size(); j < nn; ++j )
			_collections[i].primitives[j].draw();
	}
	glFinish();
}

void Scene::resizeGL( int w, int h )
{
// 	QOpenGLWidget::resizeGL( w, h );

	glViewport( 0, 0, w, h );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	glOrtho( 0, w, 0, h, -1.0,1.0 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void Scene::addPrimitive()
{
	_buildingPrimitive.setColor( _collections.at( _lastCollection ).color );
	_collections.at( _lastCollection ).primitives.push_back( _buildingPrimitive );
	++_lastPrimitive;
	update();
}
