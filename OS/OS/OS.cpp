#include"OS.h"

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	cout << "������������̵ĵ���ʱ��ͷ���ʱ��" << endl;
	cout << "���� -1 ��������" << endl;
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
		cout << "  ---�����㷨---" << endl;
		cout << "1.-----FCFS-----" << endl;
		cout << "2.-----SJF------" << endl;
		cout << "3.------RR------" << endl;
		cout << "������ѡ��1��2��3" << endl;
		cout << "����0�˳�" << endl;
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
			cout << "����������������룡" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}