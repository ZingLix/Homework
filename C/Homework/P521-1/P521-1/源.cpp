#include <stdio.h>
#include <stdlib.h>

int main() {
	int aa = 0xAD3F, bb = 0xCC43, cc = 0xAC23, dd = 0xFFFB, ee = 0x23F2;
	printf("aa&bb=0x%X\n", aa&bb);
	printf("cc|dd=0x%X\n", cc | dd);
	printf("dd^ee=0x%X\n", dd^ee);
	printf("~cc=0x%X\n", ~cc);
	printf("aa>>5=0x%X\n", aa >> 5);
	printf("dd<<4=0x%X\n", dd << 4);
	system("pause");
	return 0;
}