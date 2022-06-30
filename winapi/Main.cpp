#include <windows.h>
#include "HelloWindows.h"
#include "FirstWindow.h"
#include"Drawing.h"
//이곳에서는 만든 winapi를 테스트 해보세요


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);



//winapi의 main문입니다.
int WINAPI WinMain(
	HINSTANCE hinstance, HINSTANCE, char*, int
) {
	Drawing::main(hinstance, WndProc);
}

//콜백함수 (WinMain보다 위에 있어야 함)
//매개변수는 (윈도우 핸들HWND, 윈도우 메세지msg, 키 입력 마우스 입력 같은 이벤트 변수)
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {//상황에 따른 메시지(msg는 윈도우의 상태 정도로 알아두면 된다.)
	case WM_CREATE:
		break;
	case WM_PAINT:
		Drawing::ScreenDraw(hwnd);//그릴 때 사용하는 메소드
		break;
	case WM_LBUTTONDOWN:
		Drawing::CustomDraw(hwnd); //WM_PAINT 밖에서 그릴 때 사용하는 메소드
		break;
	case WM_DESTROY:
		PostQuitMessage(0);//따라서 이런 부분은 윈도우가 종료될 때 실행된다.
		return 0;
	}
	return(DefWindowProcA(hwnd, msg, wParam, lParam));
}