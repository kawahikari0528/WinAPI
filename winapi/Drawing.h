#pragma once
#include<Windows.h>

class Drawing
{
public:
	static int main(HINSTANCE hinstance, WNDPROC WndProc);

	//DC (�������� ����� ���� ȭ�� ����) ���
	static void ScreenDraw(HWND hwnd);

	static void CustomDraw(HWND hwnd);
};

