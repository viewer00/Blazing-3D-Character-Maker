#include<graphics.h>
#include"DrawingBoard.h"
#include"Button.h"

# define BLOCK_BTN_WIDTH (16 * 2)
# define ARROW_WIDTH 22
HWND Win_handle = 0;
MOUSEMSG m; //���������Ϣ�ı���

void init()
{
	int Win_width = 16 * 56; // ������ʵ���
	int Win_height = 16 * 34; // ������ʵ�߶�
	Win_handle = initgraph(Win_width, Win_height);
}

int main()
{
	init();
	SetWindowTextA(Win_handle, "�����ֿ����ɹ��ߣ�Blazing Character maker��V1.31");
	DrawingBoard dwb(16 * 5, int(16 * 1), 16 * 24, 16 * 32, 2, true);
	dwb.set_showGrid(true);
	int start_X = int(16 * 0.5);
	int start_Y = int(16 * 0.5);
	int buttonInterval = 16 * 0.5;
	//դ��ť
	FuntionalButton grid_button(start_X, start_Y, 16 * 4, 16 * 2, '#', 0);
	bool grid_useful = true;
	//�����ť
	FuntionalButton clear_button(start_X, start_Y + (16 * 2 + buttonInterval) * 1, 16 * 4, 16 * 2, 'x', 0);
	//ͶӰԴ��ť
	SequentialSelectionalButton origin_button(start_X, start_Y + (16 * 2 + buttonInterval) * 2, 16 * 4, 16 * 2, '&', 0);
	int show_origin = 0;
	//��ˢ��ѡ��ť

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
			// ��ͼ�İ�ťģ��
			dwb.response(m);
			// դ��ť
			if (grid_button.response(m))
			{
				grid_useful = !grid_useful;
				dwb.set_showGrid(grid_useful);
			}
			// �����ť
			if (clear_button.response(m))
			{
				dwb.clear();
			}
			// ͶӰԴ��ť
			if (origin_button.response(m, show_origin))
			{
				dwb.set_showOrigin(show_origin);
			}
			// ���߰�ť
			if (lightButton.response(m, lightID, lightSettings))
			{
				dwb.set_projectType(lightID, lightSettings[0]);
			}
			// ��ˢ��ť
			if (brushButton.response(m, blockBrushID, brushSettings))
			{
				dwb.set_brushType(blockBrushID);
			}
		}
	}
	closegraph();
	return 0;
}