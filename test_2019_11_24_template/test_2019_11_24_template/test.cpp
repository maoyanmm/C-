#include<iostream>
using namespace std;

template<size_t N>
struct Sum
{
	enum{
		RET = N + Sum<N>::RET;
	};
};

template<>
struct Sum<1>
{

};

int main()
{

}

#include<iostream>
#include<string>
using namespace std;
#include<vector>
int New_YangHuiArray(vector<vector<int>>& vv, int n)
{
	int con = 1;
	vv[0].resize(con);
	vv[0][0] = 1;
	for (int i = 1; i < n; ++i)
	{
		con += 2;
		vv[i].resize(con, 0);
		for (int j = 0; j < con; ++j)
		{
			if (j - 2 >= 0 && j - 2 <= vv[i - 1].size() - 1)
				vv[i][j] += vv[i - 1][j - 2];
			if (j - 1 >= 0 && j - 1 <= vv[i - 1].size() - 1)
				vv[i][j] += vv[i - 1][j - 1];
			if (j >= 0 && j <= vv[i - 1].size() - 1)
				vv[i][j] += vv[i - 1][j];
		}
	}
	for (int i = 1; i < con; ++i)
	{
		if (vv[n - 1][i] % 2 == 0)
		{
			return i + 1;
		}
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<int>> vv;
		vv.resize(n);
		int ret = New_YangHuiArray(vv, n);
		cout << ret << endl;
	}
	

	return 0;
}


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void LongIntAdd(string& str1, string& str2, string& ans)
{
	int flag = 0;
	int i = str1.size() - 1;
	int j = str2.size() - 1;
	while (i >= 0 && j >= 0)
	{
		int left = str1[i] - '0';
		int right = str2[j] - '0';
		int sum = left + right + flag;
		if (sum > 9)
		{
			flag = 1;
			sum -= 10;
		}
		else
		{
			flag = 0;
		}
		ans += (sum + '0');
		--i;
		--j;
	}
	while (j >= 0)
	{
		int sum = 0;
		sum += str2[j] - '0' + flag;
		if (sum > 9)
		{
			flag = 1;
			sum -= 10;
		}
		else
		{
			flag = 0;
		}
		ans += (sum + '0');
		--j;
	}
	while (i >= 0)
	{
		int sum = 0;
		sum += str1[i] - '0' + flag;
		if (sum > 9)
		{
			flag = 1;
			sum -= 10;
		}
		else
		{
			flag = 0;
		}
		ans += (sum + '0');
		--i;
	}
	if (flag == 1)
	{
		ans += '1';
	}
	reverse(ans.begin(), ans.end());
}

int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		int maxsize = str1.size() > str2.size() ? str1.size() + 2 : str2.size() + 2;
		string ans;
		ans.reserve(maxsize);
		LongIntAdd(str1, str2, ans);
		cout << ans << endl;
	}
	return 0;
}