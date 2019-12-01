#include<algorithm>
#include<iostream>
using namespace std;
#include<vector>
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		sort(gifts.begin(), gifts.end());
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			if (gifts[i] == gifts[n / 2])
			{
				++count;
			}
		}
		if (count >= n / 2 + 1)
			return gifts[n / 2];
		else
			return 0;
	}
};

class Finder {
public:
	int findElement(vector<int> A, int n, int x) {
		// write code here
		int begin = 0;
		int end = n - 1;
		int mid = begin + (end - begin) / 2;
		while (begin <= end)
		{
			mid = begin + (end - begin) / 2;
			if (A[mid] == x)
			{
				return mid;
			}
			if (A[begin] < A[mid])
			{
				if (A[begin] <= x && x < A[mid])
				{
					end = mid - 1;
				}
				else
				{
					begin = mid + 1;
				}
			}
			else
			{
				if (A[mid] < x && x <= A[end])
				{
					begin = mid + 1;
				}
				else
				{
					end = mid - 1;
				}
			}
		}
	}
};




