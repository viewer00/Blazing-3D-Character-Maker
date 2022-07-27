#pragma once
#include<graphics.h>
#include<string>
using namespace std;

class Window
{
public:
	Window();
	Window(int X, int Y, int width, int height, IMAGE* on_where = 0);
	void locate_on(IMAGE* on_where);
	virtual bool mouse_on(int X, int Y);
	virtual bool response(MOUSEMSG m);
	virtual void save_img(wstring name);
	virtual void refresh();
protected:
	IMAGE* on_where;
	bool useful;
	int coordX;
	int coordY;
	int width;
	int height;
};