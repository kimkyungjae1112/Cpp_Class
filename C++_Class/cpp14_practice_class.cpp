#include <iostream>

namespace Calculator_with_a_class
{
	template <typename T>
	class My_calc
	{
		T x;
		T y;

	public:
		My_calc(T x, T y) : x(x), y(y) {}

		T add()
		{
			return x + y;
		}

		T sub()
		{
			return x - y;
		}

		T mul()
		{
			return x * y;
		}

		T div()
		{
			if (y != 0) return x / y;
			std::cout << "0으로 못나눔요" << std::endl;
			return 0;
		}
	};

	int main()
	{
		My_calc<int> c(10, 20);
		std::cout << c.add() << std::endl;
		std::cout << c.sub() << std::endl;
		std::cout << c.mul() << std::endl;
		std::cout << c.div() << std::endl;
		My_calc<int> c1(10, 0);
		std::cout << c1.div() << std::endl;
		return 0;
	}
}

namespace Queue
{
	template <typename T>
	class Queue
	{
		struct Node
		{
			T data;
			Node* next;
			Node(T data) : data(data), next(nullptr) {}
		};

		Node* head, * tail;

	public:
		Queue() : head(nullptr), tail(nullptr) {}

		bool is_empty()
		{
			if (tail == nullptr) return true;
			return false;
		}

		void enqueue(T data)
		{
			Node* new_node = new Node(data);
			if (is_empty())
			{
				head = tail = new_node;
				return;
			}
			tail->next = new_node;
			tail = new_node;
		}

		T dequeue()
		{
			if (!is_empty())
			{
				Node* temp = head;
				head = head->next;
				T data = temp->data;
				delete temp;
				return data;
			}
			else
			{
				std::cout << "Q가 비어있다." << std::endl;
				return NULL;
			}
		}

		T peek()
		{
			return head->data;
		}
	};

	int main()
	{
		Queue<int> Q;
		Q.enqueue(10);
		Q.enqueue(20);
		Q.enqueue(30);

		std::cout << Q.peek() << std::endl;
		std::cout << Q.dequeue() << std::endl;
		std::cout << Q.dequeue() << std::endl;
		std::cout << Q.dequeue() << std::endl;
		std::cout << Q.dequeue() << std::endl;
		return 0;
	}
}
