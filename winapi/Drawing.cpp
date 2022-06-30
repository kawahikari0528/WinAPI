#include "Drawing.h"


int Drawing::main(HINSTANCE hinstance, WNDPROC WndProc)
{

	WNDCLASSEXA win = { 0 };
	win.cbSize = sizeof(win);
	win.style = CS_HREDRAW | CS_VREDRAW;
	win.hInstance = hinstance;
	win.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	win.lpszClassName = "my window";
	win.lpfnWndProc = WndProc; 
	RegisterClassExA(&win);
	//윈도우 속성

	HWND hwnd;
	hwnd = CreateWindowA(
		"my window",
		"Drawing",
		WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT,//x
		CW_USEDEFAULT,//y
		CW_USEDEFAULT,//가로
		CW_USEDEFAULT,//세로
		0, 0, hinstance, 0
	);
	ShowWindow(hwnd, 1);
	//윈도우 창 구현

	MSG msg;
	while (GetMessageA(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
	return 0;

}

void Drawing::ScreenDraw(HWND hwnd)
{

	PAINTSTRUCT ps;
	HDC hdc;
	//일반적으로 dc는 'HDC' 형식에 저장됨
	hdc = BeginPaint(hwnd, &ps);//그리기 시작
	//도형 그리기

	/*
	직선을 그릴 때 사용
	MoveToEx(HDC, x1, y1, NULL); //NULL은 0이랑 같음
	LineTo(HDC, x2, y2);
	*/
	MoveToEx(hdc, 300, 100, 0);
	LineTo(hdc, 300, 300);

	MoveToEx(hdc, 100, 300, 0);
	LineTo(hdc, 500, 300);
	//ㅗ

	
	Ellipse(hdc, 200, 200, 300,300);
	//ㅇ

	Rectangle(hdc, 200, 100, 300, 200);

	//도형 그리기
	EndPaint(hwnd, &ps);//그리기 해제


	//이 함수는 WM_PAINT에서만 사용 가능

}


//WM_PAINT 밖에서 사용하기 위해서는 GetDC, ReleaseDC함수 사용
void Drawing::CustomDraw(HWND hwnd)
{
	HDC hdc;
	hdc = GetDC(hwnd);
	ReleaseDC(hwnd, hdc);

}

