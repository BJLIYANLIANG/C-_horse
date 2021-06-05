//…¡∆¡Ãÿ–ß
#include <stdio.h>
#include <windows.h>
void flashWindow()
{
 
	HWND handle=GetForegroundWindow();
	for(int i=0;i<15;i++)
	{
		RECT rc;
		GetWindowRect(handle,&rc);
		MoveWindow(handle,rc.left+8,rc.top+8,rc.right-rc.left,rc.bottom-rc.top,1);
		Sleep(40);
		MoveWindow(handle,rc.left,rc.top,rc.right-rc.left,rc.bottom-rc.top,1);
		Sleep(40);
		Beep(0x0fff,10);//≈‰“Ù
	}
 
}
void main()
{
	flashWindow();
	getchar();
}
