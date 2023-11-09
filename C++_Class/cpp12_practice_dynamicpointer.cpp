#include <iostream>
#include <cmath>

namespace mystrcat
{
	char* my_strcat(const char* str1, const char* str2)
	{
		int i = 0, j = 0;
		while (str1[i] != '\0')
		{
			i++;
		}
		while (str2[j] != '\0')
		{
			j++;
		}

		char* str = new char[i + j + 1];
		for (int k = 0; k < i; ++k)
		{
			str[k] = str1[k];
		}
		for (int k = i; k < i + j + 1; ++k)
		{
			str[k] = str2[k - i];
		}
		return str;
	}

	int main()
	{
		char* str = my_strcat("Hello", "World!");
		std::cout << str << std::endl;
		return 0;
	}
}

namespace Reverse_linked_list
{

	template<typename T>
	class Linked_List
	{
		struct Node
		{
			T data;
			Node* next;
			Node(T data) : data(data), next(nullptr) {}
		};

		Node* head;
		Node* tail;
		bool check = false;

	public:
		Linked_List() : head(nullptr), tail(nullptr) {}

		void append(T data)
		{
			Node* new_node = new Node(data);
			if (!head)
			{
				head = new_node;
				return;
			}

			Node* current = head;
			while (current->next)
			{
				current = current->next;
			}
			current->next = new_node;
			tail = current;
		}

		void print()
		{
			if (!check)
			{
				Node* temp = head;
				while (temp)
				{
					std::cout << temp->data << std::endl;
					temp = temp->next;
				}
			}
			else
			{
				Node* temp = head;
				while (tail)
				{
					std::cout << temp->data << std::endl;
					temp = temp->next;
				}
			}
		}

		void reverse()
		{
			Node* prev = nullptr;
			Node* current = head;
			Node* next = nullptr;

			while (current != nullptr)
			{
				next = current->next;
				current->next = prev;
				prev = current;
				current = next;
			}

			tail = head;
			head = prev;

			check = !check;
		}
	};

	int main()
	{
		Linked_List<int> list;
		std::cout << "안뒤집은 LIST" << std::endl;
		list.append(10);
		list.append(20);
		list.append(30);
		list.append(40);
		list.print();

		list.reverse();
		std::cout << "뒤집은 LIST" << std::endl;
		list.print();
		return 0;
	}
}

namespace dynamic_Heap
{

	//사용자가 직접 넣으면서 수정 가능
	using namespace std;

	class Heap_Tree
	{
		int* heap;
		int length;
		int capacity;
		int round_count;
		bool check;

	public:


		Heap_Tree();
		void Add(int data);
		void make_heap_tree();
		void make_heap_tree2();
		void print();
		int get_length();
		int get_capacity();
	};

	Heap_Tree::Heap_Tree() : heap(new int[10]), length(0), capacity(10), check(false), round_count(0) {}

	void Heap_Tree::Add(int data)
	{
		if (length >= capacity)
		{
			int* temp = new int[capacity * 2];

			for (int i = 0; i < length; ++i)
			{
				temp[i] = heap[i];
			}
			delete[] heap;
			heap = temp;
			capacity *= 2;
		}

		check = true;
		heap[length++] = data;
		if (check)
		{
			make_heap_tree2();
		}
	}

	void Heap_Tree::make_heap_tree()
	{
		for (int i = 1; i < length; ++i)
		{
			int c = i;
			do
			{
				int root = (c - 1) / 2;
				if (heap[root] < heap[c])
				{
					int temp = heap[root];
					heap[root] = heap[c];
					heap[c] = temp;
				}
				c = root;
			} while (c != 0);
		}
	}

	void Heap_Tree::make_heap_tree2()
	{
		int c = length - 1;
		do
		{
			int root = (c - 1) / 2;
			if (heap[root] < heap[c])
			{
				if (check)
				{
					print();
					check = !check;
					round_count++;
				}
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
				print();
				round_count++;
			}

			c = root;
		} while (c != 0);


	}
	void Heap_Tree::print()
	{
		int level = 0, a = 0;
		int temp = length;
		while (temp != 0)
		{
			temp /= 2;
			level++;
		}

		int index = 0;
		cout << "Round " << round_count << ": " << endl;;
		for (int i = 0; i < level; ++i)
		{
			for (int k = level * 2 - i * 2; k > 0; --k)
			{
				cout << " ";
			}
			for (int j = 0; j < pow(2, i) && index < length; ++j)
			{
				cout << heap[index++];
				for (int z = level - i; z > 0; --z)
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	int Heap_Tree::get_length()
	{
		return length;
	}

	int Heap_Tree::get_capacity()
	{
		return capacity;
	}
	int main()
	{
		Heap_Tree ht;
		int count;
		cout << "몇 개의 원소를 넣을건지 고르시오: ";
		cin >> count;

		int i;
		while (count--)
		{
			cin >> i;
			ht.Add(i);
		}
		return 0;
	}
}

namespace same_Heap
{

	//이렇게 하면 보너스 과제랑 똑같이 나옵니다!!
	using namespace std;

	class Heap_Tree
	{
		int* heap;
		int length;
		int capacity;
		int round_count;
		bool check;

	public:


		Heap_Tree();
		void Add(int data);
		void make_heap_tree();
		void make_heap_tree2();
		void print();
		int get_length();
		int get_capacity();
	};

	Heap_Tree::Heap_Tree() : heap(new int[10]), length(0), capacity(10), check(false), round_count(0) {}

	void Heap_Tree::Add(int data)
	{
		if (length >= capacity)
		{
			int* temp = new int[capacity * 2];

			for (int i = 0; i < length; ++i)
			{
				temp[i] = heap[i];
			}
			delete[] heap;
			heap = temp;
			capacity *= 2;
			check = true;
		}

		heap[length++] = data;
		if (check)
		{
			make_heap_tree2();
		}
	}

	void Heap_Tree::make_heap_tree()
	{
		for (int i = 1; i < length; ++i)
		{
			int c = i;
			do
			{
				int root = (c - 1) / 2;
				if (heap[root] < heap[c])
				{
					int temp = heap[root];
					heap[root] = heap[c];
					heap[c] = temp;
				}
				c = root;
			} while (c != 0);
		}
	}

	void Heap_Tree::make_heap_tree2()
	{
		int c = length - 1;
		do
		{
			int root = (c - 1) / 2;
			if (heap[root] < heap[c])
			{
				if (check)
				{
					print();
					check = !check;
					round_count++;
				}
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
				print();
				round_count++;
			}

			c = root;
		} while (c != 0);


	}
	void Heap_Tree::print()
	{
		int level = 0, a = 0;
		int temp = length;
		while (temp != 0)
		{
			temp /= 2;
			level++;
		}

		int index = 0;
		cout << "Round " << round_count << ": " << endl;;
		for (int i = 0; i < level; ++i)
		{
			for (int k = level * 2 - i * 2; k > 0; --k)
			{
				cout << " ";
			}
			for (int j = 0; j < pow(2, i) && index < length; ++j)
			{
				cout << heap[index++];
				for (int z = level - i; z > 0; --z)
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	int Heap_Tree::get_length()
	{
		return length;
	}

	int Heap_Tree::get_capacity()
	{
		return capacity;
	}
	int main()
	{
		Heap_Tree ht;
		int count = 10;

		int i;
		while (count--)
		{
			cin >> i;
			ht.Add(i);
		}
		ht.make_heap_tree();
		ht.print();
		ht.Add(15);
		return 0;
	}
}