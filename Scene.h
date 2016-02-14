#pragma once

#include "Primitive.h"

#include <QtWidgets/QOpenGLWidget>

#include <QtGui/QOpenGLFunctions>

class Scene : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
	Scene( QWidget * parent = nullptr );

	void startNewCollection();
	void movePoints( int offset, bool horizontal );

protected:
	void mousePressEvent( QMouseEvent * event ) override;
	void keyPressEvent( QKeyEvent * event )		override;

	void initializeGL()				override;
	void paintGL()					override;
	void resizeGL( int w, int h )	override;

private:
	void addPrimitive();

	std::vector<Collection> _collections;
	Primitive _buildingPrimitive;

	int _pointSet;
	int _lastCollection;
	int _lastPrimitive;
};
