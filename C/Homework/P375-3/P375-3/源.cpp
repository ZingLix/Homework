#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char name[50], email[50];
	FILE *fp = fopen("data.txt", "w");
	gets_s(name);
	gets_s(email);
	printf("Name:%s\nEmail:%s\n", name, email);
	fprintf(fp, "%s\n%s", name, email);
	fclose(fp);
	name[0] = '\0';
	fp = fopen("data.txt", "r");
	rewind(fp);
	fgets(name,50,fp);
	fgets(email, 50, fp);
	name[strlen(name) - 1] = '\0';
	printf("Name:%s\nEmail:%s\n", name, email);
	system("pause");
	return 0;
}
//}
//#include <stdio.h>   
//#include <stdlib.h>
//#define MAX_LINE 1024                   //每行最大字节数  
//
//int main()
//{
//	FILE *fp;
//	char strLine[MAX_LINE];                             //读取缓冲区  
//	if ((fp = fopen("data.txt", "r")) == NULL)      //判断文件是否存在及可读  
//	{
//		printf("Open Falied!");
//		return -1;
//	}
//	while (!feof(fp))                                   //循环读取每一行，直到文件尾  
//	{
//		fgets(strLine, MAX_LINE, fp);                     //将fp所指向的文件一行内容读到strLine缓冲区  
//		printf("%s", strLine);                          //输出所读到的内容  
//														//DO SOMETHING ELSE  
//	}
//	fclose(fp);                                         //关闭文件  
//	printf("\n");
//	system("pause");
//	return 0;
//}