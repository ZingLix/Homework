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
//#define MAX_LINE 1024                   //ÿ������ֽ���  
//
//int main()
//{
//	FILE *fp;
//	char strLine[MAX_LINE];                             //��ȡ������  
//	if ((fp = fopen("data.txt", "r")) == NULL)      //�ж��ļ��Ƿ���ڼ��ɶ�  
//	{
//		printf("Open Falied!");
//		return -1;
//	}
//	while (!feof(fp))                                   //ѭ����ȡÿһ�У�ֱ���ļ�β  
//	{
//		fgets(strLine, MAX_LINE, fp);                     //��fp��ָ����ļ�һ�����ݶ���strLine������  
//		printf("%s", strLine);                          //���������������  
//														//DO SOMETHING ELSE  
//	}
//	fclose(fp);                                         //�ر��ļ�  
//	printf("\n");
//	system("pause");
//	return 0;
//}