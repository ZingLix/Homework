#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	char city[5][15] = { "San Francisco", "Berkeley","Palo Alto", "Santa Cruz", "San Jose" };
	char descriptor[12][15] = { "mild","weak", "slow",
		"moderate", "medium", "tempered" ,
		"strong", "powerful", "sharp",
		"violent", "destructive", "extreme" };
	FILE *fp=fopen("data.txt", "r");
	char report[1000] = { '\0' };
	char *descript[10];
	int k, rept_len=1, tally[4][5] = { 0 },  mm;
	int i=0, j=0;
	while (report[i] != EOF) {
		while(1){
			report[i] = getc(fp);
			if (report[i] == '#' || report[i] == EOF) break;
			i++;
		}
		report[i + 1] = '\0';
		rept_len = i + 2;
		descript[j] = (char *)malloc((i+2)*sizeof(char));
		strcpy(descript[j], report);
		j++;
		i = 0;
	}
	char* match;
	int num = j;
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < 5; j++) {
			match = strstr(descript[i], city[j]);
			if (match != NULL) break;
		}
		for (k = 0; k < 12; k++) {
			match = strstr(descript[i], descriptor[k]);
			if (match != NULL) break;
		}

		if (0 <= k && k <= 2) {
			tally[0][j]++;
		}
		else if (3 <= k &&
			k <= 5) {
			tally[1][j]++;
		}
		else if (6 <= k &&
			k <= 8) {
			tally[2][j]++;
		}
		else if (9 <= k &&
			k <= 11) {
			tally[3][j]++;
		}
	}
	for (i = 0; i < 5; i++) printf("%12s", city[i]);
	printf("\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++) {
			printf("%12d", tally[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	system("pause");
	return 0;
}