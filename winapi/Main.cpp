#include <windows.h>
#include "HelloWindows.h"
#include "FirstWindow.h"

//�̰������� ���� winapi�� �׽�Ʈ �غ�����

//winapi�� main���Դϴ�.
int WINAPI WinMain(
	HINSTANCE hinstance, HINSTANCE, char*, int
) {
	FirstWindow::main(hinstance);
}