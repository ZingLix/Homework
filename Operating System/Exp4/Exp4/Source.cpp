#include <math.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define TRUE 1 
#define FALSE 0 
#define INVALID -1 

#define total_instruction 320   /*指令流长*/ 
#define total_vp 32           /*虚页长*/ 
#define clear_period 50       /*清零周期*/ 

typedef struct {               /*页面结构*/
	int pn, pfn, counter, time;

}pl_type;

pl_type pl[total_vp];          /*页面结构数组*/

struct pfc_struct {             /*页面控制结构*/
	int pn, pfn;  
	struct pfc_struct* next;
};

struct pfc_struct pfc[total_vp], * freepf_head, * busypf_head, * busypf_tail;

int diseffect, a[total_instruction];
int page[total_instruction], offset[total_instruction];
void initialize();
void FIFO(int);
void LRU(int);
void OPT(int);
void LFU(int);
void CLOCK(int);

int main() {
	int S, i;   
	srand(10 * getpid());  /*由于每次运行时进程号不同，故可用来作为初始化随机数队列的“种子”*/
	S = (int)(319.0 * rand() / RAND_MAX) + 1;
	for (i = 0; i < total_instruction; i += 4) /*产生指令队列*/
	{
		a[i] = S;          /*任选一指令访问点*/
		a[i + 1] = a[i] + 1;    /*顺序执行下一条指令*/
		a[i + 2] = (int)(1.0 * a[i] * rand() / RAND_MAX);         /*执行前地址指令m'*/
		a[i + 3] = a[i + 2] + 1;   /*执行后地址指令*/
		S = (int)(1.0 * rand() * (318 - a[i + 2]) / RAND_MAX) + a[i + 2] + 2;
	}

	for (i = 0; i < total_instruction; i++)  /*将指令序列变换成页地址流*/
	{
		page[i] = a[i] / 10;
		offset[i] = a[i] % 10;
	}
	for (i = 4; i <= 32; i++)  /*用户内存工作区从4个页面到32个页面*/
	{
		printf("%2d page frames\t", i);
		FIFO(i);
		LRU(i);
		OPT(i);
		LFU(i);
		CLOCK(i);
		printf("\n");
	}  
	return 0;
}


void initialize(int total_pf)  /*初始化相关数据结构*/
{
	int i;
	diseffect = 0;
	for (i = 0; i < total_vp; i++)
	{
		pl[i].pn = i; 
		pl[i].pfn = INVALID; /*置页面控制结构中的页号，页面为空*/
		pl[i].counter = 0;
		pl[i].time = -1;   /*置页面控制结构中的访问次数，时间为-1*/
	}   
	for (i = 1; i < total_pf; i++)
	{
		pfc[i - 1].next = &pfc[i];
		pfc[i - 1].pfn = i - 1;
	}          /*建立pfc[i-1]和pfc[i]之间的链接*/
	pfc[total_pf - 1].next = NULL;
	pfc[total_pf - 1].pfn = total_pf - 1;
	freepf_head = &pfc[0];             /*空页面队列的头指针为pfc[0]*/
}


void FIFO(int total_pf) {
	int i;
	struct pfc_struct* p;
	initialize(total_pf);  /*初始化相关页面控制用数据结构*/
	busypf_head = busypf_tail = NULL;          /*忙页面队列，队列尾链接*/
	for (i = 0; i < total_instruction; i++) {
		if (pl[page[i]].pfn == INVALID)   /*页面失效*/ {
			diseffect += 1;               /*失效次数*/
			if (freepf_head == NULL)    /*无空闲页面*/ {
				p = busypf_head->next;
				pl[busypf_head->pn].pfn = INVALID;
				freepf_head = busypf_head;          /*释放忙页面队列中的第一个页面*/
				freepf_head->next = NULL;
				busypf_head = p;
			}
			p = freepf_head->next;  /*按FIFO方式调新页面入内存页面*/
			freepf_head->next = NULL;
			freepf_head->pn = page[i];
			pl[page[i]].pfn = freepf_head->pfn;
			if (busypf_tail == NULL)
				busypf_head = busypf_tail = freepf_head;
			else {
				busypf_tail->next = freepf_head;
				busypf_tail = freepf_head;
			} 
			freepf_head = p;
		}
	}
	printf("FIFO:%6.4f  ", 1 - (float)diseffect / 320);
}

void LRU(int total_pf)
{
	initialize(total_pf);
	int free_pf_count = total_pf;
	int replace_pf = 0;
	int time_for_clear_period = 0;
	for (int currentInstruction = 0; currentInstruction < total_instruction; currentInstruction++) {
		//页面失效
		if (pl[page[currentInstruction]].pfn == INVALID) {
			diseffect += 1;
			if (free_pf_count > 0) {
				pl[page[currentInstruction]].pfn = total_pf - free_pf_count;
				free_pf_count--;
			}
			else {
				//检索counter最小的且在内存中的页
				//初始化replace的页号，向后进行查找，找到counter为0的页
				for (int i = 0; i < total_instruction; i++) {
					if (pl[page[i]].pfn != INVALID && pl[page[i]].counter != 0) {
						replace_pf = page[i];
						break;
					}
				}
				//载入本次要访问的页
				pl[page[currentInstruction]].pfn = pl[replace_pf].pfn;
				pl[page[currentInstruction]].counter = 0;
				//释放将要替换的页
				pl[replace_pf].pfn = INVALID;
				pl[replace_pf].counter = 0;
			}
		}
		else {
			pl[page[currentInstruction]].counter++;
		}
		//时间周期递增
		time_for_clear_period += 1;
		//到达清零周期则把所有指令的counter清零
		if (time_for_clear_period >= clear_period) {
			for (int i = 0; i < total_instruction; i++) {
				pl[page[i]].counter = 0;
			}
		}
	}
	printf("LRU:%6.4f  ", 1 - (float)diseffect / 320);
}

void OPT(int total_pf)
{
	initialize(total_pf);
	int free_pf_count = total_pf;
	for (int currentInstruction = 0; currentInstruction < total_instruction; currentInstruction++) {
		if (pl[page[currentInstruction]].pfn != INVALID) continue;
		int replace_pfn = 0;
		int access_distance[total_pf];
		//页面失效
		diseffect += 1;
		if (free_pf_count > 0) {
			//有空闲页面，直接装入
			pl[page[currentInstruction]].pfn = total_pf - free_pf_count;
			free_pf_count--;
		}
		else {
			//无空闲页面，寻找一个页面去替换
			//初始化所有页面的access_distance
			for (int i = 0; i < total_pf; i++) access_distance[i] = -1;
			//从当前页向后对每一页面计算access_distance
			for (int targetInstruction = currentInstruction + 1; targetInstruction < total_instruction; targetInstruction++) {
				int pfn = pl[page[targetInstruction]].pfn;
				if (pfn == INVALID || access_distance[pfn] != -1) continue;
				access_distance[pfn] = targetInstruction - currentInstruction;
			}
			//寻找access_distance最大的页
			int maxDistance = 0;
			for (int i = 0; i < total_pf; i++) {
				if (access_distance[i] > maxDistance) {
					maxDistance = access_distance[i];
					replace_pfn = i;
				}
			}
			//进行替换
			//旧页换出
			for (int i = 0; i < total_vp; i++) {
				if (pl[i].pfn == replace_pfn) pl[i].pfn = INVALID;
			}
			//新页换入
			pl[page[currentInstruction]].pfn = replace_pfn;
		}
	}
	printf("OPT:%6.4f  ", 1 - (float)diseffect / 320);
}

void LFU(int total_pf) {
	initialize(total_pf);
	int free_pf_count = total_pf;
	int replace_pf = 0;
	int time_for_clear_period = 0;
	for (int currentInstruction = 0; currentInstruction < total_instruction; currentInstruction++) {
		//页面失效
		if (pl[page[currentInstruction]].pfn == INVALID) {
			diseffect += 1;
			if (free_pf_count > 0) {
				pl[page[currentInstruction]].pfn = total_pf - free_pf_count;
				free_pf_count--;
			}
			else {
				//检索counter最小的且在内存中的页
				//初始化replace的页号，设置为第一个在内存中的页，然后开始向后进行比较，找到counter最小的页
				for (int i = 0; i < total_instruction; i++) {
					if (pl[page[i]].pfn != INVALID) {
						replace_pf = page[i];
						break;
					}
				}
				for (int i = replace_pf + 1; i < total_instruction; i++) {
					if (pl[page[i]].pfn != INVALID && pl[page[i]].counter < pl[replace_pf].counter) {
						replace_pf = page[i];
					}
				}
				//载入本次要访问的页
				pl[page[currentInstruction]].pfn = pl[replace_pf].pfn;
				pl[page[currentInstruction]].counter = 0;
				//释放将要替换的页
				pl[replace_pf].pfn = INVALID;
				pl[replace_pf].counter = 0;
			}
		}
		else {
			pl[page[currentInstruction]].counter++;
		}
		//时间周期递增
		time_for_clear_period += 1;
		//到达清零周期则把所有指令的counter清零
		if (time_for_clear_period >= clear_period) {
			for (int i = 0; i < total_instruction; i++) {
				pl[page[i]].counter = 0;
			}
		}
	}
	printf("LFU:%6.4f  ", 1 - (float)diseffect / 320);
}
typedef struct CLOCK_Control {
    int pn;
    bool accessedRecently;
} CLOCK_Control;
void CLOCK(int total_pf) {
	CLOCK_Control control[total_pf];
	int current = 0;
	initialize(total_pf);
	//初始化控制数组
	for (int i = 0; i < total_pf; i++) {
		control[i].pn = INVALID;
		control[i].accessedRecently = false;
	}
	for (int currentInstruction = 0; currentInstruction < total_instruction; currentInstruction++) {
		//页面失效
		if (pl[page[currentInstruction]].pfn == INVALID) {
			diseffect += 1;
			bool loaded = false;
			//检查是否有空页面
			for (int i = 0; i < total_pf; i++) {
				if (control[(current + i) % total_pf].pn == INVALID) {
					current = (current + i) % total_pf;
					pl[page[currentInstruction]].pfn = current;
					control[current].pn = pl[page[currentInstruction]].pn;
					control[current].accessedRecently = true;
					loaded = true;
					break;
				}
			}
			if (loaded) continue;
			//移回current
			current = (current + 1) % total_pf;
			//所有内存页面均已载入，此时需要找出一块进行替换
			while (control[current].accessedRecently != false) {
				control[current].accessedRecently = false;
				current = (current + 1) % total_pf;
			}
			//找到了页面的位置，进行替换
			pl[control[current].pn].pfn = INVALID;
			control[current].pn = page[currentInstruction];
			control[current].accessedRecently = true;
		}
	}
	printf("CLOCK:%6.4f  ", 1 - (float)diseffect / 320);
}