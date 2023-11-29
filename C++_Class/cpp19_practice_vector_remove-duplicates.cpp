#include <iostream>
#include <cmath>
//����
template<typename T, typename U> void Sort(T first, T last, U compare)
{
	for (auto i = first; i != last; ++i)
	{
		for (auto j = i; j != last; ++j)
		{
			if (compare(*i, *j))
			{
				auto temp = *i;
				*i = *j;
				*j = temp;
			}
		}
	}
}

//����ũ
template <typename T>
T unique(T first, T last)
{
	if (first == last) // �� ������ ���
		return last;

	T result = first;

	while (first != last)
	{
		if (*first == *result) ++first;
		else
		{
			++result;
			*result = *first;
		}
	}

	return ++result; // ���ο� �� ���� ��ȯ
}

//���ͷ�����
template <typename T> class VECTOR_Iterator //adaptor ���� ����� �����, �ڷᱸ���� �� ��ü�� �ְ� �ڷᱸ�� �ۿ��� �ȿ� �ִ� ��ҵ��� ����Ŵ
{
	T* cursor; //����ؼ� �������� ������

public:
	VECTOR_Iterator(T* p = 0) : cursor(p) {}

	bool operator!=(const VECTOR_Iterator& p)
	{
		return cursor != p.cursor;
	}

	bool operator==(const VECTOR_Iterator& p)
	{
		return cursor == p.cursor;
	}

	VECTOR_Iterator& operator++()
	{
		++cursor;
		return *this;
	}

	VECTOR_Iterator& operator++(int)
	{
		cursor++;
		return *this;
	}

	VECTOR_Iterator& operator-(int i)
	{
		cursor -= i;
		return *this;
	}
	int operator-(VECTOR_Iterator& p) //�ٽ� ���� �ڿ��� �� ���� ���� �����ϱ�
	{
		return cursor - p.cursor;
	}

	T& operator* ()
	{
		return *cursor;
	}
};

//����
template <typename T> class VECTOR
{
	T* content;
	int mSize;
	int mCapacity;
	int mIndex;

public:
	VECTOR(int s = 0) : mSize(0), mCapacity(s), mIndex(0)
	{
		content = new T[mCapacity];
	}

	VECTOR(const T* temp)
	{
		int count = 1, i = 0;
		while (temp[i] != '\0')
		{
			i++;
			count++;
		}

		mSize = count;
		mCapacity = count * 2;
		mIndex = count;
	}
	~VECTOR()
	{
		delete[] content;
	}

	int size() { return mSize; }
	int capacity() { return mCapacity; }

	void resize(int s)
	{
		mSize = s;
		if (s >= mCapacity)
		{
			mCapacity = s * 2;

			T* temp = new T[mCapacity];
			for (int i = 0; i < mSize; ++i)
			{
				temp[i] = content[i];
			}
			delete[] content;
			content = temp;
		}
	}

	void push_back(const T& data)
	{
		if (mIndex == mSize) resize(mSize + 1);
		content[mIndex++] = data;
	}

	void _sort()
	{
		Sort(begin(), end(), [](T a, T b) { return a > b; });
	}


	T operator[](int i) { return content[i]; }


	typedef VECTOR_Iterator<T> iterator;
	iterator begin() { return iterator(content); }
	iterator end() { return iterator(content + mSize); }

	void erase(iterator first, iterator last)
	{
		int eraseCount = last - first; // ������ ��� �� ���
		if (abs(eraseCount) <= 0)
			return;

		std::cout << "������ ��� �� : " << eraseCount << std::endl;
		mSize -= eraseCount;
	}
};

int main()
{
	VECTOR<char> vec;
	vec.push_back('a');
	vec.push_back('b');
	vec.push_back('b');
	vec.push_back('a');
	vec.push_back('e');
	vec.push_back('d');
	vec.push_back('d');
	vec.push_back('b');

	std::cout << "ó�� ����ִ� ��" << std::endl;
	for (auto& i : vec)
	{
		std::cout << i << " ";
	}
	std::cout << '\n' << '\n';


	std::cout << "���� �� ����ִ� ��" << std::endl;
	vec._sort();
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << '\n' << '\n';

	std::cout << "�ߺ� ���� �� ����ִ� ��" << std::endl;
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	return 0;
}