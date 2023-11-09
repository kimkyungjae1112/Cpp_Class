#include <iostream>
#include <cmath>
#include <string>
#include <stack>

namespace More_advanced_calculator
{
	using namespace std;
	template<typename T1 = double, typename T2 = double>
	struct Number
	{
		T1 a;
		T2 b;
	};

	void add(Number<>& n)
	{
		cout << "Answer: " << n.a + n.b << endl;
	}

	void subtract(Number<>& n)
	{
		cout << "Answer: " << n.a - n.b << endl;
	}

	void multiply(Number<>& n)
	{
		cout << "Answer: " << n.a * n.b << endl;
	}

	void divide(Number<>& n)
	{
		if (n.b != 0)
		{
			cout << "Answer: " << n.a / n.b << endl;
		}
		else
		{
			cout << "Wrong" << endl;
		}
	}

	int main()
	{
		Number<> n;
		cout << "--------------" << endl;
		cout << "+ : add" << endl;
		cout << "- : subtract" << endl;
		cout << "* : multiply" << endl;
		cout << "/ : divide" << endl;
		cout << "Q : quit" << endl;
		cout << "---------------" << endl;

		char c;
		cout << "Select an operator: ";
		cin >> c;

		while (c != 'Q')
		{
			cout << "Input two number: ";
			cin >> n.a >> n.b;
			if (c == '+')
			{
				add(n);
			}
			else if (c == '-')
			{
				subtract(n);
			}
			else if (c == '*')
			{
				multiply(n);
			}
			else if (c == '/')
			{
				divide(n);
			}
			cout << "Select an operator: ";
			cin >> c;
		}
		return 0;
	}
}

namespace Quadrant_two
{
	using namespace std;

	struct Point
	{
		double x;
		double y;
	};

	double dist_2d(Point po, Point pt)
	{
		return sqrt(pow((pt.x - po.x), 2) + pow((pt.y - po.y), 2));
	}

	void set_point(Point& po, Point& pt)
	{
		cout << "input x1, y1: ";
		cin >> po.x >> po.y;
		cout << "input x2, y2: ";
		cin >> pt.x >> pt.y;
	}
	int main()
	{
		Point po, pt;
		set_point(po, pt);
		cout << "Distance: " << dist_2d(po, pt);
		return 0;
	}
}

namespace Digits_three
{
	using namespace std;

	int main()
	{
		stack<char> s;
		stack<char> q;
		string str;
		cout << "input number: ";
		cin >> str;

		int count = 0;
		for (int i = 0; i < str.length(); ++i)
		{
			s.push(str[i]);
		}

		while (!s.empty())
		{
			if (count == 3)
			{
				count = 0;
				q.push(',');
				continue;
			}
			q.push(s.top());
			s.pop();
			count++;
		}

		while (!q.empty())
		{
			cout << q.top();
			q.pop();
		}
		return 0;
	}
}

namespace Tower_of_Hanoi
{
	using namespace std;

	void hanoi(int n, int a, int b, int c)
	{
		if (n == 1)
		{
			cout << a << " " << c << endl;
			return;
		}
		hanoi(n - 1, a, c, b);
		cout << a << " " << c << endl;
		hanoi(n - 1, b, a, c);
	}

	int main()
	{
		int n;
		cin >> n;
		hanoi(n, 1, 2, 3);
		return 0;
	}
}
