#include "window.h"

Window::Window()
{
	useful = false;
	coordX = 0;
	coordY = 0;
	width = 0;
	height = 0;
	on_where = 0;
}

Window::Window(int X, int Y, int width, int height, IMAGE* on_where)
{
	useful = false;
	coordX = X;
	coordY = Y;
	this->width = width;
	this->height = height;
	this->on_where = on_where;
}

bool Window::mouse_on(int X, int Y)
{
	if (coordX <= X && X <= coordX + width && coordY <= Y && Y <= coordY + height)
		return true;
	else
		return false;
}

void Window::locate_on(IMAGE* on_where)
{
	this->on_where = on_where;
}

void Window::refresh()
{

}

bool Window::response(MOUSEMSG m)
{
	return false;
}

void Window::save_img(wstring name)
{
}