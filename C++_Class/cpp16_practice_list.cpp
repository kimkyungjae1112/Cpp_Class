#include <iostream>
#include <string>
using namespace std;

namespace Upgrade_the_ll_class
{

	template <typename T> //���ø����� ���� �ڷ��� �ޱ�
	class My_List
	{
	private:
		struct Node //��� ����, �̱� ��ũ�� ����Ʈ
		{
			T data;
			Node* next;

			Node(T data) : data(data), next(nullptr) {}
		};

		int length, index; //����Ʈ�� ���̿� mark �����Ͱ� ��� ����Ű�� �ִ��� ǥ��
		Node* head, * mark; //����Ʈ�� ù ��带 ����Ű�� head, next() ����� �����̴� mark ������


	public:
		My_List() : head(nullptr), mark(nullptr), length(0), index(0) {}

		My_List& append(T data) //ü�̴��� ���� �ڷ����� �ڽ��� ���������� ����
		{
			Node* new_node = new Node(data);
			if (!head) //��尡 ���̶�� ù ��带 ����Ű��, mark ���� ��带 ����Ų��.
			{
				head = new_node;
				mark = head;
				length++;
				return *this;	  //��ü �ڱ� �ڽ��� ��ȯ�Ѵ�.
			}

			Node* current = head;
			while (current->next) //head�� Ÿ�� �� ������ ������ �̵��Ѵ�.
			{
				current = current->next;
			}
			current->next = new_node; //������ ����� ������ ���ο� ��带 ����Ű���� �Ѵ�.
			length++;				  //����Ʈ�� ���̸� �ϳ��� �÷�����, �ڽ��� ��ȯ�� �� �����Ѵ�.
			return *this;
		}

		My_List& next()
		{
			mark = mark->next;		  //mark�� ���� ��带 ����Ű���� �ű��, ���� ��ġ�� ������Ʈ �Ѵ�.
			index++;
			return *this;
		}

		T get()					      //���� mark�� ����Ű�� �ִ� ����� �����͸� ��ȯ�Ѵ�.
		{
			Node* current = mark;

			return current->data;
		}

		void rewind()				  //mark�� ó�� ��ġ�� �ǵ�����.
		{
			mark = head;
			index = 0;
		}

		void info()					  //���� list�� ���̿� mark�� ���� ��ġ�� ����Ѵ�.
		{
			cout << "length: " << length << ", " << "current: " << index << endl;
		}

		void print()
		{
			Node* current = head;
			while (current)
			{
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}

		My_List& operator+(T data)
		{
			return append(data);
		}

		My_List& operator+(My_List& ll)
		{
			/*Node* current = head;  //�ΰ��� ��� ��� ������ �� ����� �Ȱ��� ����Ʈ�� �ѹ� �� ������ �� ���ѷ����� ������... ��?
			while (current->next)
			{
				current = current->next;
			}

			current->next = ll.head;*/

			Node* current = ll.head;
			while (current)
			{
				append(current->data);
				current = current->next;
			}
			return *this;
		}

		My_List& operator-(int n)
		{
			if (n < 0 || n > length) // ��ȿ���� ���� ��ġ�̰ų� ������ ��带 �����Ϸ��� ���
			{
				return *this;
			}

			if (n == 0)
			{
				Node* temp = head;
				head = head->next;
				delete temp;
				length--;
				rewind();
				return *this;
			}


			while (n - 1 > index)
			{
				next();
			}

			Node* temp = mark->next;
			mark->next = mark->next->next;
			delete temp;
			length--;
			rewind();
			return *this;
		}

		My_List& operator=(My_List& ll)
		{
			return *this;
		}
	};

	int main()
	{
		My_List<int> l;
		l + 10 + 20 + 30 + 40;
		l.print();

		My_List<int> ll;
		ll = ll + 50;
		l - 0 - 0;
		l.print();
		l = l + ll;
		l.print();
		return 0;
	}

}

namespace New_linked_list
{
	template<typename T>
	class Linked_List
	{
		struct Node
		{
			T data;
			Node* next;

			Node(T data, Node* n) : data(data), next(n) {}
		};

		Node* head;
		Node* tail;

	public:
		Linked_List() : head(nullptr), tail(nullptr) {}

		void push_front(T data)
		{

			head = new Node(data, head);
		}

		void push_back(T data)
		{
			Node* new_node = new Node(data, nullptr);
			if (!head)
			{
				head = tail = new_node;
				return;
			}
			tail->next = new_node;
			tail = new_node;
		}

		void print()
		{
			Node* current = head;

			while (current)
			{
				cout << current->data << " ";
				current = current->next;
			}
		}
	};

	int main()
	{
		Linked_List<int> ll;

		ll.push_back(10);
		ll.push_back(20);
		ll.push_back(30);
		ll.push_front(30);
		ll.print();
		return 0;
	}
}
