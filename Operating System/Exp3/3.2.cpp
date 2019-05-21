#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MQ_WORKSPACE 75
using namespace std;
int main() {
	pid_t server_pid=getpid();
	int buffer;
	int mq = msgget(MQ_WORKSPACE, IPC_CREAT | 0777);
	pid_t client_pid = fork();
	if(client_pid==0)
	{
		for (buffer=10;buffer>=1;--buffer)
		{
			cout << "Client has sent message to Server!\n";
			msgsnd(mq, &buffer, sizeof buffer, NULL);
			if (buffer==1)
			{
				cout << "Server wiil exit.\n";
				exit(0);
			}
		}

	}
	else
	{
		while (true)
		{
			msgrcv(mq, &buffer, sizeof buffer,0, NULL);
			cout << "Server has received message from Client!\n";
			if(buffer==1)
			{
				msgctl(mq, IPC_RMID, 0);
				break;
			}
		}
	}
	

	return 0;
}
