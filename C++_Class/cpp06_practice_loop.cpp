#include<iostream>

namespace Order_list
{
	using namespace std;

	int main()
	{
		int bugger = 0, fries = 0, coke = 0;
		int menu;
		cout << "Select a menue (1-4)" << endl;
		do
		{
			cout << "1) Bugger, 2) Fries, 3) Coke, 4) Finish" << endl;
			cin >> menu;

			if (menu == 1)
			{
				cout << "You've ordered a Bugger" << endl;
				bugger++;
			}
			else if (menu == 2)
			{
				cout << "You've ordered a Fries" << endl;
				fries++;
			}
			else if (menu == 3)
			{
				cout << "You've ordered a Coke" << endl;
				coke++;
			}
			else
			{
				if (menu == 4) break;
				cout << "Wrong select try again!!" << endl;
			}
		} while (true);

		cout << "Your orders" << endl;
		if (bugger > 0)
		{
			cout << "1) Bugger * " << bugger << endl;
		}
		if (fries > 0)
		{
			cout << "2) fries * " << fries << endl;
		}
		if (coke > 0)
		{
			cout << "3) Coke * " << coke << endl;
		}
		return 0;
	}
}

namespace Times_Table
{
	using namespace std;

	int main()
	{
		for (int i = 1; i < 10; ++i)
		{
			for (int j = 2; j < 10; ++j)
			{
				cout << j << "*" << i << "=" << j * i << " ";
			}
			cout << endl;
		}
		return 0;
	}
}

namespace Lotto
{
	using namespace std;

	void lotto()
	{
		int a, b, c, d, e, f;

		a = rand() % 45 + 1;
		b = rand() % 45 + 1;
		c = rand() % 45 + 1;
		d = rand() % 45 + 1;
		e = rand() % 45 + 1;
		f = rand() % 45 + 1;

		while (true)
		{
			if (b == a) b = rand() % 45 + 1;
			else if (c == b || c == a) c = rand() % 45 + 1;
			else if (d == c || d == b || d == a) d = rand() % 45 + 1;
			else if (e == d || e == c || e == b || e == a) e = rand() % 45 + 1;
			else if (f == e || f == d || f == c || f == b || f == a) f = rand() % 45 + 1;
			else break;
		}
		cout << a << '\n' << b << '\n' << c << '\n' << d << '\n' << e << '\n' << f;
	}

	int main()
	{
		srand(time(NULL));
		lotto();
		return 0;
	}
}

namespace Diamond
{
	using namespace std;

	int main()
	{
		int height;
		cout << "input height: ";
		cin >> height;

		for (int i = 1; i <= height / 2; i++)
		{
			for (int k = (height / 2) - i + 1; k > 0; --k)
			{
				cout << " ";
			}

			for (int j = 1; j <= 2 * i - 1; j++)
			{
				cout << "*";
			}
			cout << endl;
		}

		if (height % 2 != 0)
		{
			for (int i = 1; i <= 2 * (height / 2 + 1) - 1; i++)
			{
				cout << "*";
			}
			cout << endl;
		}


		for (int i = height / 2; i >= 1; i--)
		{
			for (int k = i; k <= height / 2; ++k)
			{
				cout << " ";
			}

			for (int j = 2 * i - 1; j >= 1; j--)
			{
				cout << "*";
			}
			cout << endl;
		}
		return 0;
	}
}


namespace ÆÄ½ºÄ®ÀÇ_»ï°¢Çü
{
	using namespace std;

	int main()
	{
		int row;
		cout << "input height: ";
		cin >> row;
		cout << endl;

		for (int i = 0; i < row; ++i)
		{
			int val = 1;
			for (int j = 1; j < (row - i); ++j)
			{
				cout << " ";
			}
			for (int k = 0; k <= i; ++k)
			{
				cout << " " << val;
				val = val * (i - k) / (k + 1);
			}
			cout << endl << endl;
		}
		cout << endl;
		return 0;
	}
}
