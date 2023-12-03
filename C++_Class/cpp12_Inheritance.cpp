#include <iostream>
#include <list>
using namespace std;

namespace cpp_class
{
	class PPP
	{
		//void* vptr -> virtual을 붙이면 컴파일러에서 애를 추가해줌  / 데이터 섹션에 추가 / PPP 에 대한 vtable 목록에 virtual 함수 넣는다.

		int a;
	public:
		virtual void func(int b = 10) //virtual 안 붙이면 foo에서 PPP::func만 실행
		{
			cout << "PPP: " << b << endl;
		}
	};

	class CCC : public PPP
	{
		//void* vptr -> virtual을 붙이면 컴파일러에서 애를 추가해줌 / 상속 받으니까 당연히 있음
		int x;
	public:
		virtual void func(int b = 20) //한번 가상함수는 더이상 안붙여도 가상함수이다. / 기술적인 부분 정적 바인딩에서 동적 바인딩으로 바꿔준다. / virtual -> 이 함수는 자식 클래스에서 오버라이딩 될 것이다.
		{
			cout << "CCC: " << b << endl;
		}
	};

	class DDD : public PPP
	{
		int x;
	public:
		void func()
		{
			cout << "DDD" << endl;
		}
	};

	class EEE : public PPP
	{
		int x;
	public:
		void func()
		{
			cout << "EEE" << endl;
		}
	};

	void foo(PPP* p) //자식이 어떻게 생긴지 몰라도 일괄적으로 함수 실행 가능
	{                //누가 들어올진 몰라도 PPP의 가문이 들어올것이다.
		p->func();
	}

	int main()
	{
		list<PPP*> li; //여러가지 객체들을 일괄적으로 관리 가능 업캐스팅!
		PPP p;
		CCC c;
		li.push_back(&p);
		li.push_back(&c);

		foo(&p);
		foo(&c);

		PPP* a = new CCC; //가상함수가 동작하는 원리 : CCC vptr을 통해 CCC의 가상함수 테이블을 참조한다.
		a->func();
		return 0;
	}
}