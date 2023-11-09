#include <iostream>
namespace Simple_calculator
{
	using namespace std;

	int main()

	{
		int a, b;
		cout << "input1 : ";
		cin >> a;
		cout << "input2: ";
		cin >> b;

		cout << "Add : " << a + b << endl;
		cout << "Sub : " << a - b << endl;
		cout << "Mul : " << a * b << endl;
		cout << "Div : " << a / b << endl;

		return 0;

	}
}

namespace ID_card
{
	using namespace std;

	int main()

	{

		int number;

		string name;



		cout << "Your student number: ";

		cin >> number;

		cout << "Your name: ";

		cin >> name;



		cout << "My name is " << name << endl;

		cout << "My student ID is " << number << endl;

		cout << "My name and ID is " << name << " and " << number << endl;

		return 0;

	}

}

namespace Wrong number
{
	using namespace std;



	int main()

	{

		while (cin)

		{

			int x;

			cin >> x;

			cout << x << endl;

		}

		/*0이 출력된다.

		cin 자체가 객체이고 true(정상)와 false(비정상) 값을 가지는데 평소에는 true 이다.

		한마디로 cin의 값은 true이고 >> 연산자를 통해 값을 전달해줄때 잘못된 값이 전달되면

		false 값이 전달된다. false는 0이기 때문에 0이 출력된다.*/



		return 0;

	}
}

namespace How_old_are_you
{

	using namespace std;

	int main()

	{
		int year, month;
		cout << "Enter your age: ";
		cin >> year;
		month = 12 * year;
		cout << "Your age in months is: " << month;

		return 0;

	}
}

namespace Celsius_and_Fahrenheit
{

	using namespace std;

	int main()

	{

		float c;

		cout << "Please enter a Celsius value: ";

		cin >> c;



		cout << c << " degrees Celsius is " << 1.8 * c + 32.0

			<< " degrees Fahrenheit.";

		return 0;

	}

}

int main()
{
	ID_card::main();
}