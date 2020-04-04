#include<iostream>
#include<vector>
using namespace std;
class BitMap
{
private:
	vector<int> _table;
public:
	BitMap(size_t range)
	{
		//>>5是因为：一个字节32位，>>5相当于除以32。+1是因为：如果不是32的倍数，多出来的也要计算，例如33/32 =1，实际应该要2个字节来算
		_table.resize((range >> 5) + 1);
	}
	void set(int data)
	{
		//算出数组的下标
		size_t int_index = data >> 5;
		//算出一个字节里的比特位位置
		size_t bit_index = (data % 32);
		//或上1，就表示有这个数了
		_table[int_index] |= (1 << bit_index);
	}
	bool find(int data)
	{
		//算出数组的下标
		size_t int_index = data >> 5;
		//算出一个字节里的比特位位置
		size_t bit_index = (data % 32);
		//看那一比特位是否是1
		return ((_table[int_index] >> bit_index) & 1);
	}
	void reset(int data)
	{
		//算出数组的下标
		size_t int_index = data >> 5;
		//算出一个字节里的比特位位置
		size_t bit_index = (data % 32);
		//将那一位与0，其他位这时是与的1（但是与1对其他位没影响）
		_table[int_index] &= ~(1 << bit_index);
	}
};

void test()
{
	BitMap bm(777);
	bm.set(677);
	bm.set(15);
	bm.set(43);
	bool ret = bm.find(11);
	ret = bm.find(15);
	ret = bm.find(43);
	ret = bm.find(100);
	bm.reset(15);
	ret = bm.find(15);
}

int main()
{
	test();
	system("pause");
	return 0;
}