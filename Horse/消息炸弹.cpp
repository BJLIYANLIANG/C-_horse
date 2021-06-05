#define UNICODE 
#define _UNICODE 
#include <stdio.h> 
#include <tchar.h> 
#include <windows.h> 
#include <Lm.h> 
//œ˚œ¢’®µØ
#pragma comment(lib, "Netapi32.lib") // º”‘ÿNetapi32.libø‚ 
 
 
void main(int argc, wchar_t *argv[]) 
{ 	
	TCHAR *DesIp = _TEXT("1210.36.16.167"); 
	
	TCHAR *SouIp = _TEXT("255.255.255.255"); 
	
	TCHAR *Msg = _TEXT("Fuck All MM"); 
	
	int nRet = NetMessageBufferSend(NULL, DesIp, SouIp, (LPBYTE)Msg, sizeof(Msg)); 
	
	if (nRet != NERR_Success) 		
	{ 
		
		printf("Error\n"); 		
	} else{
		printf("success\n");
	}
	getchar();
	
} 
