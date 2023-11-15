#include <iostream>
#include <string>
using namespace std;

namespace Upgrade_the_ll_class
{

	template <typename T> //템플릿으로 여러 자료형 받기
	class My_List
	{
	private:
		struct Node //노드 생성, 싱글 링크드 리스트
		{
			T data;
			Node* next;

			Node(T data) : data(data), next(nullptr) {}
		};

		int length, index; //리스트의 길이와 mark 포인터가 어딜 가리키고 있는지 표현
		Node* head, * mark; //리스트의 첫 노드를 가리키는 head, next() 실행시 움직이는 mark 포인터


	public:
		My_List() : head(nullptr), mark(nullptr), length(0), index(0) {}

		My_List& append(T data) //체이닝을 위해 자료형을 자신의 참조형으로 지정
		{
			Node* new_node = new Node(data);
			if (!head) //헤드가 널이라면 첫 노드를 가리키고, mark 또한 헤드를 가르킨다.
			{
				head = new_node;
				mark = head;
				length++;
				return *this;	  //객체 자기 자신을 반환한다.
			}

			Node* current = head;
			while (current->next) //head를 타고 들어가 마지막 노드까지 이동한다.
			{
				current = current->next;
			}
			current->next = new_node; //마지막 노드의 다음이 새로운 노드를 가리키도록 한다.
			length++;				  //리스트의 길이를 하나씩 늘려가고, 자신을 반환한 후 종료한다.
			return *this;
		}

		My_List& next()
		{
			mark = mark->next;		  //mark를 다음 노드를 가리키도록 옮기고, 현재 위치를 업데이트 한다.
			index++;
			return *this;
		}

		T get()					      //현재 mark가 가리키고 있는 노드의 데이터를 반환한다.
		{
			Node* current = mark;

			return current->data;
		}

		void rewind()				  //mark를 처음 위치로 되돌린다.
		{
			mark = head;
			index = 0;
		}

		void info()					  //현재 list의 길이와 mark의 현재 위치를 출력한다.
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
			/*Node* current = head;  //두가지 방법 모두 되지만 이 방법은 똑같은 리스트를 한번 더 더했을 시 무한루프에 빠진다... 왜?
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
			if (n < 0 || n > length) // 유효하지 않은 위치이거나 마지막 노드를 삭제하려는 경우
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
