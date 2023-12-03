#include <iostream> 
using namespace std;

namespace Before_AdaptorPattern
{
	template<typename T, typename U>
	T xfind(T first, T end, U c)
	{
		while (first != end && *first != c)
		{
			first++;
		}
		return first;
	}

	template<typename T>
	struct Node
	{
		T data;
		Node* next;
		Node(T data, Node* n) : data(data), next(n) {}
	};

	template<typename T>
	class slist
	{
		Node<T>* head;

		Node<T>* current;
	public:
		slist() : head(nullptr), current(nullptr) {}

		void push_front(T data)
		{
			head = new Node<T>(data, head);
		}

		slist<T>& next()
		{
			current = current->next;
			return *this;
		}

		slist<T>& begin()
		{
			current = head;
			return *this;
		}

		bool end()
		{
			return current == 0;
		}

		T operator*()
		{
			return current->data;
		}

		void print()
		{
			Node<T>* current = head;
			while (current)
			{
				cout << current->data << " ";
				current = current->next;
			}
		}
	};

	int main()
	{
		slist<int> s;
		s.push_front(10);
		s.push_front(20);
		s.push_front(30);
		s.print();
		cout << endl;
		for (s.begin(); !s.end(); s.next()) //for문으로 순회할 수 있다.
		{
			cout << *s << " ";              //근데 xfind알고리즘은 형식이 맞지 않아 사용 불가능
		}                                   //그래서 도입된 개념이 어뎁터 디자인 패턴
		return 0;                           //많은 컨테이너들이 있는데 접근, 순회 방법이 제각각
		                                    //이를 통일시켜보자!
	}
}
namespace After_AdaptorPatern
{
	template<typename T>
	struct Node
	{
		T data;
		Node* next;
		Node(T data, Node* n) : data(data), next(n) {}
	};


	template<typename T, typename U>
	T xfind(T first, T end, U c)
	{
		while (first != end && *first != c)
		{
			first++;
		}
		return first;
	}

	template<typename T>
	class slist_proxy
	{
		Node<T>* current;
	public:
		slist_proxy(Node<T>* p = 0) : current(p) {}

		bool operator!=(const slist_proxy<T> p)
		{
			return current != p.current;
		}

		template<typename U>
		bool operator!=(const U& p)
		{
			return current->data != p;
		}

		T& operator*()
		{
			return current->data;
		}

		slist_proxy<T>& operator++(int)
		{
			current = current->next;
			return *this;
		}
		
	};

	template<typename T>
	class slist
	{
		Node<T>* head;
	public:
		slist() : head(nullptr) {}

		void push_front(const T& data)
		{
			head = new Node<T>(data, head);
		}
		
		typedef slist_proxy<T> iterator;
		iterator begin() { return iterator(head); }
		iterator end() { return iterator(0); }
	};

	int main()
	{
		slist<int> s;
		s.push_front(10);
		s.push_front(20);
		s.push_front(30);
		slist<int>::iterator iter = xfind(s.begin(), s.end(), 40);
		
		return 0;
	}
}
namespace Function_Object
{
	struct plus
	{
		int operator()(int a, int b)
		{
			return a + b;
		}
	};

	class PiggyBox
	{
		int total;

	public:
		PiggyBox(int init = 0) : total(init) {}
		int operator()(int money)
		{
			total += money;
			return total;
		}
	};

	int main()
	{
		plus p;
		PiggyBox pig;

		cout << "money(100) : " << pig(100) << endl;
		cout << "money(500) : " << pig(500) << endl;
		cout << "money(2000) : " <<pig(2000) << endl;

		int n = p(1, 2);
		cout << n << endl;
		return 0;
	}
}
