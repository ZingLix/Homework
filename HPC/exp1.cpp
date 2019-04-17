#include <iostream>
#include <Windows.h>
#include <ctime>

#define N 1000000000
#define MAX_THREAD_NUM 8

double res[MAX_THREAD_NUM];

struct para{
	int id;
	int thread_num;
};

DWORD WINAPI cal(LPVOID l){
	para* p=(para*)l;
	clock_t start=clock();
	double local,pi=0;
	double w=1.0/N;
	for(long i=p->id;i<N;i+=p->thread_num){
		local=(i+0.5)*w;
		pi+=4.0/(1.0+local*local);
	}
	res[p->id]=pi;
	clock_t end=clock();
	printf("Thread %d: %d\n",p->id,end-start);
	return 0;
}

int main(){
	double local,pi=0;
	double w=1.0/N;
	printf("串行：\n");
	clock_t start=clock();
	for(long i=0;i<N;i++){
		local=(i+0.5)*w;
		pi+=4.0/(1.0+local*local);
	}
	clock_t end=clock();
	clock_t serial=end-start;
	printf("time: %d\n",serial);
	printf("pi: %.10lf\n\n",pi*w);
	printf("并行：");
	for(int num=2;num<=8;num*=2){
		printf("\nThread Number：%d\n",num);
		HANDLE threads[MAX_THREAD_NUM];
		struct para p[MAX_THREAD_NUM];
		DWORD threadid;
		pi=0;
		start=clock();
		for(long i=0;i<num;++i){
			p[i].id=i;
			p[i].thread_num=num;
			threads[i]=CreateThread(NULL,0,cal,(LPVOID)(&p[i]),0,&threadid);
		}
		WaitForMultipleObjects(num, threads, TRUE, INFINITE); 
		for(long i=0;i<num;++i){
			pi+=res[i];
		}
		end=clock();
		clock_t parallel=end-start;
		printf("time: %d\n",parallel);
		printf("pi: %.10lf\n",pi*w);
		printf("\n加速比: %lf\n",1.0*serial/parallel);
		for(int i=0;i<num;++i){
			CloseHandle(threads[i]);
		}
	}
	std::cin.get();
	return 0;
}
