#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<assert.h>

class String
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;
	friend ostream& operator<<(ostream& _cout, const String& str);
	//��������Ԫ��������Ϊ����ǳ�Ա��������ô<<���Ҳ������͹涨��*this�ˣ���û����cout������ˣ���������Ԫ�ȿ�����*this��������������ֿ��Է���˽�г�Ա
	void Swap(String& str)
	{
		swap(_str, str._str);
		swap(_capacity, str._capacity);
		swap(_size, str._size);
	}

	String(const char* str = "")
	{
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		_capacity = strlen(_str);
		_size = strlen(_str);
		/*cout << "String(const char* str = "")" << endl;*/
	}

	String(const String& str)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String s(str._str);//�ù��캯��������ʱ������Ȼ�󽻻�*this����ʱ��������Դ
		/*cout << "String(const String& str)" << endl;*/
		Swap(s);
	}

	int capacity()
	{
		return _capacity;
	}

	int size()
	{
		return _size;
	}

	~String()
	{
		if (_str)
		{
			_capacity = 0;
			_size = 0;
			delete[] _str;
			_str = nullptr;
		}
	}

	String& operator=(String str)//�����Ǵ���ֵ������������ʱ��ͻ�ִ��һ�ο�������
	{
		Swap(str);//�����������ľֲ�������*this������Դ
		return *this;
	}

	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}

	const char& operator[](size_t pos)const
	{
		assert(pos < _size);//�ж������ֵ�Ƿ���Ч
		return _str[pos];
	}

	iterator begin()
	{
		return _str;
	}

	iterator end()
	{
		return _str + _size;
	}

	const iterator begin()const
	{
		return _str;
	}

	const iterator end()const
	{
		return _str + _size;
	}

	const_iterator cbegin()const
	{
		return _str;
	}

	const_iterator cend()const
	{
		return _str + _size;
	}

	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];//���¿ռ�
			strcpy(tmp, _str);//����ԭ��������
			delete[] _str;//�ͷ�ԭ���Ŀռ�
			_str = tmp;//��ָ��ָ���¿��Ŀռ�
			_capacity = n;//��������
		}
	}

	void resize(size_t sz, char c = '\0')
	{
		if (sz > _capacity)//���sz>capacity�����ݡ���size--capacity�����ݱ��c������_size�������һλ���'\0'
		{
			reserve(sz);
		}
		if (sz > _size)//���_size<sz<capacity:��size--capacity�����ݱ��c������_size�������һλ���'\0'
		{
			memset(_str + _size, c, sz - _size);
		}
		_size = sz;//���sz < _size������_size�������һλ���'\0'�����ǲ���ɾ��Ԫ�أ������ͷſռ䣩
		_str[_size] = '\0';
	}

	const char* c_str()const
	{
		return _str;
	}

	void Insert(size_t pos, char c)
	{
		assert(pos <= _size);
		if (_size == _capacity)//��������
		{
			size_t newc = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newc);
		}
		size_t end = _size + 1;
		while (end > pos)//��ǰ�����ƶ�Ԫ��
		{
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = c;//����Ԫ��
		++_size;
	}

	void Insert(size_t pos, const char* c)
	{
		assert(pos <= _size);
		int sz = strlen(c);
		if (_size + sz > _capacity)//�����ĳ�����������������
		{
			size_t newc = sz + _size;
			reserve(newc);
		}
		size_t end = _size + sz;
		while (end > pos + sz - 1)//��ǰ����ֵ���ƶ�Ԫ��
		{
			_str[end] = _str[end - sz];
			end--;
		}
		while (*c)//�����ַ���
		{
			_str[pos] = *c++;
			pos++;
		}
		_size += sz;
	}

	String& operator+=(char c)
	{
		(*this).push_back(c);
		return *this;
	}

	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}

	String& operator+=(const String& str)
	{
		Append(str._str);
		return *this;
	}

	void push_back(char c)
	{
		(*this).Insert(_size, c);
	}

	void Append(const char* str)
	{
		(*this).Insert(_size, str);
	}

	void erase(size_t pos, int len)// h  e  l  l  o  x  l  \0      pos = 2 , len = 2 --> h e o x l \0
	{                           //  0  1  2  3  4  5  6  7
		//���ɾ�����ȳ������һ��Ԫ�أ���ֱ�Ӱ�pos���\0
		if (pos + len >= _size)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{ //�Ӻ���ǰ��ֵ
			int begin = pos + len;
			while (begin <= _size)
			{
				_str[pos++] = _str[begin++];
			}
			_size -= len;
		}
	}

	void erase(iterator it)
	{
		int pos = it - _str;
		erase(pos, 1);
	}

	size_t find(const char* str, size_t pos = 0)//abc abcde df    abcd
	{
		size_t _begin = pos;
		size_t _end = pos;
		size_t begin = 0;
		while (_begin < _size)
		{
			if (_str[_begin] == str[begin])
			{

				while (_str[_end] == str[begin] && begin < strlen(str) && _end < _size)
				{
					++_end;
					++begin;
				}
				if (begin == strlen(str))
				{
					return _begin;
				}
			}
			_begin++;
			_end = _begin;
			begin = 0;
		}
		return npos;
	}

	size_t find(char c, size_t pos = 0)
	{
		for (int i = pos; i < _size; ++i)
		{
			if (c == _str[i])
			{
				return i;
			}
		}
		return npos;
	}

private:
	char* _str;
	size_t _capacity;
	size_t _size;
	static const size_t npos;
};

const size_t String::npos = -1;

ostream& operator<<(ostream& _cout, const String& str)
{
	_cout << str._str;
	/*for (const auto& ch : str)
	{
	_cout << ch;
	}*/
	return _cout;
}

int main()
{
	/*String s1("hello");*/
	/*cout << s1 << endl;
	cout << s1.Forcapacity() << endl;
	cout << s1.Forsize() << endl;
	String s2(s1);
	cout << s2 << endl;
	cout << s2.Forcapacity() << endl;
	cout << s2.Forsize() << endl;*/

	/*const String s1("hello");
	String::const_itrator sit = s1.begin();
	*sit = 'x';
	cout << s1 << endl;*/

	/*String s1("hello");
	String::const_itrator sit = s1.begin();
	cout << *sit << endl;*/
	/*const String s1("hello");
	String::const_itrator sit = s1.cbegin();*/
	/*const String s1("hello");
	*s1.c_str() = '1';*/
	/*s1.reserve(3);*/
	/*int a = int();
	cout << a << endl;*/
	//String s;
	/*s.Insert(0, '2');
	s.Insert(0, '1');
	s.Insert(2, '3');
	cout << s << endl;*/
	/*String s;
	s.reserve(20);
	s.Insert(0, "hello");
	cout << s << endl;*/
	/*string s("hello");
	s.insert(s.begin(), 'x');
	s.erase(s.begin());
	cout << s << endl;*/
	/*int m = 83;
	printf("%x\n", m);*/
	/*String s("hello");
	cout << s << endl;*/
	/*String s("hello");
	s.Append("sss");
	cout << s << endl;*/
	String s("abcabcdqwe");
	size_t ret = s.find("abcd", 1);
	cout << ret << endl;
	system("pause");
	return 0;
}