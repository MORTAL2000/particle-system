#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) : QWidget(parent), ui(new Ui::Window)
{
	ui->setupUi(this);
	setFocusPolicy(Qt::StrongFocus);
}

Window::~Window()
{
	delete ui;
}

void Window::selectEmitterType(int type)
{
	// TODO
	// We're supposed to change the type the emitter here
}

void Window::setVelocity(int velocity)
{

}

void Window::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Escape)
		close();
	else
		app.keyPressEvent(event);
}
