//�������� �߰� �����ؾ��� ����
//1. next�� �ִٸ� prev�� �־���� ��
//2. ����Ʈ�� ����ִ��� �˻��� ��
//3. ����Ʈ ��ü�� ����� �Լ� ����

#include <iostream>

template <typename T> //���ø����� ���� �ڷ��� �ޱ�
class My_List
{
private:
	struct Node //��� ����, �̱� ��ũ�� ����Ʈ
	{
		T data;
		Node* next;

		Node(T data) : data(data), next(nullptr){}
	};

	int length, index; //����Ʈ�� ���̿� mark �����Ͱ� ��� ����Ű�� �ִ��� ǥ��
	Node* head, *mark; //����Ʈ�� ù ��带 ����Ű�� head, next() ����� �����̴� mark ������


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