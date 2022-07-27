#pragma once
#include "Window.h"

class FuntionalButton :public Window
{
public:
	FuntionalButton();
	FuntionalButton(int X, int Y, int width, int height, char kind, IMAGE* on_where = 0);
	bool response(MOUSEMSG m);
	void load_commonButton(IMAGE img);
	void load_selectedButton(IMAGE img);
	void save_img(wstring name);
private:
	void set_state(bool state);
	void refresh();
	IMAGE commonButton;
	IMAGE selectedButton;
	bool stateIndex;
};

class Selection :public Window
{
public:
	Selection();
	Selection(int X, int Y, int width, int height, char kind, IMAGE* on_where = 0);
	bool response(MOUSEMSG m, int& selectionID);
	void load_commonButton(IMAGE img);
	void load_selectedButton(IMAGE img);
	void save_img(wstring name);
	void set_state(bool state);
private:
	void refresh();
	IMAGE commonButton;
	IMAGE selectedButton;
	bool stateIndex;
	int meaning;
};

class SequentialSelectionalButton :public Window
{
public:
	SequentialSelectionalButton();
	SequentialSelectionalButton(const SequentialSelectionalButton& another);
	SequentialSelectionalButton& operator=(const SequentialSelectionalButton& another);
	SequentialSelectionalButton(int X, int Y, int width, int height, char kind, IMAGE* on_where = 0);
	SequentialSelectionalButton(int X, int Y, int width, int height, wstring content = L"", bool selection = false, IMAGE* on_where = 0);
	bool response(MOUSEMSG m, int& selectionID);
	void save_img(wstring name);
	void load_stateImage(IMAGE img, int index);
	void set_state(int state);
	~SequentialSelectionalButton();
private:
	void refresh();
	int num_states;
	int stateIndex;
	IMAGE* stateImages;
};


class MultiSelectionlButton :public Window
{
public:
	MultiSelectionlButton();
	MultiSelectionlButton(int X, int Y, int width, int height, char kind, IMAGE* on_where = 0);
	MultiSelectionlButton(int X, int Y, int width, int height, int num_selections, int num_settings, IMAGE* on_where = 0);
	bool response(MOUSEMSG m, int& selectionID, bool* settings);
	void save_img(wstring name);
	~MultiSelectionlButton();
private:
	void set_state(int selectionIndex);
	void refresh();
	int num_selections;
	int selectionIndex;
	Selection* selectionButtons;
	int num_settings;
	bool* settings;
	SequentialSelectionalButton* settingButtons;
	IMAGE back;
	int selectionWidth;
	int selectionHeight;
};
