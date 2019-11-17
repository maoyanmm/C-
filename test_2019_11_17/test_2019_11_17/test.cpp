#include<list>
#include<iostream>
using namespace std;

#include<iostream>
using namespace std;
#include<string>
#include<vector>
int main()
{
	int n;
	cin >> n;
	vector<string> v;
	v.resize(n);
	for (auto& str : v)
	{
		cin >> str;
	}
	bool lon = true;
	bool dic = true;
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i].size() < v[i - 1].size())
		{
			lon = false;
			break;
		}
	}
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i] < v[i - 1])
		{
			dic = false;
			break;
		}
	}
	if (dic && lon)
	{
		cout << "both" << endl;
	}
	else if (dic && !lon)
	{
		cout << "lexicographically" << endl;
	}
	else if (!dic && lon)
	{
		cout << "lengths" << endl;
	}
	else
	{
		cout << "none" << endl;
	}
	return 0;
}

class LCA {
public:
	int getLCA(int a, int b)
	{
		// write code here
		int child1 = a > b ? a : b;
		int child2 = a > b ? b : a;
		while (child1 != child2)
		{
			if (child1 > child2)
			{
				child1 /= 2;
			}
			else
			{
				child2 /= 2;
			}
		}
		return child1;
	}
};

int main()
{
	list<int> l1;
	l1.emplace_back(1);
	l1.emplace(l1.end(), 2);
	/*for (auto& ch : l1)
	{
		cout << ch << endl;
	}*/
	list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	system("pause");
	return 0;
}

#include<iostream>
using namespace std;
int main()
{
	int a;
	while (cin >> a)
	{
		int count = 0;
		int max = 0;
		while (a)
		{
			if ((a & 1) == 1)
			{
				++count;
				if (count > max)
				{
					max = count;
				}
			}
			else
			{
				count = 0;
			}
			a = a >> 1;
		}
		cout << max << endl;
	}
	return 0;
}