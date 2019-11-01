#include<iostream>
#include<assert.h>
using namespace std;

//template<typename T>
//template<class T>
//void Swap(T& c,T& d)
//{
//	T tmp = c;
//	c = d;
//	d = tmp;
//}

template<typename T1,typename T2>
void Swap(const T1& c,const T2& d)//c=1 d=2.2
{
	T1 tmp = c;
	c = d;//将d强转为int型，用这个强转后的匿名临时变量给c赋值
	d = tmp;
}

template<typename T>
T Add(const T& c,const T& d)
{
	return c + d;
}

//template<typename T1,typename T2>
//T2 Add(const T1& c,const T2& d)
//{
//	return c + d;
//}

template<typename T>
class Seqlist
{
public:
	Seqlist(size_t capicity = 10)
		:_data(new T[10])
		, _size(0)
		, _capicity(capicity)
	{
	}
	~Seqlist();
	
	T operator[](size_t n)//a[i]
	{
		assert(n < _size);
		return _data[n];
	}

	void display();

	void PushBack(const T& data)
	{
		if (_capicity == _size)
		{
			_capicity = 2 * _capicity;
			_data = (T*)realloc(_data, sizeof(T)*_capicity);
		}
		_data[_size] = data;
		++_size;
	}
private:
	T* _data;
	size_t _size;
	size_t _capicity;
};

template<typename T>
Seqlist<T>::~Seqlist()
{
	_size = 0;
	_capicity = 0;
	if (_data)
	delete[] _data;
	_data = nullptr;
}

template<typename T1>
Seqlist<T1>::display()
{
	cout << "hello" << endl;
}


void test()
{
	int a = 1;
    int b = 2;
	double c = 2.2;
	Seqlist<int> s;
	/*for (int i = 0; i < 5; i++)
	{
		s1.PushBack(i);
	}
	for (int i = 0; i < 22; i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;*/
	/*Add(a, b);
	Add(1, 2);*/
	/*Add(1, 2);*/
	/*Add(1,2.1);*/
	/*Add(1, 2);*/
	/*int& x = a;
	x = c;*/
	/*Swap(a, b);*/
	/*Add<double>(a,c);*/
	/*Add(a, (int)c);*/
	/*Add(a, c);*/
	/*Swap(a, b);*/
	/*Swap(a, c);*/
}

int main()
{
	test();
	system("pause");
	return 0;
}