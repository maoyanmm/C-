#include<iostream>
using namespace std;
#include<thread>
#include<mutex>

//ֻ���ڶ��ϴ�������
//1������˽�л�
//2�����еĹ��еľ�̬�����ӿ�ȥ�ڶ��ϴ���
//3��������
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
	/*HeapOnly(const HeapOnly& h)
	{
	*this = h;
	cout << "HeapOnly(const HeapOnly& h)" << endl;
	}*/
	HeapOnly(const HeapOnly& h) = delete;
private:
	HeapOnly()
	{
		cout << "HeapOnly()" << endl;
	}
	/*HeapOnly(const HeapOnly& h);*/

};

//ֻ����ջ�ϴ�������
//1������˽�л�
//2���ṩ���е�static�ӿ�ȥ��ջ�ϴ�������
//3���������NEW�Ĵ���
class StackOnly
{
public:
	//һ��
	/*static StackOnly* CreateObject()
	{
		StackOnly s;//������ʱ���������ص�����ʱ�����ĵ�ַ
		return &s;
	}*/

	//����
	static StackOnly CreateObject()
	{
		StackOnly s;
		return s;
	}

	//����
	/*static StackOnly CreateObject()
	{
		return StackOnly();
	}*/

	/*StackOnly(const StackOnly& s)
	{
		*this = s;
		cout << "StackOnly(const StackOnly& s)" << endl;
	}*/

private:
	StackOnly()
	{
		cout << "StackOnly()" << endl;
	}

	
	void* operator new(size_t size);
	void operator delete(void* p);
};

//����ģʽ��
//����ģʽ
//1�����캯��˽�л�
//2���������캯��˽�л�
//3����ֵ����˽�л�
//4������static������static�����������Ѿ�������static��Ա
class Singleton
{
public:
	static Singleton* GetSingleton()
	{
		return &_s;
	}
	Singleton(const Singleton& s) = delete;
	Singleton& operator=(const Singleton& s) = delete;
private:
	Singleton()
	{
		cout << "Singleton()" << endl;
	}
	/*Singleton(const Singleton& s);
	Singleton& operator=(const Singleton& s);*/
	static Singleton _s;
};
Singleton Singleton::_s;

//����ģʽ
//1�����캯��˽�л�
class Singleton2
{
public:
	static Singleton2* Getsingleton2()
	{
		if (_s == nullptr)//���Ч��
		{
			_mtx.lock();
			if (_s == nullptr)//��֤�̰߳�ȫ
			{
				_s = new Singleton2;
				cout << "static Singleton2* Getsingleton2()" << endl;
			}
			_mtx.unlock();
		}

		//if (_s == nullptr)
		//{
		//	_s = new Singleton2;
		//	cout << "static Singleton2* Getsingleton2()" << endl;
		//}
		return _s;
	}
	class Garbage
	{
	public:
		~Garbage()//���������static Garbage _gab;
		{
			delete _s;
			_s = nullptr;
		}
	};

	/*~Singleton2()
	{
		if (_s)
		{
			delete _s;
			_s = nullptr;
		}
	}*/
private:
	Singleton2()
	{
		cout << "Singleton2()" << endl;
	}
	Singleton2(const Singleton2& s);//������

	static Singleton2* _s;
	static mutex _mtx;
	static Garbage _gab;
};
Singleton2* Singleton2::_s = nullptr;
mutex Singleton2::_mtx;
Singleton2::Garbage Singleton2::_gab;
