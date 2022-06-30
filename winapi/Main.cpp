#include <windows.h>
#include "HelloWindows.h"
#include "FirstWindow.h"
#include"Drawing.h"
//�̰������� ���� winapi�� �׽�Ʈ �غ�����


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);



//winapi�� main���Դϴ�.
int WINAPI WinMain(
	HINSTANCE hinstance, HINSTANCE, char*, int
) {
	Drawing::main(hinstance, WndProc);
}

//�ݹ��Լ� (WinMain���� ���� �־�� ��)
//�Ű������� (������ �ڵ�HWND, ������ �޼���msg, Ű �Է� ���콺 �Է� ���� �̺�Ʈ ����)
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {//��Ȳ�� ���� �޽���(msg�� �������� ���� ������ �˾Ƶθ� �ȴ�.)
	case WM_CREATE:
		break;
	case WM_PAINT:
		Drawing::ScreenDraw(hwnd);//�׸� �� ����ϴ� �޼ҵ�
		break;
	case WM_LBUTTONDOWN:
		Drawing::CustomDraw(hwnd); //WM_PAINT �ۿ��� �׸� �� ����ϴ� �޼ҵ�
		break;
	case WM_DESTROY:
		PostQuitMessage(0);//���� �̷� �κ��� �����찡 ����� �� ����ȴ�.
		return 0;
	}
	return(DefWindowProcA(hwnd, msg, wParam, lParam));
}