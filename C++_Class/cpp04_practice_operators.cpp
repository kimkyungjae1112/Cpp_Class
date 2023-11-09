#include <iostream>
#include <cmath>

namespace Caesar_cipher
{
	using namespace std;

	int main()
	{
		string str;
		cout << "Input string: ";
		cin >> str;

		int key;
		cout << "Input key: ";
		cin >> key;

		str[0] = (char)(str[0] + key);
		str[1] = (char)(str[1] + key);
		str[2] = (char)(str[2] + key);
		str[3] = (char)(str[3] + key);
		str[4] = (char)(str[4] + key);
		str[5] = (char)(str[5] + key);
		str[6] = (char)(str[6] + key);
		str[7] = (char)(str[7] + key);
		cout << "Cipher string: " << str;
		return 0;
	}
}

namespace Decryption
{
	using namespace std;

	int main()
	{
		string str;
		cout << "Input string: ";
		cin >> str;

		int key;
		cout << "Input key: ";
		cin >> key;

		str[0] = (char)(str[0] - key);
		str[1] = (char)(str[1] - key);
		str[2] = (char)(str[2] - key);
		str[3] = (char)(str[3] - key);
		str[4] = (char)(str[4] - key);
		str[5] = (char)(str[5] - key);
		str[6] = (char)(str[6] - key);
		str[7] = (char)(str[7] - key);
		cout << "Decrypted string: " << str;
		return 0;
	}
}

namespace Quadrant
{
	using namespace std;

	int main()
	{
		int x, y;
		cout << "Input x: ";
		cin >> x;
		cout << "Input y: ";
		cin >> y;
		int answer(0);

		(x > 0 && y > 0) ? answer = 1 :
			(x > 0) ? answer = 4 :
			(y > 0) ? answer = 2 : answer = 3;

		cout << "It is located in the " << answer
			<< "st quadrant";
		return 0;
	}
}

namespace Population
{
	using namespace std;

	int main()
	{
		long long population;
		cout << "Enter the world's population: ";
		cin >> population;

		int kor;
		cout << "Enter the population of KOR: ";
		cin >> kor;

		float answer = (float)kor / population;
		cout << "The population of KOR is "
			<< answer << "% of the world population";
		return 0;
	}
}

namespace Your_height
{
	using namespace std;

	int main()
	{
		float height;
		cout << "Input your height: ";
		cin >> height;

		float inch = height / 2.54;
		cout << height << "cm is " << (int)inch / 12 << " feet " << fmodf(inch, 12) << " inch";
		return 0;
	}
}