#include "HelloWindows.h"
#include <windows.h>
//여기서는 메시지 박스에 대해 나옵니다.
void HelloWindows::HelloWindowsBox()
{
	MessageBoxA(0, "Hello Windows World!", "알림", MB_OK);//MessageBoxA(0, 내용, 제목, 메시지 박스 형식)

	/// <summary>
	/// 메시지 박스 형식 문
	/// MB_OK : 확인 버튼만 있는 박스
	/// MB_OKCANCEL : 확인, 취소 버튼 있는 박스
	/// MB_YESNO : 예, 아니오 버튼 있는 박스
	/// MB_YESNOCANCEL : 예, 아니오, 취소 버튼 있는 박스]
	/// MB_ICONERROR : 오류 모양 박스
	/// </summary>
	return;
}
