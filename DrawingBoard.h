#pragma once
#include"window.h"
#include"Block.h"
#include<graphics.h>

class DrawingBoard :public Window
{
public:
	// 还没有拷贝构造函数
	DrawingBoard(int X, int Y, int width, int height, int projectType = 2, bool show_origin = false, IMAGE* on_where = 0);
	bool response(MOUSEMSG m);
	void zoom(int multiple);

	void set_showGrid(bool actived, int linestyle = PS_DASH);
	void set_showOrigin(bool actived);
	void clear();
	void set_brushType(int brushType);
	void set_projectType(int pro_type, bool globa = true);

protected:
	void XY2xy(int X, int Y, int& x, int& y);

	bool show_grid;
	bool show_origin;
	int projectType;
	bool globalProjectType_useful;

	int blockWidth;
	int shadow_alphaX;
	int shadow_alphaY;
	int alphaX;
	int alphaY;
	int brushType;
private:
	void redraw();
	void paint(int x, int y);
	void draw_grid();
	void draw_shadow(int x, int y);
	void remove(int x, int y);
	void draw_block(int x, int y, int mode);
	void rebuild_block(int x, int y);
	void refresh();
	int linestyle;
	IMAGE img_in;
	IMAGE img_out;
	Block** BlockArray;
	Block** ShadowArray;
	Block** WarningArray;
};