class Solution {
public:
	/**
	*  ����λ�϶�����������ż��λ�϶���ż��
	*  ���룺����arr�����ȴ���2
	*  len��arr�ĳ���
	*  ��arr����������λ�϶�����������ż��λ�϶���ż��
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