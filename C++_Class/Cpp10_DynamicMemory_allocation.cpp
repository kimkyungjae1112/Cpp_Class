#include <iostream>
using namespace std;

namespace new_and_delete
{
	int main()
	{
		int* p = new int;
		*p = 1024;
		delete p;

		int a = 1024;
		delete& a;

		int arr_size;
		cin >> arr_size;
		int* arr = new int[arr_size];

		for (int i = 0; i < arr_size; ++i) arr[i] = i;

		delete[] arr;
		return 0;
	}
}

namespace Dynamic_allocation
{
	class AAA
	{
	private:
		char id;

	public:
		AAA() : id('z')
		{
			cout << "I am AAA!" << endl;
		}

		AAA(char c)
		{
			cout << "I am a " << c << "!" << endl;
			this->id = c;
		}

		~AAA()
		{
			cout << id << " will be back!" << endl;
		}

	};

	int main()
	{
		AAA* ptr1 = new AAA; // �Ҹ��ڰ� ȣ�� �ȵ�
		AAA* ptr2 = new AAA('c');
		AAA* ptr = (AAA*)malloc(sizeof(AAA)); // malloc �� �Լ��� �����޸� �Ҵ縸 / ������ ȣ�� �ȵ�
		delete ptr1; // �Ҹ��� ȣ��
		delete ptr2;
		return 0;
	}
}

//ù��° ���ڴ� 'size_t'�� ���
//void* operator new(size_t sz)
//{
//	cout << "operator new" << endl;
//	return malloc(sz);
//}
//
//void* operator new(size_t sz, const char* s, int n)
//{
//	cout << "operator new2: " << s << " " << n << endl;
//	return malloc(sz);
//}
//
//void operator delete(void* p)
//{
//	cout << "operator delete" << endl;
//	free(p);
//}
//
//int main()
//{
//	int* p = new int;
//	int* p2 = new("new new new", 2) int;
//	delete p;
//	return 0;
//}
//���۷����ʹ� ���ӽ����̽��� ���� �� ���� �������̾�� ��

namespace Placement_new
{
	class klass
	{
	private:
		int a = 0x41424344;

	public:
		klass() { cout << "Constructor! " << endl; }
		void foo() { cout << "Foooooooo!" << endl; }
	};

	int main()
	{
		char reserve[1024] = "Hello";
		cout << reserve << endl;

		klass* ptr = new (reserve) klass;

		cout << (void*)reserve << endl;
		cout << ptr << endl;

		cout << reserve << endl;

		return 0;
	}
}

namespace constructor_repeatedly
{
	class klass
	{
	private:
		int a = 0x41424344;
		int test;
	public:
		klass(int b = 0) : test(b) { cout << "Constructor! " << test << endl; }
		void foo() { cout << "Fooooooooooo!" << endl; }
		~klass() { cout << "Destructor!" << endl; }
	};

	int main()
	{
		klass k(10);

		new (&k) klass(20); //���� ��ü k�� �޸� ��ġ�� ���ο� ��ü�� ������. (placement new)
		new (&k) klass;
		new klass;  //�׳� ���ο� �޸� ��ġ�� ��ü ����
		new klass;
		return 0;
	}
}

namespace smart_ptr //���� ���·δ� �������ؼ� ���� �������� ���� �Ұ����ϴ�.
{
	class smartptr
	{
	private:
		int* ptr;

	public:
		smartptr(int* p = 0) : ptr(p) {}

		~smartptr()
		{
			cout << "free the memory! " << endl;
			delete ptr;
		}

	};

	class test //smartptr ptr�� �� *�� �� ���̴��� �ñ��ؼ� ������ Ŭ����
	{
	private:
		int a;
	public:
		test(int a = 0) : a(a)
		{
			cout << a << endl;
		}

		~test()
		{
			cout << "test �Ҹ�" << endl;
		}

	};

	int main()
	{
		test a = test(10); //�����ڸ� �θ��� ��� 
		test b = 20;       //����� ��� ����.
		test c(30);
		test d = c; //���� ������ 

		smartptr ptr = new int; //�������� �Ű� ���� Ÿ���� �����ʹϱ� new�� �ּ� �ذ�, ���� �Ȱ��� �θ�
		return 0;
	}
}

namespace smart_ptr_v1 //Ŭ���� ��� ������ �� ������ ����
{
	class smartptr
	{
	private:
		int* ptr;

	public:
		smartptr(int* p = 0) : ptr(p) {}

		~smartptr()
		{
			cout << "free the memory! " << endl;
			delete ptr;
		}

		int& operator*()
		{
			return *ptr;
		}
	};

	int main()
	{
		smartptr ptr = new int;
		*ptr = 10;
		cout << "ptr is " << *ptr << endl;
		return 0;
	}
}

namespace smart_ptr_v2 //�ܺ� Ŭ����, ����ü�� �����ͷν� �۵� ����
{
	class member
	{
	private:
		int id;

	public:
		member(int _id) : id(_id) {}
		void print()
		{
			cout << id << endl;
		}
	};

	template<typename T>
	class smartptr
	{
	private:
		T* ptr;

	public:
		smartptr(T* p = 0) : ptr(p) {}
		~smartptr()
		{
			cout << "free the memory! " << endl;
			delete ptr;
		}

		T& operator*() { return *ptr; }
		T* operator->() { return ptr; }
	};

	int main()
	{
		smartptr<member> ptr = new member(10);
		ptr->print();
		return 0;
	}
} 

namespace smart_ptr_my
{
	class test
	{
		int a;
	public:
		test() : a(10){}
		void print() { cout << a << endl; }
	};

	template<typename T>
	class smartptr
	{
		T* ptr;

	public:
		smartptr(T* p) : ptr(p) {}
		
		~smartptr()
		{
			cout << "������ ^^" << endl;
			delete ptr;
		}

		T& operator*()
		{
			return *ptr;
		}

		T* operator->()
		{
			return ptr;
		}
	};

	int main()
	{
		smartptr<test> ptr = new test;
		ptr->print();
		return 0;
	}
} 

namespace Deep_copy
{
	template<typename T>
	class smartptr
	{
	private:
		T* ptr;

	public:
		smartptr(T* p = 0) : ptr(p) {}
		smartptr(const smartptr& p)
		{
			ptr = new T;
			memcpy(ptr, p.ptr, sizeof(T));
		}

		T& operator*() { return *ptr; }
		T* operator->() { return ptr; }

		~smartptr() { delete ptr; }
	};


	int main()
	{
		smartptr<int> p1 = new int;
		*p1 = 10;

		smartptr<int> p2 = p1;
		cout << *p2 << endl;
		return 0;
	}
}

namespace reference_counter
{
	template <typename T>
	class smartptr
	{
	private:
		T* ptr;
		int* ref;

	public:
		smartptr(T* p = 0) : ptr(p)
		{
			ref = new int(1);
		}
		smartptr(const smartptr& p) : ptr(p.ptr), ref(p.ref)
		{
			(*ref)++;
		}

		~smartptr()
		{
			if (--(*ref) == 0)
			{
				delete ptr;
				delete ref;
			}
		}

		T& operator*()
		{
			return *ptr;
		}
		T* operator->()
		{
			return ptr;
		}
	};

	int main()
	{
		smartptr<int>  p1 = new int;
		*p1 = 10;

		smartptr<int> p2 = p1;
		return 0;
	}
}
