#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

typedef struct processControl {
public:
	processControl(int i,int arrive,int est)
	:id(i),arriveTime(arrive),estimatedTime(est),timeLeft(est), status(false)
	{
		
	}

	int id;
	int arriveTime;
	int estimatedTime;
	int timeLeft;
	int doneTime;
	bool status;
} processControl;

struct compareEstTime
{
	bool operator()(const processControl* p1, const processControl* p2)
	{
		return p1->estimatedTime < p2->estimatedTime;
	}
};

using TaskSet=multimap <int, processControl>;

void printResult(TaskSet& tasks) {
	int roundTimeSum = 0;
	int serviceTimeSum = 0;
	double weightedRoundTimeSum = 0;
	for (auto it = tasks.begin(); it != tasks.end();++it) {
		auto& task = it->second;
		int roundTime = task.doneTime - task.arriveTime;
		double weightedRoundTime = (double)roundTime / task.estimatedTime;
		std::cout << "Process " << task.id << ": round time " << roundTime << ", weighted round time: " << weightedRoundTime << endl;
		roundTimeSum += roundTime;
		serviceTimeSum += task.estimatedTime;
		weightedRoundTimeSum += weightedRoundTime;
	}
	cout << "Total: Average Round Time: " << roundTimeSum / (double)tasks.size() << ", Average Weighted Round Time:" << weightedRoundTimeSum / tasks.size() << endl;
}

void FCFS(TaskSet tasks) {
	int currentTime = 0,finishedProc=0;
	queue<processControl*> queue;
	while (finishedProc!=tasks.size())
	{
		if(!queue.empty())
		{
			auto curTask = queue.front();
			curTask->timeLeft--;
			if (curTask->timeLeft == 0)
			{
				curTask->status = true;
				curTask->doneTime = currentTime;
				queue.pop();
				finishedProc++;
			}

		}
		auto it = tasks.find(currentTime);
		if (it != tasks.end())
		{
			while (it->second.arriveTime == currentTime)
			{
				queue.push(&(it++->second));
			}
		}
		currentTime++;
	}
	cout << "* * * * * * * * FCFS * * * * * * * *" << endl;
	printResult(tasks);
	cout << "* * * * * * * * FCFS * * * * * * * *" << endl;
}

void SPN(TaskSet tasks) {
	int currentTime = 0,finishedProc=0;
	multiset<processControl*,compareEstTime> waitingList;
	processControl* curTask = nullptr;
	while (finishedProc!=tasks.size())
	{
		if(curTask!=nullptr)
		{
			curTask->timeLeft--;
			if (curTask->timeLeft == 0)
			{
				curTask->status = true;
				curTask->doneTime = currentTime;
				finishedProc++;
				if(!waitingList.empty())
				{
					curTask = *waitingList.begin();
					waitingList.erase(waitingList.begin());
				}
			}
		}
		auto it = tasks.find(currentTime);
		if (it != tasks.end())
		{
			while (it->second.arriveTime == currentTime)
			{
				waitingList.insert(&(it++->second));
			}
			if(curTask==nullptr)
			{
				curTask = *waitingList.begin();
				waitingList.erase(waitingList.begin());
			}
		}
		currentTime++;

	}
	cout << "* * * * * * * * SPN * * * * * * * *" << endl;
	printResult(tasks);
	cout << "* * * * * * * * SPN * * * * * * * *" << endl;
}

void RR(TaskSet tasks) {
	int timeSlice,finishedProc=0,curTime=0;
	cout << "Please input time slice for RR:";
	cin >> timeSlice;
	queue<processControl*> queue;
	while (finishedProc!=tasks.size()) {
		int timeUsed = 1;
		auto it = tasks.find(curTime);
		if (it != tasks.end())
		{
			while (it->second.arriveTime == curTime)
			{
				queue.push(&(it++->second));
			}
		}
		if(!queue.empty())
		{
			auto curTask = queue.front();
			queue.pop();
			if(curTask->timeLeft<=timeSlice)
			{
				timeUsed = curTask->timeLeft;
				curTask->status = true;
				curTask->doneTime = curTime + curTask->timeLeft;
				curTask->timeLeft = 0;
				curTask = nullptr;
				finishedProc++;
			}else
			{
				curTask->timeLeft -= timeSlice;
				timeUsed = timeSlice;
				
			}
			for (int i = curTime+1; i < curTime + timeUsed; ++i)
			{
				auto it1 = tasks.find(i);
				if (it1 != tasks.end())
				{
					while (it1->second.arriveTime == i)
					{
						queue.push(&(it1++->second));
					}
				}
			}
			if(curTask!=nullptr)
			queue.push(curTask);
		}
		curTime += timeUsed;
	}
	cout << "* * * * * * * * RR * * * * * * * *" << endl;
	printResult(tasks);
	cout << "* * * * * * * * RR * * * * * * * *" << endl;
}




int main(int argc, const char* argv[]) {
	TaskSet task;
	int count;
	cout << "Please input the number of processes:";
	cin >> count;
	cout << "Please input the arrive time and the estimated service time of" << endl;
	for (int i = 0; i < count; i++) {
		int arriveTime, estimatedTime;
		cout << "Process " << (i + 1) << ":";
		cin >> arriveTime >> estimatedTime;
		task.insert(make_pair(arriveTime, processControl(i, arriveTime, estimatedTime)));
	}
	FCFS(task);
	SPN(task);
	RR(task);
	cin >> count;
	return 0;
}