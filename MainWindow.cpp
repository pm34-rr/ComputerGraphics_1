#include "MainWindow.h"

#include "Scene.h"

MainWindow::MainWindow( QWidget * parent ):
	QMainWindow( parent )
{
	_scene = new Scene;

	setCentralWidget( _scene );

	resize( 512, 512 );
}
