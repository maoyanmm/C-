#include<iostream>
using namespace std;
#include<thread>
#include<mutex>

//只能在堆上创建对象
//1、构造私有化
//2、类中的共有的静态函数接口去在堆上创建
//3、防拷贝
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

//只能在栈上创建对象
//1、构造私有化
//2、提供共有的static接口去在栈上创建对象
//3、或者阻断NEW的创建
class StackOnly
{
public:
	//一：
	/*static StackOnly* CreateObject()
	{
		StackOnly s;//错误：临时变量，返回的是临时变量的地址
		return &s;
	}*/

	//二：
	static StackOnly CreateObject()
	{
		StackOnly s;
		return s;
	}

	//三：
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

//单例模式：
//饿汉模式
//1、构造函数私有化
//2、拷贝构造函数私有化
//3、赋值函数私有化
//4、创建static变量和static函数来返回已经创建的static成员
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

//懒汉模式
//1、构造函数私有化
class Singleton2
{
public:
	static Singleton2* Getsingleton2()
	{
		if (_s == nullptr)//提高效率
		{
			_mtx.lock();
			if (_s == nullptr)//保证线程安全
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
		~Garbage()//当最下面的static Garbage _gab;
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
	Singleton2(const Singleton2& s);//防拷贝

	static Singleton2* _s;
	static mutex _mtx;
	static Garbage _gab;
};
Singleton2* Singleton2::_s = nullptr;
mutex Singleton2::_mtx;
Singleton2::Garbage Singleton2::_gab;
