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
		AAA* ptr1 = new AAA; // 소멸자가 호출 안됨
		AAA* ptr2 = new AAA('c');
		AAA* ptr = (AAA*)malloc(sizeof(AAA)); // malloc 은 함수고 동적메모리 할당만 / 생성자 호출 안됨
		delete ptr1; // 소멸자 호출
		delete ptr2;
		return 0;
	}
}

//첫번째 인자는 'size_t'로 약속
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
//오퍼레이터는 네임스페이스에 넣을 수 없엉 전역적이어야 해

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

		new (&k) klass(20); //기존 객체 k의 메모리 위치에 새로운 객체를 덮어씌운다. (placement new)
		new (&k) klass;
		new klass;  //그냥 새로운 메모리 위치에 객체 생성
		new klass;
		return 0;
	}
}

namespace smart_ptr //현재 상태로는 역참조해서 값을 가져오는 것이 불가능하다.
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

	class test //smartptr ptr에 왜 *을 안 붙이는지 궁금해서 만들어보는 클래스
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
			cout << "test 소멸" << endl;
		}

	};

	int main()
	{
		test a = test(10); //생성자를 부르는 방법 
		test b = 20;       //결과는 모두 같다.
		test c(30);
		test d = c; //복사 생성자 

		smartptr ptr = new int; //생성자의 매개 변수 타입이 포인터니까 new로 주소 준것, 위랑 똑같에 인마
		return 0;
	}
}

namespace smart_ptr_v1 //클래스 멤버 변수의 값 역참조 가능
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

namespace smart_ptr_v2 //외부 클래스, 구조체의 포인터로써 작동 가능
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
			cout << "삭제요 ^^" << endl;
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
