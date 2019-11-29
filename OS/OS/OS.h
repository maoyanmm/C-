#include<iostream>
using namespace std;
#include<vector>
//ABC
//015
//312
//
//033
//242
void FCFS(vector<int>& a, vector<int>& s)
{
	vector<int> arrive(a);
	vector<int> service(s);
	cout << "FCFS()" << endl;
	vector<int> complete_time;//表示完成时间
	vector<int> cycling_time;//表示周转时间
	vector<double> bring_cycling_time;//表示代权周转时间
	const int size = arrive.size();
	complete_time.resize(size);
	cycling_time.resize(size);
	bring_cycling_time.resize(size);
	int over = 0;//表示结束了多少个进程
	int time = 0;//表示当前时间点
	while (over != size)
	{
		int flag = 0;
		for (int i = 0; i < size; ++i)
		{
			if (arrive[i] <= time && service[i] > 0)
			{
				time += service[i];
				service[i] = 0;
				++over;
				complete_time[i] = time;
				cycling_time[i] = complete_time[i] - arrive[i];
				bring_cycling_time[i] = (double)cycling_time[i] / (double)s[i];
				flag = 1;
			}
		}
		if (0 == flag)
		{
			++time;
		}
	}
	//ABC
	//015
	//312
	//
	//033
	//242
	cout << "进程序号：     ";
	for (int i = 0; i < size; ++i)
	{
		printf("%7c   ", 'A' + i);
	}
	cout << endl;
	cout << "服务时间：     ";
	for (int i = 0; i < size; ++i)
	{
		printf("%7d   ", s[i]);
	}
	cout << endl;
	cout << "到达时间：     ";
	for (int i = 0; i < size; ++i)
	{
		printf("%7d   ", a[i]);
	}
	cout << endl;
	cout << "完成时间：     ";
	for (int i = 0; i < size; ++i)
	{
		printf("%7d   ", complete_time[i]);
	}
	cout << endl;
	cout << "周转时间：     ";
	for (int i = 0; i < size; ++i)
	{
		printf("%7d   ", cycling_time[i]);
	}
	cout << endl;
	cout << "带权周转时间：  ";
	for (int i = 0; i < size; ++i)
	{
		printf("%f   ", bring_cycling_time[i]);
	}
	cout << endl;
}
void SJF(vector<int>& arrive, vector<int>& service)
{
	cout << "SJF()" << endl;
}
void RR(vector<int>& a,vector<int>& s)
{
	vector<int> arrive(a);
	vector<int> service(s);
	cout << "RR()" << endl;
	cout << "请输入时间片时间：" << endl;
	int q;
	cin >> q;
	vector<int> complete_time;//表示完成时间
	vector<int> cycling_time;//表示周转时间
	vector<double> bring_cycling_time;//表示代权周转时间
	const int size = arrive.size();
	complete_time.resize(size);
	cycling_time.resize(size);
	bring_cycling_time.resize(size);
	int over = 0;//表示结束了多少个进程
	int time = 0;//表示当前时间点
	while (over != size)
	{
		int flag = 0;
		for (int i = 0; i < size; ++i)
		{
			if (arrive[i] <= time)
			{	
				if (service[i] > 0)
				{
					int tmpq = q;
					int tmptime = 0;
					while (service[i] > 0 && tmpq > 0)
					{
						--(service[i]);
						--(tmpq);
						++tmptime;
					}
					flag = 1;
					time += tmptime;
					if (0 == service[i])
					{
						++over;
						complete_time[i] = time;
						cycling_time[i] = complete_time[i] - arrive[i];
						bring_cycling_time[i] = (double)cycling_time[i] / (double)s[i];
					}
				}
			}
		}
		if (0 == flag)
		{
			++time;
		}
	}
	cout << "进程序号：     ";
	for (int i = 0; i < size; ++i)
	{
		printf("%7c   ", 'A'+i);
	}
	cout << endl;
	cout << "服务时间：     ";
	for (int i = 0; i < size; ++i)
	{
		printf("%7d   ", s[i]);
	}
	cout << endl;
	cout << "到达时间：     ";
	for (int i = 0; i < size; ++i)
	{
		printf("%7d   ", a[i]);
	}
	cout << endl;
	cout << "完成时间：     ";
	for (int i = 0; i < size; ++i)
	{
		printf("%7d   ", complete_time[i]);
	}
	cout << endl;
	cout << "周转时间：     ";
	for (int i = 0; i < size; ++i)
	{
		printf("%7d   ", cycling_time[i]);
	}
	cout << endl;
	cout << "带权周转时间：  ";
	for (int i = 0; i < size; ++i)
	{
		printf("%7f   ", bring_cycling_time[i]);
	}
	cout << endl;
}