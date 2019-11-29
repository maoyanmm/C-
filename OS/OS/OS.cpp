#include"OS.h"

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	cout << "请输入各个进程的到达时间和服务时间" << endl;
	cout << "输入 -1 结束输入" << endl;
	vector<int> arrive_time;
	vector<int> service_time;
	int flag = 0;
	while (1)
	{
		int time;
		cin >> time;
		if (0 == flag && time >= 0)
		{
			arrive_time.push_back(time);
			flag = 1;
		}
		else if (1 == flag && time >= 0)
		{
			service_time.push_back(time);
			flag = 0;
		}
		else if (-1 == time)
		{
			break;
		}
	}
	for (int i = 0; i < arrive_time.size()-1; ++i)
	{
		for (int j = 0; j < arrive_time.size() - i - 1; ++j)
		{
			if (arrive_time[j] > arrive_time[j + 1])
			{
				swap(arrive_time[j], arrive_time[j + 1]);
				swap(service_time[j], service_time[j + 1]);
			}
		}
	}

	while (1)
	{
		cout << "  ---调度算法---" << endl;
		cout << "1.-----FCFS-----" << endl;
		cout << "2.-----SJF------" << endl;
		cout << "3.------RR------" << endl;
		cout << "请输入选项1、2或3" << endl;
		cout << "输入0退出" << endl;
		int n;
		cin >> n;
		if (0 == n)
		{
			break;
		}
		switch (n)
		{
		case 1:
			FCFS(arrive_time, service_time);
			break;
		case 2:
			SJF(arrive_time, service_time);
			break;
		case 3:
			RR(arrive_time, service_time);
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}