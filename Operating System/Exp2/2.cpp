#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	pid_t pid;
	if((pid=fork())==0)
	{
		execl("/bin/ls", "ls");
	}
	waitpid(pid, NULL, 0);
	printf("%d", pid);
	return 0;
}
