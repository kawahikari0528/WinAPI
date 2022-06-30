#pragma once
#include <Windows.h>

class FirstWindow
{
public:
	static void WindowType(HINSTANCE hinstance, WNDPROC WndProc);
	static void MakeWindow(HINSTANCE hinstance);
	static void Message();
	static int main(HINSTANCE hinstance, WNDPROC WndProc);
};

