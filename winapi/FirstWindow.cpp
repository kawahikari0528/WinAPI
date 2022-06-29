#include "FirstWindow.h"
#include <windows.h>
//�������� ���� ������
//�Ӽ����� -> ���� -> �޼��� ó�� ���̴�.

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);




//�� �Լ��� �������� �Ӽ��� �����ϴ� �Լ���.
void FirstWindow::WindowType(HINSTANCE hinstance) {

	WNDCLASSEXA win = { 0 }; // WNDCLASSEXA �� ������ �Ӽ� ����ü
	win.cbSize = sizeof(win); // ����ü�� ������ ���ϱ�
	win.style = CS_HREDRAW | CS_VREDRAW; //  CS_HREDRAW | CS_VREDRAW : �������� ũ�Ⱑ ���ϸ� �ٽ� �׸���.
	win.hInstance = hinstance;// �ڵ� �ν��Ͻ�

	win.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);// �̰Ŵ� �����ε�, WHITE_BRUSH�� �Ͼ���� �ǹ���
	win.lpszClassName = "Ŭ���� �̸�";

	win.lpfnWndProc = WndProc; // WndProc�� �ݹ��Լ���. �Լ��� ������ �����Ͽ� ����Ѵ�.

	RegisterClassExA(&win);// Ŭ������ �����
	return;

}

//�� �Լ��� �����츦 �����ϴ� �Լ���.
void FirstWindow::MakeWindow(HINSTANCE hinstance)
{
	HWND hwnd;
	hwnd = CreateWindowA(
		"my window",
		"maplestory",//������ â �̸�
		WS_OVERLAPPEDWINDOW,//������ ��Ÿ��, ���� �� �ִ� �� â ũ�⸦ ���� ������ ��Ÿ���̴�.

		//���� �� �ִ� �� �⺻���̴�.(������ �Է� ����)
		CW_USEDEFAULT,//X��
		CW_USEDEFAULT,//Y��
		CW_USEDEFAULT,//����
		CW_USEDEFAULT,//����

		0, 0, hinstance, 0 //�θ������� �ڵ�, �޴� ,�ڵ� �ν��Ͻ�, ����
		//�ϴ� �ʿ� ������ 0���� ����
		);

	ShowWindow(hwnd, 1);
}

//�� �Լ��� �޼��� ó���� ����Ѵ�.
void FirstWindow::Message()
{
	//�޼��� ó���� MSG ������ ����Ѵ�.

	MSG msg;
	while (GetMessageA(&msg, 0, 0, 0)) {//�޼��� ó���� ���α׷� ����ñ��� ��� �Ѵ�.

		//���� �޼����� �����ϰ� ó���ϴ� ����
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}

}

//���� �κе��� ���� �� �κ��̴�.
int FirstWindow::main(HINSTANCE hinstance)
{
	WNDCLASSEXA win = { 0 };
	win.cbSize = sizeof(win);
	win.style = CS_HREDRAW | CS_VREDRAW;
	win.hInstance = hinstance;
	win.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	win.lpszClassName = "my window";
	win.lpfnWndProc = WndProc; //���߿� ���
	RegisterClassExA(&win);
	HWND hwnd;
	hwnd = CreateWindowA(
		"my window",
		"maplestory",
		WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT,//x
		CW_USEDEFAULT,//y
		1920,//����
		1080,//����
		0, 0, hinstance, 0
	);
	ShowWindow(hwnd, 1);
	MSG msg;
	while (GetMessageA(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
	return 0;
	return 0;
}


//�ݹ��Լ� (WinMain���� ���� �־�� ��)
//�Ű������� (������ �ڵ�HWND, ������ �޼���msg, Ű �Է� ���콺 �Է� ���� �̺�Ʈ ����)
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {//��Ȳ�� ���� �޽���(msg�� �������� ���� ������ �˾Ƶθ� �ȴ�.)
	case WM_CHAR:
		if(wParam == 'w')
			MessageBoxA(hwnd, "���� ��/�� ?", "������ ������ ����", MB_OK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);//���� �̷� �κ��� �����찡 ����� �� ����ȴ�.
		return 0;
	}
	return(DefWindowProcA(hwnd, msg, wParam, lParam));
}