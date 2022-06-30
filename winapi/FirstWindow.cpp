#include "FirstWindow.h"
#include <windows.h>
//윈도우의 생성 과정은
//속성설정 -> 생성 -> 메세지 처리 순이다.




//이 함수는 윈도우의 속성을 설정하는 함수다.
void FirstWindow::WindowType(HINSTANCE hinstance, WNDPROC WndProc) {

	WNDCLASSEXA win = { 0 }; // WNDCLASSEXA 는 윈도우 속성 구조체
	win.cbSize = sizeof(win); // 구조체의 사이즈 정하기
	win.style = CS_HREDRAW | CS_VREDRAW; //  CS_HREDRAW | CS_VREDRAW : 윈도우의 크기가 변하면 다시 그린다.
	win.hInstance = hinstance;// 핸들 인스턴스

	win.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);// 이거는 배경색인데, WHITE_BRUSH는 하얀색을 의미함
	win.lpszClassName = "클래스 이름";

	win.lpfnWndProc = WndProc; // WndProc은 콜백함수다. 함수를 값으로 전달하여 사용한다.

	RegisterClassExA(&win);// 클래스를 등록함
	return;

}

//이 함수는 윈도우를 생성하는 함수다.
void FirstWindow::MakeWindow(HINSTANCE hinstance)
{
	HWND hwnd;
	hwnd = CreateWindowA(
		"my window",
		"maplestory",//윈도우 창 이름
		WS_OVERLAPPEDWINDOW,//윈도우 스타일, 지금 써 있는 건 창 크기를 변경 가능한 스타일이다.

		//지금 써 있는 건 기본값이다.(정수로 입력 가능)
		CW_USEDEFAULT,//X값
		CW_USEDEFAULT,//Y값
		CW_USEDEFAULT,//가로
		CW_USEDEFAULT,//세로

		0, 0, hinstance, 0 //부모윈도우 핸들, 메뉴 ,핸들 인스턴스, 정보
		//일단 필요 없으니 0으로 두자
		);

	ShowWindow(hwnd, 1);
}

//이 함수는 메세지 처리를 담당한다.
void FirstWindow::Message()
{
	//메세지 처리는 MSG 형식을 사용한다.

	MSG msg;
	while (GetMessageA(&msg, 0, 0, 0)) {//메세지 처리는 프로그램 종료시까지 계속 한다.

		//대충 메세지를 번역하고 처리하는 과정
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}

}

//위의 부분들을 총합 한 부분이다.
int FirstWindow::main(HINSTANCE hinstance, WNDPROC WndProc)
{
	WNDCLASSEXA win = { 0 };
	win.cbSize = sizeof(win);
	win.style = CS_HREDRAW | CS_VREDRAW;
	win.hInstance = hinstance;
	win.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	win.lpszClassName = "my window";
	win.lpfnWndProc = WndProc; //나중에 배움
	RegisterClassExA(&win);
	HWND hwnd;
	hwnd = CreateWindowA(
		"my window",
		"maplestory",
		WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT,//x
		CW_USEDEFAULT,//y
		1920,//가로
		1080,//세로
		0, 0, hinstance, 0
	);
	ShowWindow(hwnd, 1);
	MSG msg;
	while (GetMessageA(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
	return 0;
}


