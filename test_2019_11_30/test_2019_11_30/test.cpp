#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>

using namespace std;
#include<vector>
#include<string>
#include<string.h>

struct ServerInfo
{
	char ip[100];
	int port;
};

class config
{
public:
	config(string filename = "laji")
		:_binaryFile(filename + ".cfg")
		, _textFile(filename + ".txt")
	{

	}
	void ReadText(ServerInfo& info)
	{
		ifstream fin(_textFile.c_str());
		fin >> info.ip;
		fin >> info.port;
		fin.close();
	}
	void WriteText(const ServerInfo& info)
	{
		ofstream fout(_textFile.c_str());
		fout << info.ip << endl;
		fout << info.port << endl;
		fout << "What are you doing" << endl;
		fout.close();
	}
	void ReadBin(ServerInfo& info)
	{
		ifstream fin(_binaryFile.c_str());
		fin.read((char*)&info, sizeof(ServerInfo));
		fin.close();
	}
private:
	string _binaryFile;
	string _textFile;
};


void testFile()
{
	/*ServerInfo info;
	config cfg;
	strcpy(info.ip, "198.169.123");
	info.port = 2088;
	cfg.WriteText(info);*/
	ofstream wenben("huile.txt");
	wenben << "知道了" << endl;
	wenben.close();
}

int main()
{

	testFile();
	system("pause");
	return 0;
}

////
////
////#include<iostream>
////#include<vector>
////using namespace std;
////
////int gcd(int a, int b)
////{
////	int tmp = a % b;
////	while (tmp)
////	{
////		a = b;
////		b = tmp;
////		tmp = a%b;
////	}
////	return b;
////}
////
////int main()
////{
////	int n, a;
////	while (cin >> n >> a)
////	{
////		vector<int> monster;
////		monster.resize(n);
////		for (int i = 0; i < n; ++i)
////		{
////			cin >> monster[i];
////		}
////		开始遍历怪物数组
////		for (int i = 0; i < n; ++i)
////		{
////			if (monster[i] <= a)
////			{
////				a += monster[i];
////			}
////			else
////			{
////				a += gcd(monster[i], a);
////			}
////		}
////		cout << a << endl;
////
////	}
////
////
////	return 0;
////}
////
////int main()
////{
////	int n;
////	cin >> n;
////	if (n <= 0)
////	{
////		cout << 0 << endl;
////		return 0;
////	}
////	vector<int> song;
////	song.resize(n);
////	string str;
////	cin >> str;
////	for (int i = 0; i < n; ++i)//将数组赋值为各个歌曲号
////	{
////		song[i] = i + 1;
////	}
////	vector<int> display;//在MP3上显示的数组
////	if (n > 4)
////	{
////		display.resize(4);
////		for (int i = 0; i < 4; ++i)//给显示的列表赋初值
////		{
////			display[i] = i + 1;
////		}
////		int flag = 0;//设置光标
////		for (int i = 0; i < str.size(); ++i)//开始读取指令
////		{
////			if (str[i] == 'U')
////			{
////				if (0 == flag)
////				{
////					flag = n - 1;
////					display[3] = song[flag];
////					display[2] = song[flag - 1];
////					display[1] = song[flag - 2];
////					display[0] = song[flag - 3];
////				}
////				else
////				{
////					if (song[flag] == display[0])
////					{
////						--flag;
////						display[0] = song[flag];
////						display[1] = song[flag + 1];
////						display[2] = song[flag + 2];
////						display[3] = song[flag + 3];
////					}
////					else
////					{
////						--flag;
////					}
////				}
////			}
////			else if (str[i] == 'D')
////			{
////				if (n - 1 == flag)
////				{
////					flag = 0;
////					display[0] = song[flag];
////					display[1] = song[flag + 1];
////					display[2] = song[flag + 2];
////					display[3] = song[flag + 3];
////				}
////				else
////				{
////					if (song[flag] == display[3])
////					{
////						++flag;
////						display[3] = song[flag];
////						display[2] = song[flag - 1];
////						display[1] = song[flag - 2];
////						display[0] = song[flag - 3];
////					}
////					else
////					{
////						++flag;
////					}
////				}
////			}
////		}
////		for (int i = 0; i < 4; ++i)
////		{
////			cout << display[i];
////			if (i < 3)
////			{
////				cout << ' ';
////			}
////		}
////		cout << endl;
////		cout << song[flag] << endl;
////	}
////	else
////	{
////		display.resize(n);
////		for (int i = 0; i < n; ++i)
////		{
////			display[i] = i + 1;
////		}
////		int flag = 0;
////		for (int i = 0; i < str.size(); ++i)
////		{
////			if (str[i] == 'U')
////			{
////				if (flag == 0)
////				{
////					flag = n - 1;
////				}
////				else
////				{
////					--flag;
////				}
////			}
////			else if (str[i] == 'D')
////			{
////				if (flag == n - 1)
////				{
////					flag = 0;
////				}
////				else
////				{
////					++flag;
////				}
////			}
////		}
////		for (int i = 0; i < n; ++i)
////		{
////			cout << display[i];
////			if (i < n - 1)
////			{
////				cout << ' ';
////			}
////		}
////		cout << endl;
////		cout << song[flag];
////	}
////	return 0;
////}
//
//
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		vector<int> hash;
//		hash.resize(128);
//		for (int i = 0; i < str.size(); ++i)
//		{
//			++hash[str[i]];
//		}
//		int i = 0;
//		for (i = 0; i < str.size(); ++i)
//		{
//			if (hash[str[i]] == 1)
//			{
//				cout << str[i] << endl;
//				break;
//			}
//		}
//		if (i == str.size())
//		{
//			cout << -1 << endl;
//		}
//	}
//	return 0;
//}