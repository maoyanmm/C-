//成绩分批处理
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
#include<string>

//int main()
//{
//	int x;
//	while (cin >> x)
//	{
//		if (x >= 90 && x <= 100)
//		{
//			cout << 'A' << endl;
//		}
//		else if (x >= 80 && x <= 89)
//		{
//			cout << 'B' << endl;
//		}
//		else if (x >= 70 && x <= 79)
//		{
//			cout << 'C' << endl;
//		}
//		else if (x >= 60 && x <= 69)
//		{
//			cout << 'D' << endl;
//		}
//		else
//		{
//			cout << 'E' << endl;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int arr[3][3];
//	for (int j = 0; j < 3; ++j)
//	{
//		for (int i = 0; i < 3; ++i)
//		{
//			cin >> arr[i][j];
//		}
//	}
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j < 3; ++j)
//		{
//			cout << arr[i][j];
//			if (j != 3)
//			{
//				cout << " ";
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}

//int main()
//{
//	string str;
//	getline(cin, str);
//	int countx = 0;
//	string strtmp;
//	for (int i = 0; i < str.size(); ++i)
//	{
//		if (str[i] == '*')
//		{
//			countx++;
//		}
//	}
//	strtmp.reserve(str.size());
//	for (int i = 0; i < countx; ++i)
//	{
//		strtmp += '*';
//	}
//	for (int i = 0; i < str.size(); ++i)
//	{
//		if (str[i] != '*' && str[i] != ' ')
//		{
//			strtmp += str[i];
//		}
//	}
//	cout << strtmp << endl;
//	cout << countx << endl;
//	return 0;
//}

//int main()
//{
//	int n;
//	while (cin >> n )
//	{
//		int i = -1;
//		int* arr = new int[n];
//		int nums = n;
//		while (1)
//		{
//			int count = 3;
//			while (count)
//			{
//				i++;
//				if (i == n)
//				{
//					i = 0;
//					if (arr[i] != 1)
//					{
//						count--;
//					}
//				}
//				else
//				{
//					if (arr[i] != 1)
//					{
//						count--;
//					}
//				}
//			}
//			arr[i] = 1;
//			nums--;
//			if (nums == 1)
//			{
//				break;
//			}
//		}
//		for (int j = 0; j < n; j++)
//		{
//			if (arr[j] != 1)
//			{
//				cout << j + 1 << endl;
//			}
//		}
//	}
//	return 0;
//}//

//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	int* arr1 = new int[k];
//	int* arr2 = new int[k];
//	for (int i = 0; i < k; ++i)
//	{
//		cin >> arr1[i] >> arr2[i];
//	}
//	int sum = 0;
//	while (k)
//	{
//		--k;
//		sum += pow(2, k);
//	}
//	cout << sum + 1 << endl;
//
//	system("pause");
//	return 0;
//}

int main()
{
	string password;
	cin >> password;
	int score = 0;
	int alphabeta = 0;
	int alphabetA = 0;
	int alphabet = 0;
	int num = 0;
	int symbol = 0;
	for (int i = 0; i < password.size(); ++i)
	{
		/*if (password[i] >= 'a' && password[i] <= 'z')
		{
			alphabeta = 1;
			alphabet = 1;
		}
		if (password[i] >= 'A' && password[i] <= 'Z')
		{
			alphabetA = 1;
			alphabet = 1;
		}
		if (password[i] >= '0' && password[i] <= '9')
		{
			++num;
		}
		if ((password[i] >= 0x21 && password[i] <= 0x2F) || (password[i] >= 0x3A && password[i] <= 0x40)
			|| (password[i] >= 0x5B && password[i] <= 0x60) || (password[i] >= 0x7B && password[i] <= 0x7E))
		{
			++symbol;
		}*/
		if (password[i] >= 'a' && password[i] <= 'z')
		{
			alphabeta = 1;
			alphabet = 1;
		}
		else if (password[i] >= 'A' && password[i] <= 'Z')
		{
			alphabetA = 1;
			alphabet = 1;
		}
		else if (password[i] >= '0' && password[i] <= '9')
		{
			++num;
		}
		else
		{
			symbol++;
		}
	}
	if (password.size() >= 8)
	{
		score += 25;
	}
	else if (password.size() >= 5)
	{
		score += 10;
	}
	else
	{
		score += 5;
	}
	if (alphabeta == 1 && alphabetA == 1)
	{
		score += 20;
	}
	else if (alphabeta == 1 || alphabeta == 1)
	{
		score += 10;
	}
	if (num > 1)
	{
		score += 20;
	}
	else if (num == 1)
	{
		score += 10;
	}
	if (symbol > 1)
	{
		score += 25;
	}
	else if (symbol == 1)
	{
		score += 10;
	}
	if (alphabeta == 1 && alphabetA == 1 && num >0 && symbol>0)
	{
		score += 5;
	}
	else if (alphabet == 1 && num>0 && symbol>0)
	{
		score += 3;
	}
	else if (alphabet == 1 && num>0)
	{
		score += 2;
	}
	if (score >= 90)
	{
		cout << "VERY_SECURE" << endl;
	}
	else if (score >= 80)
	{
		cout << "SECURE" << endl;
	}
	else if (score >= 70)
	{
		cout << "VERY_STRONG" << endl;
	}
	else if (score >= 60)
	{
		cout << "STRONG" << endl;
	}
	else if (score >= 50)
	{
		cout << "AVERAGE" << endl;
	}
	else if (score >= 25)
	{
		cout << "WEAK" << endl;
	}
	else
	{
		cout << "VERY_WEAK" << endl;
	}
	system("pause");
	return 0;
}