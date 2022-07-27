#include<graphics.h>
#include"DrawingBoard.h"
#include"Button.h"

# define BLOCK_BTN_WIDTH (16 * 2)
# define ARROW_WIDTH 22
HWND Win_handle = 0;
MOUSEMSG m; //接收鼠标消息的变量

void init()
{
	int Win_width = 16 * 56; // 窗口真实宽度
	int Win_height = 16 * 34; // 窗口真实高度
	Win_handle = initgraph(Win_width, Win_height);
}

int main()
{
	init();
	SetWindowTextA(Win_handle, "极光立体字符制作工具（Blazing 3D Character maker）V1.3.1");
	DrawingBoard dwb(16 * 5, int(16 * 1), 16 * 24, 16 * 32, 2, true);
	dwb.set_showGrid(true);
	int start_X = int(16 * 0.5);
	int start_Y = int(16 * 0.5);
	int buttonInterval = 16 * 0.5;
	//栅格按钮
	FuntionalButton grid_button(start_X, start_Y, 16 * 4, 16 * 2, '#', 0);
	bool grid_useful = true;
	//清除按钮
	FuntionalButton clear_button(start_X, start_Y + (16 * 2 + buttonInterval) * 1, 16 * 4, 16 * 2, 'x', 0);
	//投影源按钮
	SequentialSelectionalButton origin_button(start_X, start_Y + (16 * 2 + buttonInterval) * 2, 16 * 4, 16 * 2, '&', 0);
	int show_origin = 0;
	//画刷单选按钮

	MultiSelectionlButton brushButton(start_X / 2, start_Y + (16 * 2 + buttonInterval) * 3, 18 * 4, 16 * 8, '#');
	MultiSelectionlButton lightButton(start_X / 2, start_Y + (16 * 2 + buttonInterval) * 3 + 16 * 8 + buttonInterval, 18 * 4, 18 * 6, '*');

	sizeof(DrawingBoard);
	int blockBrushID = 1;
	int lightID = 2;
	bool brushSettings[10] = { false };
	bool lightSettings[10] = { false };

	while (true)
	{
		int X = m.x;
		int Y = m.y;
		if (MouseHit())
		{
			m = GetMouseMsg();
			X = m.x;
			Y = m.y; 
			// 绘图的按钮模块
			dwb.response(m);
			// 栅格按钮
			if (grid_button.response(m))
			{
				grid_useful = !grid_useful;
				dwb.set_showGrid(grid_useful);
			}
			// 清除按钮
			if (clear_button.response(m))
			{
				dwb.clear();
			}
			// 投影源按钮
			if (origin_button.response(m, show_origin))
			{
				dwb.set_showOrigin(show_origin);
			}
			// 光线按钮
			if (lightButton.response(m, lightID, lightSettings))
			{
				dwb.set_projectType(lightID, lightSettings[0]);
			}
			// 画刷按钮
			if (brushButton.response(m, blockBrushID, brushSettings))
			{
				dwb.set_brushType(blockBrushID);
			}
		}
	}
	closegraph();
	return 0;
}
