#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t p1, p2;
	if((p1=fork())!=0)
	{
		printf("b\n");
		_exit(0);
	}
	if((p2=fork())!=0)
	{
		printf("c\n");
		_exit(0);
	}
	printf("a\n");
	waitpid(p1, NULL, 0);
	waitpid(p2, NULL, 0);
	return 0;
}