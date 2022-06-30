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
	//������ �Ӽ�

	HWND hwnd;
	hwnd = CreateWindowA(
		"my window",
		"Drawing",
		WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT,//x
		CW_USEDEFAULT,//y
		CW_USEDEFAULT,//����
		CW_USEDEFAULT,//����
		0, 0, hinstance, 0
	);
	ShowWindow(hwnd, 1);
	//������ â ����

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
	//�Ϲ������� dc�� 'HDC' ���Ŀ� �����
	hdc = BeginPaint(hwnd, &ps);//�׸��� ����
	//���� �׸���

	/*
	������ �׸� �� ���
	MoveToEx(HDC, x1, y1, NULL); //NULL�� 0�̶� ����
	LineTo(HDC, x2, y2);
	*/
	MoveToEx(hdc, 300, 100, 0);
	LineTo(hdc, 300, 300);

	MoveToEx(hdc, 100, 300, 0);
	LineTo(hdc, 500, 300);
	//��

	
	Ellipse(hdc, 200, 200, 300,300);
	//��

	Rectangle(hdc, 200, 100, 300, 200);

	//���� �׸���
	EndPaint(hwnd, &ps);//�׸��� ����


	//�� �Լ��� WM_PAINT������ ��� ����

}


//WM_PAINT �ۿ��� ����ϱ� ���ؼ��� GetDC, ReleaseDC�Լ� ���
void Drawing::CustomDraw(HWND hwnd)
{
	HDC hdc;
	hdc = GetDC(hwnd);
	ReleaseDC(hwnd, hdc);

}

