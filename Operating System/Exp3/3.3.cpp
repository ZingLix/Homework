#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define MQ_WORKSPACE 75
using namespace std;
int main() {
	srand(time(NULL));
	int shm = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0777);
	pid_t client_pid = fork();
	if (client_pid == 0)
	{
		int* ptr = (int*)shmat(shm, NULL, 0);
		while (true)
		{
			if (ptr[0] == -1)
			{
				ptr[0] = rand() % 10;
				cout << "Client has sent message to Server!\n";
				if (ptr[0] == 0)
				{
					cout << "Server wiil exit.\n";
					shmdt(ptr);
					exit(0);
				}
			}
		}
	}
	else
	{
		int* ptr = (int*)shmat(shm, NULL, 0);
		ptr[0] = -1;
		while (true)
		{
			if (ptr[0] == -1) continue;
			if (ptr[0] == 0)
			{
				shmdt(ptr);
				break;
			}
			cout << "Server has received message from Client!\n";
			ptr[0] = -1;
		}
	}
	shmctl(shm,IPC_RMID, NULL);
	return 0;
}
