#include <iostream>
#include <list>
using namespace std;

namespace cpp_class
{
	class PPP
	{
		//void* vptr -> virtual�� ���̸� �����Ϸ����� �ָ� �߰�����  / ������ ���ǿ� �߰� / PPP �� ���� vtable ��Ͽ� virtual �Լ� �ִ´�.

		int a;
	public:
		virtual void func(int b = 10) //virtual �� ���̸� foo���� PPP::func�� ����
		{
			cout << "PPP: " << b << endl;
		}
	};

	class CCC : public PPP
	{
		//void* vptr -> virtual�� ���̸� �����Ϸ����� �ָ� �߰����� / ��� �����ϱ� �翬�� ����
		int x;
	public:
		virtual void func(int b = 20) //�ѹ� �����Լ��� ���̻� �Ⱥٿ��� �����Լ��̴�. / ������� �κ� ���� ���ε����� ���� ���ε����� �ٲ��ش�. / virtual -> �� �Լ��� �ڽ� Ŭ�������� �������̵� �� ���̴�.
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

	void foo(PPP* p) //�ڽ��� ��� ������ ���� �ϰ������� �Լ� ���� ����
	{                //���� ������ ���� PPP�� ������ ���ð��̴�.
		p->func();
	}

	int main()
	{
		list<PPP*> li; //�������� ��ü���� �ϰ������� ���� ���� ��ĳ����!
		PPP p;
		CCC c;
		li.push_back(&p);
		li.push_back(&c);

		foo(&p);
		foo(&c);

		PPP* a = new CCC; //�����Լ��� �����ϴ� ���� : CCC vptr�� ���� CCC�� �����Լ� ���̺��� �����Ѵ�.
		a->func();
		return 0;
	}
}