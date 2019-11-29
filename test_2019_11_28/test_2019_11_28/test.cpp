#include<iostream>
using namespace std;
#include<string>
#include<vector>

	vector<int> singleNumber(vector<int>& nums) {
		int ans = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			ans = ans ^ nums[i];
		}
		int flag = 0;
		while (((ans >> flag)&1) != 1)
		{
			++flag;
			/*ans = ans >> flag;*/
		}
		vector<int> ans1;
		vector<int> ans2;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (((nums[i] >> flag) & 1) == 1)
			{
				ans1.push_back(nums[i]);
			}
			else if (((nums[i] >> flag) & 1) == 0)
			{
				ans2.push_back(nums[i]);
			}
		}
		int result1 = 0;
		int result2 = 0;
		for (int i = 0; i < ans1.size(); ++i)
		{
			result1 ^= ans1[i];
		}
		for (int i = 0; i < ans2.size(); ++i)
		{
			result2 ^= ans2[i];
		}
		vector<int> vv;
		vv.push_back(result1);
		vv.push_back(result2);
		return vv;
	}

	int main()
	{
		vector<int> nums;
		nums.push_back(1);
		nums.push_back(2);
		nums.push_back(1);
		nums.push_back(3);
		nums.push_back(2);
		nums.push_back(5);
		vector<int> result = singleNumber(nums);
		for (int i = 0; i < result.size(); ++i)
		{
			cout << result[i] << ' ';
		}
		cout << endl;
		system("pause");
		return 0;
	}

//int main()
//{
//	string str1, str2;
//	while (cin >> str1 >> str2)
//	{
//		int maxcount = 0;
//		int flag = 0;
//		if (str1.size() > str2.size())
//		{
//			swap(str1, str2);
//		}
//		for (int i = 0; i < str1.size(); ++i)
//		{
//			for (int j = 0; j < str2.size(); ++j)
//			{
//				if (str1[i] == str2[j])
//				{
//					int tmpi = i;
//					int tmpj = j;
//					int count = 0;
//					while (tmpi < str1.size() && tmpj < str2.size() && str1[tmpi] == str2[tmpj])
//					{
//						++count;
//						++tmpi;
//						++tmpj;
//					}
//					if (count > maxcount)
//					{
//						maxcount = count;
//					}
//					if (tmpi == str1.size())
//					{
//						flag = 1;
//						break;
//					}
//				}
//			}
//			if (1 == flag)
//			{
//				break;
//			}
//		}
//		cout << maxcount << endl;
//	}
//	return 0;
//}