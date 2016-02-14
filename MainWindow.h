#pragma once

#include <QtWidgets/QMainWindow>

class Scene;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow( QWidget * parent = nullptr );

private:
	Scene * _scene;
};
