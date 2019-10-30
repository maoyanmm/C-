#include"test.h"

void HeapOnlytest()
{
	/*HeapOnly h1;*/
	HeapOnly* h2 = HeapOnly::CreateObject();
	/*HeapOnly h3(*h2);*/
}

void StackOnlytest()
{
	/*StackOnly s;*/
	/*StackOnly *s = new StackOnly;*/
	StackOnly s2 = StackOnly::CreateObject();
	/*StackOnly s1 = new StackOnly;*/
}

void Singletontest1()
{
	/*Singleton* p1 = Singleton::GetSingleton();
	Singleton* p2 = Singleton::Get1Singleton();
	Singleton* p3 = Singleton::GetSingleton();*/
	Singleton* p2 = Singleton::GetSingleton();
	/*Singleton s(*p2);*/
	/*Singleton s = *p2;*/
}

void Singleton2test()
{
	/*Singleton2 s;*/
	Singleton2* s1 = Singleton2::Getsingleton2();
	Singleton2* s2 = Singleton2::Getsingleton2();
	Singleton2* s3 = Singleton2::Getsingleton2();
	Singleton2* s4 = Singleton2::Getsingleton2();
}

void func(int n)
{
	for (int i = 0; i < n; i++)
	{
		Singleton2* p = Singleton2::Getsingleton2();
	}
}

int main()
{
	/*HeapOnlytest();*/
	/*StackOnlytest();*/
	/*Singletontest1();*/
	//Singleton2test();
	int n;
	cin >> n;
	thread t1(func, n);
	thread t2(func, n);
	thread t3(func, n);
	thread t4(func, n);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	system("pause");
	return 0;
}