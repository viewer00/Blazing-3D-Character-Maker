#include "DrawingBoard.h"
#define MAX_WIDTH 64
#define MAX_HEIGHT 64

// 8�ֿ���9������ͶӰ�����䵽��4�������״
__int16 projectMap[8][9][4] = {
	{
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)}
	},
	{
		{Block::mk_slice(0),Block::mk_slice(4),Block::mk_slice(1),Block::mk_slice(7)},
		{Block::mk_slice(0),Block::mk_slice(1),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(5),Block::mk_slice(1),Block::mk_slice(6)},
		{Block::mk_slice(0),Block::mk_slice(1),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(7),Block::mk_slice(1),Block::mk_slice(4)},
		{Block::mk_slice(0),Block::mk_slice(1),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(6),Block::mk_slice(1),Block::mk_slice(5)},
		{Block::mk_slice(0),Block::mk_slice(1),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)}
	},
	{
		{Block::mk_slice(0),Block::mk_slice(4),0b1111111111111001,0b1001000000000000},
		{Block::mk_slice(0),Block::mk_slice(2),Block::mk_slice(0),Block::mk_slice(0)},
		{0b0000000011001111,Block::mk_slice(5),Block::mk_slice(2),0b0000110000000000},
		{Block::mk_slice(3),Block::mk_slice(2),Block::mk_slice(0),Block::mk_slice(0)},
		{0b0000000011111001,0b1001000000000000,Block::mk_slice(2),Block::mk_slice(4)},
		{Block::mk_slice(0),Block::mk_slice(2),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),0b0000110000000000,0b1111111111001111,Block::mk_slice(5)},
		{Block::mk_slice(0),Block::mk_slice(1),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)}
	},
	{
		{0b0110111100000000,0b0000000000000110,Block::mk_slice(3),Block::mk_slice(7)},
		{Block::mk_slice(0),Block::mk_slice(3),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),0b0000000000110000,0b1111001111111111,Block::mk_slice(6)},
		{Block::mk_slice(0),Block::mk_slice(1),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(7),0b0110111111111111,0b0000000000000110},
		{Block::mk_slice(0),Block::mk_slice(3),Block::mk_slice(0),Block::mk_slice(0)},
		{0b1111001100000000,Block::mk_slice(6),Block::mk_slice(3),0b0000000000110000},
		{Block::mk_slice(2),Block::mk_slice(3),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)}
	},
	{
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(4),Block::mk_slice(7)},
		{Block::mk_slice(0),Block::mk_slice(1),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(5),Block::mk_slice(1),Block::mk_slice(6)},
		{Block::mk_slice(0),Block::mk_slice(1),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(7),Block::mk_slice(4),Block::mk_slice(0)},
		{Block::mk_slice(7),Block::mk_slice(4),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(7),Block::mk_slice(6),Block::mk_slice(4),Block::mk_slice(5)},
		{Block::mk_slice(7),Block::mk_slice(4),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)}
	},
	{
		{Block::mk_slice(6),Block::mk_slice(4),Block::mk_slice(5),Block::mk_slice(7)},
		{Block::mk_slice(6),Block::mk_slice(5),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(5),Block::mk_slice(6)},
		{Block::mk_slice(0),Block::mk_slice(1),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(7),Block::mk_slice(1),Block::mk_slice(4)},
		{Block::mk_slice(0),Block::mk_slice(1),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(6),Block::mk_slice(5),Block::mk_slice(0)},
		{Block::mk_slice(6),Block::mk_slice(5),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)}
	},
	{
		{Block::mk_slice(0),Block::mk_slice(4),Block::mk_slice(1),Block::mk_slice(7)},
		{Block::mk_slice(0),Block::mk_slice(1),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(5),Block::mk_slice(6),Block::mk_slice(0)},
		{Block::mk_slice(5),Block::mk_slice(6),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(5),Block::mk_slice(7),Block::mk_slice(6),Block::mk_slice(4)},
		{Block::mk_slice(5),Block::mk_slice(6),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(6),Block::mk_slice(5)},
		{Block::mk_slice(0),Block::mk_slice(1),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)}
	},
	{
		{Block::mk_slice(0),Block::mk_slice(4),Block::mk_slice(7),Block::mk_slice(0)},
		{Block::mk_slice(4),Block::mk_slice(6),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(4),Block::mk_slice(5),Block::mk_slice(7),Block::mk_slice(6)},
		{Block::mk_slice(4),Block::mk_slice(7),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(7),Block::mk_slice(4)},
		{Block::mk_slice(0),Block::mk_slice(1),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(6),Block::mk_slice(1),Block::mk_slice(5)},
		{Block::mk_slice(0),Block::mk_slice(1),Block::mk_slice(0),Block::mk_slice(0)},
		{Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0),Block::mk_slice(0)}
	}
};
// ��9���������ͶӰ��ÿ��������Ӱ��Ŀ��ںδ�
int affection_Map[9][4][2] = {
	{{0, 0}, {0, -1}, {1, -1},{1, 0}},
	{{0, 0}, {1, 0}, {0, 0}, {0, 0}},
	{{0, 0}, {1, 0}, {1, 1}, {0, 1}},
	{{0, 0}, {0, 1}, {0, 0}, {0, 0}},
	{{0, 0}, {0, 1}, {-1, 1}, {-1, 0}},
	{{0, 0}, {-1, 0}, {0, 0}, {0, 0}},
	{{0, 0}, {-1, 0}, {-1, -1}, {0, -1}},
	{{0, 0}, {0, -1}, {0, 0}, {0, 0}},
	{{0, 0}, {0, 0}, {0, 0}, {0, 0}},
};
// 9������,Ӱ�챾��Ŀ��ںδ�
int affection_Origin[9][4][2] = {
	{{0, 0}, {0, 1}, {-1, 1},{-1, 0}},
	{{0, 0}, {-1, 0}, {0, 0}, {0, 0}},
	{{0, 0}, {-1, 0}, {-1, -1}, {0, -1}},
	{{0, 0}, {0, -1}, {0, 0}, {0, 0}},
	{{0, 0}, {0, -1}, {1, -1}, {1, 0}},
	{{0, 0}, {1, 0}, {0, 0}, {0, 0}},
	{{0, 0}, {1, 0}, {1, 1}, {0, 1}},
	{{0, 0}, {0, 1}, {0, 0}, {0, 0}},
	{{0, 0}, {0, 0}, {0, 0}, {0, 0}},
};
int affection_All[9][2] = { {-1, -1}, {0, -1}, {1, -1},{-1, 0},{0, 0},{1, 0},{-1, 1},{0, 1},{1, 1} };

int affention_length[9] = { 4,2,4,2,4,2,4,2,1 };
//����8�Ź��ղ���Ͷ���κ���Ӱ�����������������ƣ����ٿ���1�����ӵĻ��ơ�
COLORREF color_list[4] = { LIGHTGRAY, BLACK, RED, LIGHTGRAY };
DrawingBoard::DrawingBoard(int X, int Y, int width, int height, int projectType, bool show_origin, IMAGE* on_where)
	:Window(X, Y,width, height, on_where)
{
	brushType = 1;
	BlockArray = new Block*[MAX_HEIGHT];
	ShadowArray = new Block * [MAX_HEIGHT];
	WarningArray = new Block * [MAX_HEIGHT];
	for (int i = 0; i < MAX_HEIGHT; ++i)
	{
		BlockArray[i] = new Block[MAX_WIDTH];
		ShadowArray[i] = new Block[MAX_WIDTH];
		WarningArray[i] = new Block[MAX_WIDTH];
	}
	globalProjectType_useful = false;
	shadow_alphaX = 32;
	shadow_alphaY = 0;
	blockWidth = 16;

	coordX = X;
	coordY = Y;
	linestyle = PS_DASH;
	this->width = width;
	this->height = height;
	this->show_origin = show_origin;
	this->projectType = projectType;

	img_in = IMAGE(width, height);
	img_out = IMAGE(width, height);
	SetWorkingImage(&img_in);
	setbkcolor(WHITE);
	setfillcolor(LIGHTGRAY);
	clearrectangle(0, 0, width, height);
	SetWorkingImage(&img_out);
	setbkcolor(WHITE);
	clearrectangle(0, 0, width, height);

	alphaX = blockWidth * MAX_WIDTH / 2 - width / blockWidth;
	alphaY = blockWidth * MAX_HEIGHT / 2 - height / blockWidth;

	refresh();
}

bool DrawingBoard::response(MOUSEMSG m)
{
	if (mouse_on(m.x, m.y))
	{

		if (m.uMsg == WM_LBUTTONDOWN)
		{
			useful = true;
			int x = (m.x - coordX + alphaX) / blockWidth;
			int y = (m.y - coordY + alphaY) / blockWidth;
			paint(x, y);
			return true;
		}
		else if (m.mkLButton && useful)
		{
			int x = (m.x - coordX + alphaX) / blockWidth;
			int y = (m.y - coordY + alphaY) / blockWidth;
			paint(x, y);
			return true;
		}
		else if (m.uMsg == WM_LBUTTONUP)
		{
			useful = false;
			return false;
		}
	}
	else
	{
		useful = false;
		return false;
	}
	return false;
}

void DrawingBoard::set_brushType(int brushType)
{
	this->brushType = brushType;
}

void DrawingBoard::XY2xy(int X, int Y, int & x, int & y)
{
	x = (X - coordX + alphaX) / blockWidth;
	y = (Y - coordY + alphaY) / blockWidth;
}

void DrawingBoard::set_showGrid(bool actived, int linestyle)
{
	//�趨�Ƿ���ʾ����
	if (show_grid != actived)
	{
		show_grid = actived;
		if (actived)
			draw_grid();
		else
			redraw();
	}
}

void DrawingBoard::set_showOrigin(bool actived)
{
	// �趨�Ƿ�����ͶӰԴ��ʾ����Ӱ���Ļ���ϡ�
	if (show_origin != actived)
	{
		show_origin = actived;
		redraw();
	}
}

void DrawingBoard::refresh()
{
	//������ͼͶ�䵽������
	int x2 = coordX + width + shadow_alphaX;
	int y2 = coordY + shadow_alphaY;
	SetWorkingImage();
	putimage(coordX, coordY, &img_in);
	putimage(x2, y2, &img_out);
}

void DrawingBoard::draw_grid()
{
	int X_start = alphaX % blockWidth;
	int Y_start = alphaY % blockWidth;

	SetWorkingImage(&img_in);
	setlinestyle(linestyle);
	setlinecolor(LIGHTGRAY);
	for (int i = 0; i < MAX_WIDTH; ++i)
	{
		line(X_start + i * blockWidth, 0, X_start + i * blockWidth, height);
		line(0, Y_start + i * blockWidth, width, Y_start + i * blockWidth);
	}

	SetWorkingImage(&img_out);
	setlinestyle(linestyle);
	setlinecolor(LIGHTGRAY);
	for (int i = 0; i < MAX_WIDTH; ++i)
	{
		line(X_start + i * blockWidth, 0, X_start + i * blockWidth, height);
		line(0, Y_start + i * blockWidth, width, Y_start + i * blockWidth);
	}

	refresh();
}

void DrawingBoard::set_projectType(int blk_type, bool global)
{
	// ͶӰ����ı䣬����ȫ�ְ�ť����Ż��������輰�ػ�
	if (globalProjectType_useful != global || projectType != blk_type)
	{
		projectType = blk_type;
		globalProjectType_useful = global;
		SetWorkingImage(&img_out);
		clearrectangle(0, 0, width, height);
		for (int y = 0; y < MAX_HEIGHT; ++y)
			for (int x = 0; x < MAX_WIDTH; ++x)
				ShadowArray[y][x] = Block(0);
		int min_y = alphaY / blockWidth - 1;
		int max_y = (alphaY + height) / blockWidth + 1;
		int min_x = alphaX / blockWidth - 1;
		int max_x = (alphaX + width) / blockWidth + 1;
		if (min_y < 0) min_y = 0;
		if (min_x < 0) min_x = 0;
		if (max_y >= MAX_HEIGHT) max_y = MAX_HEIGHT - 1;
		if (max_x >= MAX_WIDTH) max_x = MAX_WIDTH - 1;

		for (int y = min_y; y <= max_y; ++y)
			for (int x = min_x; x <= max_x; ++x)
				draw_shadow(x, y);

		if (show_grid)
			draw_grid();
		else
			refresh();
	}
}

void DrawingBoard::redraw()
{
	// �ػ�ͼ���������¼�����Ӱ
	// �������դ����ػ�
	int min_y = alphaY / blockWidth - 1;
	int max_y = (alphaY + height) / blockWidth + 1;
	int min_x = alphaX / blockWidth - 1;
	int max_x = (alphaX + width) / blockWidth + 1;
	if (min_y < 0) min_y = 0;
	if (min_x < 0) min_x = 0;
	if (max_y >= MAX_HEIGHT) max_y = MAX_HEIGHT - 1;
	if (max_x >= MAX_WIDTH) max_x = MAX_WIDTH - 1;

	SetWorkingImage(&img_in);
	clearrectangle(0, 0, width, height);
	SetWorkingImage(&img_out);
	clearrectangle(0, 0, width, height);

	for (int y = min_y; y <= max_y; ++y)
		for (int x = min_x; x <= max_x; ++x)
		{
			draw_block(x, y, 0);
			int type = ShadowArray[y][x].get_type();
			if(type == -1)
				draw_block(x, y, 2);
			else
				draw_block(x, y, 1);
		}
	refresh();
}

void DrawingBoard::clear()
{
	SetWorkingImage(&img_in);
	clearrectangle(0, 0, width, height);
	SetWorkingImage(&img_out);
	clearrectangle(0, 0, width, height);


	for (int y = 0; y < MAX_HEIGHT; ++y)
		for (int x = 0; x < MAX_WIDTH; ++x)
		{
			BlockArray[y][x] = Block(0);
			ShadowArray[y][x] = Block(0);
		}

	if (show_grid)
		draw_grid();
	else
		refresh();
}

void DrawingBoard::paint(int x, int y)
{
	// �û�ˢ��һ�����ƣ������±�������Ŀ顣
	int old_type = BlockArray[y][x].get_type();
	int old_blk_projectType = BlockArray[y][x].get_projectType();
	// ͶӰ����ͬ�����߿�����Ͳ�һ�������б�Ҫ��
	if (projectType != old_blk_projectType || old_type != brushType)
	{
		// �ɿ鲻Ϊ�գ���Ҫ����������޸���Ӱ��Ŀ顣
		if (old_type != 0)
		{
			remove(x, y);
		}
		BlockArray[y][x] = Block(brushType, projectType);
		draw_block(x, y, 0);
		draw_shadow(x, y);
		refresh();
	}
}

void DrawingBoard::draw_shadow(int x, int y)
{
	// �����ǻ�ͼ�����漰���
	int blk_type = BlockArray[y][x].get_type();
	int projectType_ = globalProjectType_useful ? projectType: BlockArray[y][x].get_projectType();
	for (int i = 0; i < affention_length[projectType_]; ++i)
	{
		int x_ = x + affection_Map[projectType_][i][0];
		int y_ = y + affection_Map[projectType_][i][1];
		__int16 slices = projectMap[blk_type][projectType_][i];
		//��ֹ��Ӱ����
		if (0 <= x_ && x_ < MAX_WIDTH && 0 <= y_ && y_ < MAX_HEIGHT)
		{
			__int16 overlap_error1 = ShadowArray[y_][x_] + slices;
			__int16 overlap_error2 = ShadowArray[y_][x_] - BlockArray[y_][x_];
			if (ShadowArray[y_][x_].get_type() == -1)
				draw_block(x_, y_, 2);
			else
				draw_block(x_, y_, 1);
		}
	}
}

void DrawingBoard::rebuild_block(int x, int y)
{
	// ����ͶӰԴ���ػ汾���ͶӰ��������Ӱ��Դ�����ı��
	// ֻ���㣬������
	Block result = Block(0, projectType);
	if (globalProjectType_useful)
	{
		// ͶӰ����ȫ����Ч��ͶӰԴ��ȷ���ˣ�
		for (int i = 0; i < 4; ++i)
		{
			int x_ = x + affection_Origin[projectType][i][0];
			int y_ = y + affection_Origin[projectType][i][1];
			int ori_blk_type = BlockArray[y_][x_].get_type();
			int ori_blk_projectType = BlockArray[y_][x_].get_projectType();
			__int16 slices = projectMap[ori_blk_type][ori_blk_projectType][i];
			result + slices;
		}
		ShadowArray[y][x] = result;
	}
	else
	{
		// ͶӰ�����ȫ����Ч��Ҫ�ӾŸ�����Ѱ��
		for (int i = 0; i < 9; ++i)
		{
			int x_ = x + affection_All[i][0];
			int y_ = y + affection_All[i][1];
			int ori_blk_type = BlockArray[y_][x_].get_type();
			int ori_blk_projectType = BlockArray[y_][x_].get_projectType();
			int alpha_x = x - x_;
			int alpha_y = y - y_;
			int j = 0;
			for (; j < 4; ++j)
			{
				// ��鱾���ڲ���ͶӰԴ�ķ��䷶Χ��
				if (alpha_x == affection_Map[ori_blk_projectType][j][0] && alpha_y == affection_Map[ori_blk_projectType][j][1])
					break;
			}
			if (j != 4)
			{
				// ����ζ��ͶӰԴ����䵽��ǰ�飬���������ɺ�j==4
				__int16 slices = projectMap[ori_blk_type][ori_blk_projectType][j];
				result + slices;
			}
		}
		ShadowArray[y][x] = result;
	}
}

void DrawingBoard::remove(int x, int y)
{
	// �Ƴ�һ���飬���ؽ�������Ӱ��Ŀ顣
	// ȷ��������������ķ��򣬷����Ժ�������������
	int projectType_ = globalProjectType_useful?projectType:BlockArray[y][x].get_projectType();
	// ��ձ��飬ʹ���������Ӱ����ʧ��
	BlockArray[y][x] = Block(0,projectType);
	// �����ܱߵĿ飬���¼��㱾�顢���ܱ���Ӱ���3����
	for (int i = 0; i < 4; ++i)
	{
		int x_ = x + affection_Map[projectType_][i][0];
		int y_ = y + affection_Map[projectType_][i][1];
		rebuild_block(x_, y_);
		draw_shadow(x_, y_);
	}
}

void DrawingBoard::draw_block(int x, int y, int mode)
{
	// �����Ļ��飬���漰�����ϡ�
	int X = x * blockWidth - alphaX;
	int Y = y * blockWidth - alphaY;
	POINT triangle_points[4][3] = {
		{ {X + blockWidth, Y}, {X + blockWidth, Y + blockWidth}, {X, Y + blockWidth}},
		{ {X, Y}, {X + blockWidth, Y + blockWidth}, {X, Y + blockWidth} },
		{ {X, Y}, {X + blockWidth, Y}, {X + blockWidth, Y + blockWidth} },
		{ {X, Y}, {X + blockWidth, Y}, {X, Y + blockWidth} }

	};
	Block blk;
	switch (mode)
	{
		case 0: {
			SetWorkingImage(&img_in);
			blk = BlockArray[y][x]; 
			clearrectangle(X, Y, X + blockWidth - 1, Y + blockWidth - 1);
			break;
		}
		case 1: {
			SetWorkingImage(&img_out); 
			blk = ShadowArray[y][x];
			clearrectangle(X, Y, X + blockWidth - 1, Y + blockWidth - 1); 
			break;
		}
		case 2: {
			SetWorkingImage(&img_out);
			blk = ShadowArray[y][x];
			clearrectangle(X, Y, X + blockWidth - 1, Y + blockWidth - 1);
			break;
		}
	}
	// ��ɫһ��Ҫ���趨����ͼ֮����У�ÿ������ͼ�������Լ��Ĺ�����ɫ��
	COLORREF new_color = color_list[mode];
	setfillcolor(new_color);

	switch (blk.get_type())
	{
	case 1: solidrectangle(X, Y, X + blockWidth - 1, Y + blockWidth - 1); break;
	case 2: solidrectangle(X, Y, X + blockWidth - 1, Y + int(blockWidth * 0.5) - 1); break;
	case 3: solidrectangle(X, Y + int(blockWidth * 0.5), X + blockWidth - 1, Y + blockWidth - 1); break;
	case 4: solidpolygon(triangle_points[0], 3); break;
	case 5: solidpolygon(triangle_points[1], 3); break;
	case 6: solidpolygon(triangle_points[2], 3); break;
	case 7: solidpolygon(triangle_points[3], 3); break;
	}

	// ���ͼ���ǻ���ͼ��
	if (blk.get_type() == -1)
	{
		int wd100 = blockWidth;
		int wd025 = int(blockWidth * 0.25);
		int wd050 = int(blockWidth * 0.50);
		int wd075 = int(blockWidth * 0.75);
		__int16 slice = blk.get_slice();

		POINT slices_points[16][3] =
		{
			{{X, Y},{X + wd050, Y}, {X + wd025, Y + wd025} },
			{{X + wd050, Y}, {X + wd025, Y + wd025}, {X + wd050, Y + wd050} },
			{{X + wd025, Y + wd025}, {X + wd050, Y + wd050}, {X, Y + wd050} },
			{{X + wd025, Y + wd025}, {X, Y + wd050}, {X, Y} },

			{{X + wd050, Y},{X + wd100, Y}, {X + wd075, Y + wd025} },
			{{X + wd100, Y}, {X + wd075, Y + wd025}, {X + wd100, Y + wd050} },
			{{X + wd075, Y + wd025}, {X + wd100, Y + wd050}, {X + wd050, Y + wd050} },
			{{X + wd075, Y + wd025}, {X + wd050, Y + wd050}, {X + wd050, Y} },

			{{X, Y + wd050},{X + wd050, Y + wd050}, {X + wd025, Y + wd075} },
			{{X + wd050, Y + wd050}, {X + wd025, Y + wd075}, {X + wd050, Y + wd100} },
			{{X + wd025, Y + wd075}, {X + wd050, Y + wd100}, {X, Y + wd100} },
			{{X + wd025, Y + wd075}, {X, Y + wd100}, {X, Y + wd050} },

			{{X + wd050, Y + wd050}, {X + wd100, Y + wd050}, {X + wd075, Y + wd075} },
			{{X + wd100, Y + wd050}, {X + wd075, Y + wd075}, {X + wd100, Y + wd100} },
			{{X + wd075, Y + wd075}, {X + wd100, Y + wd100}, {X + wd050, Y + wd100} },
			{{X + wd075, Y + wd075}, {X + wd050, Y + wd100}, {X + wd050, Y + wd050} }
		};

		unsigned __int16 index = 0b1000000000000000;
		int count = 0;
		while (index != 0) 
		{
			if (slice & index)
				solidpolygon(slices_points[count], 3);
			index = index >> 1;
			count += 1;
		}
	}
	if (show_origin && mode > 0)
	{
		setfillcolor(color_list[0]);
		switch (BlockArray[y][x].get_type())
		{
		case 1: solidrectangle(X, Y, X + blockWidth - 1, Y + blockWidth - 1); break;
		case 2: solidrectangle(X, Y, X + blockWidth - 1, Y + int(blockWidth * 0.5) - 1); break;
		case 3: solidrectangle(X, Y + int(blockWidth * 0.5), X + blockWidth - 1, Y + blockWidth - 1); break;
		case 4: solidpolygon(triangle_points[0], 3); break;
		case 5: solidpolygon(triangle_points[1], 3); break;
		case 6: solidpolygon(triangle_points[2], 3); break;
		case 7: solidpolygon(triangle_points[3], 3); break;
		}
	}
	if (show_grid)
	{
		setlinestyle(PS_DASH);
		setlinecolor(LIGHTGRAY);
		line(X, Y, X + blockWidth, Y);
		line(X, Y, X, Y + blockWidth);
	}
}


void DrawingBoard::zoom(int multiple)
{
	int new_blockWidth = blockWidth + 4 * multiple;
	if (new_blockWidth < 8)
		new_blockWidth = 8;

	blockWidth = new_blockWidth;
	alphaX = int(alphaX * double(blockWidth) / double(blockWidth));
	alphaY = int(alphaX * double(blockWidth) / double(blockWidth));
}
