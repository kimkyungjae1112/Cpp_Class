

#include <iostream>
#include <string>
namespace Caesar_cipher_two
{
	using namespace std;

	int main()
	{
		string str;
		int n;
		cout << "Input string: ";
		getline(cin, str);
		cout << "Input key: ";
		cin >> n;

		for (int i = 0; i < str.length(); ++i)
		{
			if (n > 0)
			{
				if (str[i] + n > 90)
				{
					str[i] = (str[i] + n) - 91 + 65;
				}
				else
				{
					str[i] += n;
				}
			}
			else
			{
				if (str[i] + n < 65)
				{
					str[i] = (str[i] + n) + 26;
				}
				else
				{
					str[i] += n;
				}
			}
		}
		cout << "Cipher string: " << str;
		return 0;
	}
}

namespace Quite_advanced_calculator
{
	using namespace std;

	void matrix_input(int** arr, int n)
	{
		cout << "input matrix" << n << ": ";
		for (int i = 0; i < 3; ++i)
		{
			arr[i] = new int[3];
			for (int j = 0; j < 3; ++j)
			{
				cin >> arr[i][j];
			}
		}
	}

	int main()
	{
		cout << "--------------" << endl;
		cout << "+ : addition" << endl;
		cout << "* : multiplication" << endl;
		cout << "--------------" << endl;

		char a;
		int sum = 0;
		int** matrix1 = new int* [3];
		int** matrix2 = new int* [3];
		int answer[3][3] = { 0, };
		cout << "Select an operator: ";
		cin >> a;


		matrix_input(matrix1, 1);
		matrix_input(matrix2, 2);

		if (a == '+')
		{
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					answer[i][j] = matrix1[i][j] + matrix2[i][j];
				}
			}
		}
		else if (a == '*')
		{
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					for (int k = 0, l = 0; k < 3; ++k, ++l)
					{
						answer[j][i] += (matrix1[j][k] * matrix2[l][j]);
					}
				}
			}
		}

		cout << "answer:" << endl;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cout << answer[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}
}

namespace Find_a_string
{
	using namespace std;

	int main()
	{
		string str1;
		string str2;

		cout << "string1: ";
		getline(cin, str1);
		cout << "string2: ";
		cin >> str2;

		int k = 0;
		int answer = 0;
		bool c = false;

		for (int i = 0; i < str1.length(); ++i)
		{
			if (str1[i] == str2[0])
			{
				k = i + 1;
				answer = i;
				for (int j = 1; j < str2.length(); ++j, ++k)
				{
					if (str1[k] == str2[j])
					{
						c = true;
					}
					else
					{
						c = false;
						break;
					}
				}
				if (c) break;
			}
		}

		if (c)
		{
			cout << answer;
		}
		else
		{
			cout << "Not found";
		}
		return 0;
	}
}

