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
		//>>5����Ϊ��һ���ֽ�32λ��>>5�൱�ڳ���32��+1����Ϊ���������32�ı������������ҲҪ���㣬����33/32 =1��ʵ��Ӧ��Ҫ2���ֽ�����
		_table.resize((range >> 5) + 1);
	}
	void set(int data)
	{
		//���������±�
		size_t int_index = data >> 5;
		//���һ���ֽ���ı���λλ��
		size_t bit_index = (data % 32);
		//����1���ͱ�ʾ���������
		_table[int_index] |= (1 << bit_index);
	}
	bool find(int data)
	{
		//���������±�
		size_t int_index = data >> 5;
		//���һ���ֽ���ı���λλ��
		size_t bit_index = (data % 32);
		//����һ����λ�Ƿ���1
		return ((_table[int_index] >> bit_index) & 1);
	}
	void reset(int data)
	{
		//���������±�
		size_t int_index = data >> 5;
		//���һ���ֽ���ı���λλ��
		size_t bit_index = (data % 32);
		//����һλ��0������λ��ʱ�����1��������1������λûӰ�죩
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