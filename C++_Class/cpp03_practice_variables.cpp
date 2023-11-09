#include <iostream>

namespace Box
{
	using namespace std;

	int main()
	{
		int a, b, c;
		cout << "input length: ";
		cin >> a;

		cout << "input width: ";
		cin >> b;

		cout << "input height: ";
		cin >> c;

		cout << "Box volume: " << a * b * c;
		return 0;
	}
}

namespace Timer
{
	using namespace std;

	int main()
	{
		int seconds;
		cin >> seconds;
		int days = seconds / 86400;
		int hours = (seconds % 86400) / 3600;
		int minutes = ((seconds % 86400) % 3600) / 60;
		int second = ((seconds % 86400) % 3600) % 60;

		cout << seconds << "seconds = " << days << " days, "
			<< hours << " hours, " << minutes << " minutes, " << second << " seconds";

		return 0;
	}
}

namespace Digits
{
	using namespace std;

	int main()
	{
		int number;
		cin >> number;

		int thousands, hundreds, tens, ones;
		thousands = number / 1000;
		hundreds = (number % 1000) / 100;
		tens = ((number % 1000) % 100) / 10;
		ones = number % 10;

		cout << "thousands: " << thousands << '\n'
			<< "hundreds: " << hundreds << '\n'
			<< "tens: " << tens << '\n'
			<< "ones: " << ones;
		return 0;
	}
}
