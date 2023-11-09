#include <iostream>
#include <random>

namespace Lotto_game
{
	using namespace std;

	bool bonus = false;
	int a, b, c, d, e, f, g;

	void random_lotto()
	{
		a = rand() % 45 + 1;
		do
		{
			b = rand() % 45 + 1;
		} while (b == a);
		do
		{
			c = rand() % 45 + 1;
		} while (c == a || c == b);
		do
		{
			d = rand() % 45 + 1;
		} while (d == a || d == b || d == c);
		do
		{
			e = rand() % 45 + 1;
		} while (e == a || e == b || e == c || e == d);
		do
		{
			f = rand() % 45 + 1;
		} while (f == e || f == d || f == c || f == b || f == a);
		do
		{
			g = rand() % 45 + 1;
		} while (g == f || g == e || g == d || g == c || g == b || g == a);
	}

	int match_verification(int user)
	{
		int match = 0;

		if (a == user || b == user || c == user || d == user || e == user || f == user)
		{
			match++;
		}

		if (g == user) bonus = true;

		return match;
	}

	int rank_verification(int match)
	{
		if (match < 3) return 6;
		else if (match == 3) return 5;
		else if (match == 4) return 4;
		else if (match == 5)
		{
			if (bonus) return 2;
			else return 3;
		}
		else return 1;
	}

	int main()
	{
		srand(time(NULL));
		int n, match = 0;
		random_lotto();
		cout << "Guess lottery number: ";
		for (int i = 0; i < 6; ++i)
		{
			cin >> n;
			match += match_verification(n);
		}
		cout << "Number: " << a << " " << b << " " << c << " " << d << " " << e << " " << f << "           보너스 번호: " << g << endl;
		cout << "You match " << match << " number! You are in " << rank_verification(match) << "th place!";
		return 0;
	}
}

namespace Prime_number
{
	using namespace std;

	bool isPrime(int n)
	{
		if (n < 2)
		{
			return false;
		}

		for (int i = 2; i * i <= n; ++i)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
		return true;
	}

	int main()
	{
		int n;

		do
		{
			cout << "input number: ";
			cin >> n;
			if (n == -1)
			{
				cout << "Done.";
				break;
			}
			if (isPrime(n))
			{
				cout << n << " is a prime number." << endl;
			}
			else
			{
				cout << n << " is not a prime number." << endl;
			}
		} while (1);
		return 0;
	}
}

namespace ipower
{
	using namespace std;

	void ipower(int n)
	{
		int i = 0;
		int sum = 0;
		if (i == 0)
		{
			sum += 1;
			cout << n << "^" << i << " = " << sum << endl;
		}
		for (i = 1; i <= 10; ++i)
		{
			sum *= n;
			cout << n << "^" << i << " = " << sum << endl;
		}
	}

	int main()
	{
		int n;
		cout << "input number: ";
		cin >> n;

		ipower(n);
		return 0;
	}
}

namespace Probability
{

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 6);

	void count_dice(int* arrays, int n)
	{
		for (int i = 0; i < n; ++i)
		{
			arrays[dis(gen)]++;
		}
	}

	void graph(int* arrays, int n)
	{
		for (int i = 1; i <= 6; ++i)
		{
			std::cout << i << ":";
			for (int j = 0; j < arrays[i]; ++j)
			{
				std::cout << "@";
			}
			for (int k = arrays[i]; k < n; ++k)
			{
				std::cout << "*";
			}
			std::cout << std::endl;
		}
	}

	int main()
	{
		int n;
		int arrays[7] = { 0 };
		std::cout << "Roll a dice 'n' times: ";
		std::cin >> n;
		count_dice(arrays, n);
		graph(arrays, n);
		return 0;
	}
}