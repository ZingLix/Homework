#include <omp.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

#define NUM_THREADS 4
static long long num_steps = 400000000; 

void serial(){
	double x, pi, sum = 0.0, step = 1.0/(double) num_steps;
	clock_t start=clock();
	for (long i = 1; i <= num_steps; i++){
		x = (i + 0.5)*step;
		sum += 4.0/(1.0 + x*x);
	}
	pi=sum;
	printf("Pi = %f\n", pi/num_steps);
}

void parallel1(){
	double x, pi = 0.0, sum[NUM_THREADS], step = 1.0/(double)num_steps;
	omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
	{
		int id = omp_get_thread_num();
		sum[id] = 0.0;
		for (long i = id; i < num_steps; i += NUM_THREADS) {
			x = (i + 0.5)*step;
			sum[id] += 4.0/(1.0 + x*x); // 根据ID号分配任务
		}
	}
	for(int i = 0; i < NUM_THREADS; i++) pi += sum[i] * step;
	printf("Pi = %f\n", pi);
}

void parallel2(){
	double x, pi = 0.0, sum[NUM_THREADS], step = 1.0/(double)num_steps;
	omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
	{
		int id = omp_get_thread_num();
		sum[id] = 0.0;
#pragma omp for
		for (long i = 0; i < num_steps; i++)
		{
			x = (i + 0.5)*step;
			sum[id] += 4.0/(1.0 + x*x); // 存储每次的结果
		}
	}
	for(int i = 0; i < NUM_THREADS; i++) pi += sum[i] * step;
	printf("Pi = %f\n", pi);

}

void parallel3(){
	double x, pi = 0.0, sum, step = 1.0/(double)num_steps;
	omp_set_num_threads(NUM_THREADS);
#pragma omp parallel private(x, sum)
	{
		int id = omp_get_thread_num();
		sum = 0.0;
		for (long i = id; i < num_steps; i += NUM_THREADS)
		{
			x = (i + 0.5)*step;
			sum += 4.0/(1.0 + x*x);
		}
#pragma omp critical
		pi += sum*step;
	}
	printf("Pi = %f\n", pi);
}

void parallel4(){
double x, pi = 0.0, sum = 0.0, step = 1.0/(double)num_steps;
	omp_set_num_threads(NUM_THREADS);
	#pragma omp parallel for reduction(+:sum) private(x)
	for (long i = 0; i < num_steps; i++)
	{
		x = (i + 0.5)*step;
		sum += 4.0/(1.0 + x*x);
	}
	pi += sum*step;
	printf("Pi = %f\n", pi);
}


long long countTime(void (*f)(),const char* msg,long long serial){
	long long freq, countBegin, countEnd;
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
	QueryPerformanceCounter((LARGE_INTEGER *)&countBegin);
	f();
	QueryPerformanceCounter((LARGE_INTEGER *)&countEnd);
	printf("%s:\n",msg);
	printf("CPU频率：%lld, 计数：%lld, 耗时：%f秒\n", freq, countEnd - countBegin, 
		(countEnd - countBegin) / (double)freq);
	if(serial!=0)
		printf("加速比：%f\n", serial*1.0/(countEnd - countBegin));
	printf("\n");
	return countEnd-countBegin;
}

int main(){

	long long s=countTime(serial,"串行",0);
	countTime(parallel1,"并行1",s);
	countTime(parallel2,"并行2",s);
	countTime(parallel3,"并行3",s);
		countTime(parallel4,"并行4",s);
	system("pause");
}
