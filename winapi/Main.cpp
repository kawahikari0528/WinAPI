#include <windows.h>
#include "HelloWindows.h"
#include "FirstWindow.h"

//이곳에서는 만든 winapi를 테스트 해보세요

//winapi의 main문입니다.
int WINAPI WinMain(
	HINSTANCE hinstance, HINSTANCE, char*, int
) {
	FirstWindow::main(hinstance);
}