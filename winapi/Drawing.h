#pragma once
#include<Windows.h>

class Drawing
{
public:
	static int main(HINSTANCE hinstance, WNDPROC WndProc);

	//DC (윈도우의 출력을 위한 화면 영역) 사용
	static void ScreenDraw(HWND hwnd);

	static void CustomDraw(HWND hwnd);
};

