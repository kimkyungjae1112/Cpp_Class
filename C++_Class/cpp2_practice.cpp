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

		/*0�� ��µȴ�.

		cin ��ü�� ��ü�̰� true(����)�� false(������) ���� �����µ� ��ҿ��� true �̴�.

		�Ѹ���� cin�� ���� true�̰� >> �����ڸ� ���� ���� �������ٶ� �߸��� ���� ���޵Ǹ�

		false ���� ���޵ȴ�. false�� 0�̱� ������ 0�� ��µȴ�.*/



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