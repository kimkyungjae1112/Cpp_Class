#include <iostream>
#include <vector>

template<typename T> class QUEUE : private std::vector<T>
{
	std::vector<T> vec;
public:
	QUEUE() {}
	void enqueue(T data)
	{
		vec.push_back(data);
	}

	void dequeue()
	{
		vec.erase(vec.begin());
	}

	T peak()
	{
		return vec.front();
	}

	void print()
	{
		for (auto& i : vec)
		{
			std::cout << i << " ";
		}
	}
};

