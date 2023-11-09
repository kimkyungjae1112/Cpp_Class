#include <iostream>
#include <string>

namespace Advanced_calculator
{
	using namespace std;

	int main()
	{
		cout << "--------------" << endl
			<< "+ : add" << endl
			<< "- : subtract" << endl
			<< "* : multiply" << endl
			<< "/ : divide" << endl
			<< "Q : quit" << endl
			<< "--------------- " << endl;

		char a;
		cout << "Select an operator: ";
		cin >> a;

		int b, c;

		while (a != 'Q')
		{
			cout << "Input two number: ";
			cin >> b >> c;

			if (a == '+') { cout << "Answer: " << b + c << endl; }
			else if (a == '-') { cout << "Answer: " << b - c << endl; }
			else if (a == '*') { cout << "Answer: " << b * c << endl; }
			else if (a == '/')
			{
				if (c != 0)
				{
					cout << "Answer: " << b / c << endl;
				}
				else
				{
					cout << "Answer: Cannot divide by 0." << endl;
				}

			}
			else
			{
				cout << "Wrong Input" << endl;
			}

			cout << "Select an operator: ";
			cin >> a;
		}
		return 0;
	}
}

namespace Discount
{
	using namespace std;

	int main()
	{
		int item;
		cout << "number of items? ";
		cin >> item;

		int krw = item * 1000;

		if (item < 10)
		{
			cout << "price: " << krw << " KRW";
		}
		else
		{

			cout << "original price: " << krw << " KRW" << endl;
			cout << "discounted price: " << krw - (krw * 0.1) << " KRW";
		}
		return 0;
	}
}

namespace Digits_two
{
	using namespace std;

	string str(int a)
	{
		switch (a)
		{
		case 0:
			return "zero";
		case 1:
			return "one";
		case 2:
			return "two";
		case 3:
			return "three";
		case 4:
			return "four";
		case 5:
			return "five";
		case 6:
			return "six";
		case 7:
			return "seven";
		case 8:
			return "eight";
		case 9:
			return "nine";
		}
	}
	int main()
	{
		int number;
		cout << "Input your number: ";
		cin >> number;
		bool a, b, c, d;
		a = b = c = d = false;
		for (int i = 1000; i > 0; i /= 10)
		{
			string temp = str(number / i);
			if (!a)
			{
				cout << "thousands: " << temp << endl;
				a = true;
				b = true;
			}
			else if (b)
			{
				cout << "hundredsd: " << temp << endl;
				b = false;
				c = true;
			}
			else if (c)
			{
				cout << "tens: " << temp << endl;
				c = false;
				d = true;
			}
			else
			{
				cout << "ones: " << temp << endl;
				d = false;
			}
			number %= i;
		}
		return 0;
	}
}

namespace Minimum_values
{
	using namespace std;

	int min(int a, int b)
	{
		if (a > b) return b;
		else return a;
	}

	int main()
	{
		int a, b, c;
		cout << "input numbers: ";
		cin >> a >> b >> c;
		int min_num = min(min(a, b), c);

		cout << "minimum number: " << min_num;
		return 0;
	}
}
