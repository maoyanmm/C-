class Solution {
public:
	/**
	*  奇数位上都是奇数或者偶数位上都是偶数
	*  输入：数组arr，长度大于2
	*  len：arr的长度
	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	*/
	void Swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int ji = 0;
		int ou = 0;
		for (int i = 0; i < len; ++i)
		{
			if (arr[i] % 2 == 0)
			{
				++ou;
			}
			else
			{
				++ji;
			}
		}
		int i = 0;
		int j = 0;
		if (ji > ou)
		{
			i = 1;
			j = 0;
			for (; i < len; i += 2)
			{
				if (arr[i] % 2 == 0)
				{
					for (; j < len; j += 2)
					{
						if (arr[j] % 2 == 1)
						{
							Swap(arr[i], arr[j]);
							j += 2;
							break;
						}
					}
				}
			}
		}
		else
		{
			i = 0;
			j = 1;
			for (; i < len; i += 2)
			{
				if (arr[i] % 2 == 1)
				{
					for (; j < len; j += 2)
					{
						if (arr[j] % 2 == 0)
						{
							Swap(arr[i], arr[j]);
							j += 2;
							break;
						}
					}
				}
			}
		}
	}
};