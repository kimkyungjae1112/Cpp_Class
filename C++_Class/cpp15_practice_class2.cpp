//과제에서 추가 구현해야할 사항
//1. next가 있다면 prev도 있어야할 것
//2. 리스트가 비어있는지 검사할 것
//3. 리스트 전체를 출력할 함수 구현

#include <iostream>

template <typename T> //템플릿으로 여러 자료형 받기
class My_List
{
private:
	struct Node //노드 생성, 싱글 링크드 리스트
	{
		T data;
		Node* next;

		Node(T data) : data(data), next(nullptr){}
	};

	int length, index; //리스트의 길이와 mark 포인터가 어딜 가리키고 있는지 표현
	Node* head, *mark; //리스트의 첫 노드를 가리키는 head, next() 실행시 움직이는 mark 포인터


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
		std::cout << "length: " << length << ", " << "current: " << index << std::endl;
	}

};

int main()
{
	My_List<int> l;
	l.append(10).append(20).append(30).append(40).append(50).append(100);
	l.next().next().next();
	std::cout << l.get() << std::endl;
	l.info();
	l.rewind();
	std::cout << l.get() << std::endl;
}