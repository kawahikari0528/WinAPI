#include "HelloWindows.h"
#include <windows.h>
//���⼭�� �޽��� �ڽ��� ���� ���ɴϴ�.
void HelloWindows::HelloWindowsBox()
{
	MessageBoxA(0, "Hello Windows World!", "�˸�", MB_OK);//MessageBoxA(0, ����, ����, �޽��� �ڽ� ����)

	/// <summary>
	/// �޽��� �ڽ� ���� ��
	/// MB_OK : Ȯ�� ��ư�� �ִ� �ڽ�
	/// MB_OKCANCEL : Ȯ��, ��� ��ư �ִ� �ڽ�
	/// MB_YESNO : ��, �ƴϿ� ��ư �ִ� �ڽ�
	/// MB_YESNOCANCEL : ��, �ƴϿ�, ��� ��ư �ִ� �ڽ�]
	/// MB_ICONERROR : ���� ��� �ڽ�
	/// </summary>
	return;
}
