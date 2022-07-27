#include "Button.h"

#define SELECTED true
#define COMMON false

#define MIDGRAY 0x888888

#define NULL_BTN -1
#define BLOCK_0 0
#define BLOCK_1 1
#define BLOCK_2 2
#define BLOCK_3 3
#define BLOCK_4 4
#define BLOCK_5 5
#define BLOCK_6 6
#define BLOCK_7 7

#define LIGHT_0 10
#define LIGHT_1 11
#define LIGHT_2 12
#define LIGHT_3 13
#define LIGHT_4 14
#define LIGHT_5 15
#define LIGHT_6 16
#define LIGHT_7 17
#define LIGHT_8 18

char position2id[3][3] = {
	{6, 7, 0},
	{5, 8, 1},
	{4, 3, 2}
};

FuntionalButton::FuntionalButton()
	:Window()
{
	stateIndex = COMMON;
}

FuntionalButton::FuntionalButton(int X, int Y, int width, int height, char kind, IMAGE* on_where)
	:Window(X, Y, width, height, on_where)
{
	stateIndex = COMMON;
	commonButton.Resize(width, height);
	selectedButton.Resize(width, height);
	int width0150 = int(width * 0.15);
	int width0200 = int(width * 0.2);
	int width0300 = int(width * 0.3);
	int width0500 = int(width * 0.5);
	int width0700 = int(width * 0.7);
	int width0800 = int(width * 0.8);
	int width0850 = int(width * 0.85);

	int height0150 = int(height * 0.15);
	int height0200 = int(height * 0.2);
	int height0800 = int(height * 0.8);
	int height0850 = int(height * 0.85);

	POINT frame_size[2] = { {0, 0}, {width - 1, height - 1 } };
	POINT core_size[2] = { {frame_size[0].x + 4, frame_size[0].y + 4}, {frame_size[1].x - 4,frame_size[1].y - 4 } };
	if (kind == '#')
	{
		SetWorkingImage(&commonButton);

		setfillcolor(DARKGRAY);
		solidroundrect(frame_size[0].x, frame_size[0].y, frame_size[1].x, frame_size[1].y, 4, 4);
		setfillcolor(WHITE);
		solidroundrect(core_size[0].x, core_size[0].y, core_size[1].x, core_size[1].y, 2, 2);

		setlinecolor(LIGHTGRAY);
		setlinestyle(PS_SOLID, 2);
		for (int i = core_size[0].x + 8; i <= core_size[1].x; i += 8)
			line(i, core_size[0].y, i, core_size[1].y);
		for (int i = core_size[0].y + 8; i <= core_size[1].y; i += 8)
			line(core_size[0].x, i, core_size[1].x, i);

		SetWorkingImage(&selectedButton);

		setfillcolor(LIGHTGRAY);
		solidroundrect(frame_size[0].x, frame_size[0].y, frame_size[1].x, frame_size[1].y, 4, 4);
		setfillcolor(WHITE);
		solidroundrect(core_size[0].x, core_size[0].y, core_size[1].x, core_size[1].y, 2, 2);

		setlinecolor(LIGHTGRAY);
		setlinestyle(PS_SOLID, 2);
		for (int i = core_size[0].x + 8; i <= core_size[1].x; i += 8)
			line(i, core_size[0].y, i, core_size[1].y);
		for (int i = core_size[0].y + 8; i <= core_size[1].y; i += 8)
			line(core_size[0].x, i, core_size[1].x, i);
	}
	else if (kind == 'x')
	{
		SetWorkingImage(&commonButton);
		setfillcolor(DARKGRAY);
		solidroundrect(frame_size[0].x, frame_size[0].y, frame_size[1].x, frame_size[1].y, 4, 4);
		setfillcolor(WHITE);
		solidroundrect(core_size[0].x, core_size[0].y, core_size[1].x, core_size[1].y, 2, 2);
		setlinecolor(RED);
		setlinestyle(PS_SOLID, 4);
		line(width0300, height0150, width0700, height0850);
		line(width0300, height0850, width0700, height0150);

		SetWorkingImage(&selectedButton);
		setfillcolor(LIGHTGRAY);
		solidroundrect(frame_size[0].x, frame_size[0].y, frame_size[1].x, frame_size[1].y, 4, 4);
		setfillcolor(WHITE);
		solidroundrect(core_size[0].x, core_size[0].y, core_size[1].x, core_size[1].y, 2, 2);
		setlinecolor(RED);//用于画叉
		setlinestyle(PS_SOLID, 4);
		line(width0300, height0150, width0700, height0850);
		line(width0300, height0850, width0700, height0150);
	}
	refresh();
}

bool FuntionalButton::response(MOUSEMSG m)
{
	if (mouse_on(m.x, m.y))
	{
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			useful = true;
			set_state(SELECTED);
			return false;
		}
		else if (m.uMsg == WM_LBUTTONUP && useful)
		{
			useful = false;
			set_state(COMMON);
			return true;
		}
		return false;
	}
	else
	{
		useful = false;
		set_state(COMMON);
		return false;
	}
}

void FuntionalButton::save_img(wstring name)
{
	wstring name1 = name + L"_common.png";
	wstring name2 = name + L"_selected.png";
	saveimage(name1.c_str(), &commonButton);
	saveimage(name2.c_str(), &selectedButton);
}

void FuntionalButton::load_commonButton(IMAGE img)
{
	delete& commonButton;
	commonButton = img;
	if(stateIndex = COMMON)
		refresh();
}

void FuntionalButton::load_selectedButton(IMAGE img)
{
	delete& selectedButton;
	selectedButton = img;
	if (stateIndex = SELECTED)
		refresh();
}

void FuntionalButton::set_state(bool state)
{
	if (stateIndex != state)
	{
		stateIndex = state;
		refresh();
	}
}

void FuntionalButton::refresh()
{
	IMAGE* wkimg = GetWorkingImage();
	SetWorkingImage(on_where);
	if (stateIndex == COMMON)
		putimage(coordX, coordY, &commonButton);
	else
		putimage(coordX, coordY, &selectedButton);
	SetWorkingImage(wkimg);
}


Selection::Selection()
	:Window()
{
	meaning = -1;
	stateIndex = COMMON;
}

Selection::Selection(int X, int Y, int width, int height, char kind, IMAGE* on_where)
	:Window(X, Y, width, height, on_where)
{
	meaning = -1;
	stateIndex = COMMON;
	commonButton.Resize(width, height);
	selectedButton.Resize(width, height);
	// 可能有问题

	if (0 <= kind && kind <= 9)
	{
		meaning = kind - BLOCK_0;
		POINT frame_size[2] = { {0, 0}, {width - 1, height - 1 } };
		int line_width = min(width, height) / 8;
		POINT core_size[2] = {
			{frame_size[0].x + line_width, frame_size[0].y + line_width},
			{frame_size[1].x - line_width,frame_size[1].y - line_width }
		};
		POINT triange_size[2] = {
			{frame_size[0].x + line_width, frame_size[0].y + line_width},
			{frame_size[1].x - (line_width - 1),frame_size[1].y - (line_width - 1) }
		};
		POINT triangle_points[4][3] = {
		{ {triange_size[1].x, triange_size[0].y}, {triange_size[1].x, triange_size[1].y}, {triange_size[0].x, triange_size[1].y}},
		{ {triange_size[0].x, triange_size[0].y}, {triange_size[1].x, triange_size[1].y}, {triange_size[0].x, triange_size[1].y}},
		{ {triange_size[0].x, triange_size[0].y}, {triange_size[1].x, triange_size[0].y}, {triange_size[1].x, triange_size[1].y}},
		{ {triange_size[0].x, triange_size[0].y}, {triange_size[1].x, triange_size[0].y}, {triange_size[0].x, triange_size[1].y}}
		};
		int core_mid_height = core_size[0].y + (core_size[1].y - core_size[0].y) / 2;

		SetWorkingImage(&commonButton);
		setfillcolor(DARKGRAY); // 不选时，选框颜色
		solidroundrect(frame_size[0].x, frame_size[0].y, frame_size[1].x, frame_size[1].y, 4, 4);
		setfillcolor(WHITE);
		solidrectangle(core_size[0].x, core_size[0].y, core_size[1].x, core_size[1].y);

		setfillcolor(LIGHTGRAY);
		switch (kind)
		{
		case BLOCK_1: solidrectangle(core_size[0].x, core_size[0].y, core_size[1].x, core_size[1].y); break;
		case BLOCK_2: solidrectangle(core_size[0].x, core_size[0].y, core_size[1].x, core_mid_height); break;
		case BLOCK_3: solidrectangle(core_size[0].x, core_mid_height + 1, core_size[1].x, core_size[1].y); break;
		case BLOCK_4: solidpolygon(triangle_points[0], 3); break;
		case BLOCK_5: solidpolygon(triangle_points[1], 3); break;
		case BLOCK_6: solidpolygon(triangle_points[2], 3); break;
		case BLOCK_7: solidpolygon(triangle_points[3], 3); break;
		}
		SetWorkingImage(&selectedButton);
		setfillcolor(LIGHTGRAY); // 选中时，选框颜色
		solidroundrect(frame_size[0].x, frame_size[0].y, frame_size[1].x, frame_size[1].y, 4, 4);
		setfillcolor(WHITE);
		solidrectangle(core_size[0].x, core_size[0].y, core_size[1].x, core_size[1].y);

		setfillcolor(MIDGRAY);
		switch (kind)
		{
		case BLOCK_1: solidrectangle(core_size[0].x, core_size[0].y, core_size[1].x, core_size[1].y); break;
		case BLOCK_2: solidrectangle(core_size[0].x, core_size[0].y, core_size[1].x, core_mid_height); break;
		case BLOCK_3: solidrectangle(core_size[0].x, core_mid_height + 1, core_size[1].x, core_size[1].y); break;
		case BLOCK_4: solidpolygon(triangle_points[0], 3); break;
		case BLOCK_5: solidpolygon(triangle_points[1], 3); break;
		case BLOCK_6: solidpolygon(triangle_points[2], 3); break;
		case BLOCK_7: solidpolygon(triangle_points[3], 3); break;
		}
	}
	else if (10 <= kind && kind <= 19)
	{
		meaning = kind - LIGHT_0;
		POINT frame_size[2] = { {0, 0}, {width, height} };
		int wid030 = width * 0.3, wid040 = width * 0.4, wid050 = width * 0.5, wid060 = width * 0.6, wid070 = width * 0.7;
		int hig030 = height * 0.3, hig040 = height * 0.4, hig050 = height * 0.5, hig060 = height * 0.6, hig070 = height * 0.7;
		POINT triangle_points[9][4] = {
		{ {wid060, 0}, {width, 0}, {width, hig040}, {0, height}},
		{ {wid060, hig030}, {width, hig050}, {wid060, hig070}, {0, hig050}},
		{ {width, hig060}, {width, height}, {wid060, height}, {0, 0}},
		{ {wid070, hig060}, {wid050, height}, {wid030, hig060}, {wid050, 0}},
		{ {wid040, height}, {0, height}, {0, hig060}, {width, 0}},
		{ {wid040, height * 0.7}, {0, hig050}, {wid040, hig030}, {width, hig050}},
		{ {0, hig040}, {0, 0}, {wid040 , 0}, {width, height}},
		{ {wid030, hig040}, {wid050, 0}, {wid070, hig040}, {wid050, height}},
		{ {0, 0}, {0, 0}, {0, 0}, {0, 0}}
		};

		SetWorkingImage(&commonButton);
		setfillcolor(DARKGRAY);
		solidpolygon(triangle_points[kind-LIGHT_0], 4);
		if (kind == LIGHT_8)
			solidellipse(width / 4, height / 4, int(width * 0.75), int(height * 0.75));

		SetWorkingImage(&selectedButton);
		setfillcolor(WHITE);
		solidpolygon(triangle_points[kind - LIGHT_0], 4);
		if (kind == LIGHT_8)
			solidellipse(width / 4, height / 4, int(width * 0.75), int(height * 0.75));
	}
	refresh();
}


bool Selection::response(MOUSEMSG m, int& selectionID)
{
	if (mouse_on(m.x, m.y))
	{
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			useful = true;
			return false;
		}
		else if (m.uMsg == WM_LBUTTONUP && useful)
		{
			useful = false;
			set_state(SELECTED);
			selectionID = meaning;
			return true;
		}
	}
	else
	{
		useful = false;
		return false;
	}
	return false;
}

void Selection::load_commonButton(IMAGE img)
{
	delete& commonButton;
	commonButton = img;
	if (stateIndex = COMMON)
		refresh();
}

void Selection::load_selectedButton(IMAGE img)
{
	delete& selectedButton;
	selectedButton = img;
	if (stateIndex = SELECTED)
		refresh();
}

void Selection::save_img(wstring name)
{
	wstring name1 = name + L"_common.png";
	wstring name2 = name + L"_selected.png";
	saveimage(name1.c_str(), &commonButton);
	saveimage(name2.c_str(), &selectedButton);
}

void Selection::set_state(bool state)
{
	if (stateIndex != state)
	{
		stateIndex = state;
		refresh();
	}
}

void Selection::refresh()
{
	IMAGE* wkimg = GetWorkingImage();
	SetWorkingImage(on_where);
	if (stateIndex == COMMON)
		putimage(coordX, coordY, &commonButton);
	else
		putimage(coordX, coordY, &selectedButton);
	SetWorkingImage(wkimg);
}



SequentialSelectionalButton::SequentialSelectionalButton()
	:Window()
{
	num_states = 0;
	stateIndex = 0;
	stateImages = 0;
}

SequentialSelectionalButton::SequentialSelectionalButton(const SequentialSelectionalButton& another) :Window(another)
{
	num_states = another.num_states;
	stateIndex = another.stateIndex;
	if (stateImages)
	{
		delete[] stateImages;
		stateImages = 0;
	}
	if (num_states > 0)
	{
		stateImages = new IMAGE[num_states];
		for (int i = 0; i < num_states; ++i)
			stateImages[i] = another.stateImages[i];
	}
}

SequentialSelectionalButton& SequentialSelectionalButton::operator=(const SequentialSelectionalButton & another)
{
	if (this == &another) return *this;
	coordX = another.coordX;
	coordY = another.coordY;
	width = another.width;
	height = another.height;
	on_where = another.on_where;

	num_states = another.num_states;
	stateIndex = another.stateIndex;
	if (stateImages)
	{
		delete[] stateImages;
		stateImages = 0;
	}
	if (num_states > 0)
	{
		stateImages = new IMAGE[num_states];
		for (int i = 0; i < num_states; ++i)
			stateImages[i] = another.stateImages[i];
	}
	return *this;
}

SequentialSelectionalButton::SequentialSelectionalButton(int X, int Y, int width, int height, char kind, IMAGE* on_where)
	:Window(X, Y, width, height, on_where)
{
	stateIndex = 0;
	num_states = 2;
	stateImages = new IMAGE[num_states];
	stateImages[0].Resize(width, height);
	stateImages[1].Resize(width, height);

	int width0150 = int(width * 0.15);
	int width0200 = int(width * 0.2);
	int width0300 = int(width * 0.3);
	int width0500 = int(width * 0.5);
	int width0700 = int(width * 0.7);
	int width0800 = int(width * 0.8);
	int width0850 = int(width * 0.85);

	int height0150 = int(height * 0.15);
	int height0200 = int(height * 0.2);
	int height0800 = int(height * 0.8);
	int height0850 = int(height * 0.85);
	POINT frame_size[2] = { {0, 0}, {width - 1, height - 1 } };
	POINT core_size[2] = { {frame_size[0].x + 4, frame_size[0].y + 4}, {frame_size[1].x - 4,frame_size[1].y - 4 } };

	if(kind == '&')
	{
		stateIndex = 1;
		int shadow_len = 6;
		int block_len = 12;
		POINT L_block_LT = { width0150 + 1, height0200 + 4 };
		POINT R_block_LT = { width0700 - 7, height0200 + 6 };
		POINT start = { R_block_LT.x, R_block_LT.y };
		POINT ptns[6] = {
			{start.x,start.y},
			{start.x + shadow_len, start.y - shadow_len},
			{start.x + shadow_len + block_len, start.y - shadow_len},
			{start.x + shadow_len + block_len, start.y - shadow_len + block_len},
			{start.x + block_len, start.y + block_len},
			{start.x + block_len, start.y}
		};

		// 画状态1
		SetWorkingImage(&stateImages[0]);
		//画选框
		setfillcolor(DARKGRAY);
		solidroundrect(frame_size[0].x, frame_size[0].y, frame_size[1].x, frame_size[1].y, 4, 4);
		//画核心
		setfillcolor(WHITE);
		solidroundrect(core_size[0].x, core_size[0].y, core_size[1].x, core_size[1].y, 2, 2);
		setfillcolor(LIGHTGRAY);
		//画左边正方形
		solidrectangle(L_block_LT.x, L_block_LT.y, L_block_LT.x + block_len - 1, L_block_LT.y + block_len - 1);
		//画分隔线
		setlinecolor(LIGHTGRAY);
		setlinestyle(PS_DASH);
		line(width0500 - 1, height0200, width0500 - 1, height0800);
		//画阴影
		setfillcolor(BLACK);
		solidpolygon(ptns, 6);

		// 画状态2
		stateImages[1] = stateImages[0];
		SetWorkingImage(&stateImages[1]);
		setfillcolor(LIGHTGRAY);
		solidrectangle(R_block_LT.x, R_block_LT.y, R_block_LT.x + block_len - 1, R_block_LT.y + block_len - 1);
	}
	refresh();
}

SequentialSelectionalButton::SequentialSelectionalButton(int X, int Y, int width, int height, wstring content, bool selection, IMAGE* on_where)
	:Window(X, Y, width, height, on_where)
{
	stateIndex = 0;
	num_states = 2;
	stateImages = new IMAGE[num_states];
	stateImages[0].Resize(width, height);
	stateImages[1].Resize(width, height);
	if (content != L"")
	{
		if (selection)
		{
			wstring content_common = L"□ " + content;
			wstring content_selected = L"■ " + content;
			int textHeight = min(int(height * 0.9), width / (content_common.length()));
			int textY = int((height - textHeight) / 2);
			int textX = int((width - textHeight * content_common.length()) / 2);

			SetWorkingImage(&stateImages[0]);
			setbkmode(TRANSPARENT);
			settextstyle(textHeight, 0, _T("黑体"));
			settextcolor(WHITE);
			outtextxy(textX, textY, content_common.c_str());

			SetWorkingImage(&stateImages[1]);
			setbkmode(TRANSPARENT);
			settextstyle(textHeight, 0, _T("黑体"));
			settextcolor(WHITE);
			outtextxy(textX, textY, content_selected.c_str());
		}
		else
		{
			int textHeight = min(int(height * 0.9), width / content.length());
			int textY = int((height - textHeight) / 2);
			int textX = int((width - textHeight * content.length() / 2) / 2);

			SetWorkingImage(&stateImages[0]);
			setbkmode(TRANSPARENT);
			setfillcolor(DARKGRAY);
			solidroundrect(0, 0, width - 1, height - 1, 16, 16);
			settextstyle(textHeight, 0, _T("黑体"));
			settextcolor(LIGHTGRAY);
			outtextxy(textX, textY, content.c_str());

			SetWorkingImage(&stateImages[1]);
			setbkmode(TRANSPARENT);
			setfillcolor(DARKGRAY);
			solidroundrect(0, 0, width - 1, height - 1, 16, 16);
			settextstyle(textHeight, 0, _T("黑体"));
			settextcolor(WHITE);
			outtextxy(textX, textY, content.c_str());
		}
		refresh();
	}
}

bool SequentialSelectionalButton::response(MOUSEMSG m, int& selectionID)
{
	if (mouse_on(m.x, m.y))
	{
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			useful = true;
			return false;
		}
		else if (m.uMsg == WM_LBUTTONUP && useful)
		{
			useful = false;
			set_state((stateIndex + 1) % num_states);
			selectionID = stateIndex;
			return true;
		}
	}
	else
	{
		useful = false;
		return false;
	}
	return false;
}

void SequentialSelectionalButton::save_img(wstring name)
{
	for (int i = 0; i < num_states; ++i)
	{
		saveimage((name + to_wstring(i)).c_str(), &stateImages[i]);
	}
}

void SequentialSelectionalButton::load_stateImage(IMAGE img, int index)
{
	stateImages[index] = img;
	refresh();
}

void SequentialSelectionalButton::set_state(int stateIndex)
{
	if (this->stateIndex != stateIndex)
	{
		this->stateIndex = stateIndex;
		refresh();
	}
}

void SequentialSelectionalButton::refresh()
{
	IMAGE* wkimg = GetWorkingImage();
	SetWorkingImage(on_where);
	putimage(coordX, coordY, &stateImages[stateIndex]);
	SetWorkingImage(wkimg);
}

SequentialSelectionalButton::~SequentialSelectionalButton()
{
	delete[] stateImages;
}

MultiSelectionlButton::MultiSelectionlButton()
	:Window()
{
	num_selections = 0;
	selectionIndex = -1;
	selectionButtons = 0;

	num_settings = 0;
	settings = 0;
	settingButtons = 0;

	selectionWidth = 0;
	selectionHeight = 0;
}

MultiSelectionlButton::MultiSelectionlButton(int X, int Y, int width, int height, char kind, IMAGE* on_where)
	:Window(X, Y, width, height, on_where)
{
	num_selections = 0;
	selectionIndex = -1;
	selectionButtons = 0;

	num_settings = 0;
	settings = 0;
	settingButtons = 0;

	selectionWidth = 0;
	selectionHeight = 0;
	back.Resize(width, height);

	if (kind == '#')
	{
		// 是否根据框的大小拉伸单选按钮之间的距离
		bool strengthen = true;
		num_selections = 8;
		selectionIndex = 1;
		selectionButtons = new Selection[num_selections];

		num_settings = 0;
		settings = 0;
		settingButtons = 0;

		// 选框的宽度
		double widthRate = (2 + 0.1 * 2 + 0.125 * 3);
		double heightRate = (4 + 0.1 * 2 + 0.125 * 5);
		selectionWidth = selectionHeight = int(min(width / widthRate + 0.5, height / heightRate + 0.5));

		int intervalWidth = int(selectionWidth * 0.125 + 0.5);
		int lineWidth = max(int(selectionWidth * 0.1), 2);
		int intervalHeight = intervalWidth; 
		if (strengthen)
		{
			intervalHeight = int((height - selectionHeight * 4 - lineWidth * 2) / 5);
		}
		int startWidth = (width - int(selectionWidth * widthRate)) / 2;
		int intervalMid = width - (lineWidth + intervalWidth + selectionWidth + startWidth) * 2;
		// 初始化背景选框
		SetWorkingImage(&back);
		setfillcolor(DARKGRAY);
		solidroundrect(startWidth, 0, width - 1 - startWidth, height - 1, intervalWidth, intervalWidth);
		setfillcolor(BLACK);
		solidroundrect(startWidth + lineWidth, lineWidth, width - 1 - startWidth - lineWidth, height - 1 - lineWidth, intervalWidth, intervalWidth);

		int basicAlphaX = startWidth + lineWidth + intervalWidth;
		int basicAlphaY = lineWidth + intervalWidth;
		for (char i = 0; i < 8; ++i)
		{
			char selectionID = i + BLOCK_0;
			int start_X = basicAlphaX + int(i % 2) * (selectionWidth + intervalMid);
			int start_Y = basicAlphaY + int(i / 2) * (selectionHeight + intervalHeight);
			selectionButtons[i] = Selection(
				start_X,
				start_Y,
				selectionWidth,
				selectionHeight,
				selectionID,
				&back
			);
		}
		saveimage(_T("back"), &back);
		selectionButtons[selectionIndex].set_state(SELECTED);
		refresh();
	}
	else if (kind == '*')
	{
		num_selections = 9;
		selectionIndex = 8;
		selectionButtons = new Selection[num_selections];

		num_settings = 1;
		settings = new bool[1];
		settings[0] = false;
		settingButtons = new SequentialSelectionalButton[num_settings];;

		// 选框的宽度
		double widthRate = (3 + 0.1 * 2 + 0.125 * 4);
		double heightRate = (4 + 0.1 * 2 + 0.125 * 4);
		selectionWidth = selectionHeight = int(min(width / widthRate + 0.5, height / heightRate + 0.5));
		int intervalWidth = int(selectionWidth * 0.125 + 0.5);
		int lineWidth = max(int(selectionWidth * 0.1), 2);
		int startWidth = (width - int(selectionWidth * widthRate)) / 2;
		// 初始化背景选框
		SetWorkingImage(&back);
		setfillcolor(DARKGRAY);
		solidroundrect(startWidth, 0, width - 1 - startWidth, height - 1, intervalWidth, intervalWidth);
		setfillcolor(BLACK);
		solidroundrect(startWidth + lineWidth, lineWidth, width - 1 - startWidth - lineWidth, height - 1 - lineWidth, intervalWidth, intervalWidth);

		int basicAlphaX = startWidth + lineWidth + intervalWidth;
		int basicAlphaY = lineWidth + intervalWidth * 2;
		for (char i = 0; i < 9; ++i)
		{
			char selectionID = position2id[i / 3][i % 3] + LIGHT_0;
			int start_X = basicAlphaX + int(i % 3) * (selectionWidth + intervalWidth);
			int start_Y = basicAlphaY + int(i / 3) * (selectionHeight + intervalWidth);

			selectionButtons[i] = Selection(
				start_X,
				start_Y,
				selectionWidth,
				selectionHeight,
				selectionID,
				&back
			);
		}
		selectionButtons[selectionIndex].set_state(SELECTED);


		// Selection和Setting之间的间隔
		int intervat_SS = selectionHeight / 2;
		settingButtons[0] = SequentialSelectionalButton(
			startWidth + lineWidth + intervalWidth,
			intervat_SS + 3 * (selectionHeight + intervalWidth) + lineWidth + intervalWidth,
			width - (startWidth + lineWidth + intervalWidth) * 2,
			selectionHeight,
			L"全局",
			true,
			&back
		);
		refresh();
	}
}

MultiSelectionlButton::MultiSelectionlButton(int X, int Y, int width, int height, int num_selections, int num_settings, IMAGE* on_where)
	:Window(X, Y, width, height, on_where)
{
	this->num_selections = num_selections;
	selectionIndex = 0;
	selectionButtons = new Selection[num_selections];

	this->num_settings = num_settings;
	settings = new bool[num_settings];
	for (int i = 0; i < num_settings; ++i)
		settings[i] = false;
	settingButtons = new SequentialSelectionalButton[num_settings];
	back.Resize(width, height);
	selectionHeight = 0;
	selectionWidth = 0;
}

bool MultiSelectionlButton::response(MOUSEMSG m, int& selectionID, bool* settings)
{
	if (mouse_on(m.x, m.y))
	{
		m.x -= coordX;
		m.y -= coordY;
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			useful = true;
			// 遍历检查是否点击了选项，有就处理，返回处理结果
			for (int id = 0; id < num_selections; ++id)
				if (selectionButtons[id].mouse_on(m.x, m.y) && id != selectionIndex)
					return selectionButtons[id].response(m, selectionID);
			// 遍历检查是否点击了全局设置，有就处理，返回处理结果
			for (int i = 0; i < num_settings; ++i)
				if (settingButtons[i].mouse_on(m.x, m.y))
				{
					int id_ = 0;
					return settingButtons[i].response(m, id_);;
				}
		}
		else if (m.uMsg == WM_LBUTTONUP && useful)
		{
			useful = false;
			for (int id = 0; id < num_selections; ++id)
				if (selectionButtons[id].mouse_on(m.x, m.y) && id != selectionIndex)
				{
					bool result = selectionButtons[id].response(m, selectionID);
					if (result)
					{
						selectionButtons[selectionIndex].set_state(COMMON);
						selectionIndex = id;
						refresh();
					}
					return result;
				}
			for (int i = 0; i < num_settings; ++i)
				if (settingButtons[i].mouse_on(m.x, m.y))
				{
					int settingd_ = 0;
					bool result = settingButtons[i].response(m, settingd_);
					if (result)
					{
						settings[i] = settingd_;
						refresh();
					}
					return result;
				}
		}
	}
	else
	{
		useful = false;
		return false;
	}
	return false;
}

void MultiSelectionlButton::save_img(wstring name)
{
	name += L"_back.png";
	saveimage(name.c_str(), &back);
}

void MultiSelectionlButton::set_state(int selectionIndex)
{
	if (this->selectionIndex != selectionIndex)
	{
		selectionButtons[this->selectionIndex].set_state(COMMON);
		this->selectionIndex = selectionIndex;
		selectionButtons[selectionIndex].set_state(SELECTED);
		refresh();
	}
}

MultiSelectionlButton::~MultiSelectionlButton()
{
	delete[] selectionButtons;
	delete[] settings;
	delete[] settingButtons;
}

void MultiSelectionlButton::refresh()
{
	IMAGE* wkimg = GetWorkingImage();
	SetWorkingImage(on_where);
	putimage(coordX, coordY, &back);
	SetWorkingImage(wkimg);
}
