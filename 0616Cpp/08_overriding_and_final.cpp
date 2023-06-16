#include <iostream>

using namespace std;

// �ڽ�Ŭ������ �θ�Ŭ������ �Լ��� ������ --> �̸�, �Ű������� ���ƾ��� 

class A /* final --> ���̰� �Ǹ� ��� �Ұ� */
{
public:
	virtual void Print(int x) { cout << "A" << endl; }
	// virtual ���̸� �����ǵȴٴ°� �˷��ְԵ�
};

class B : public A
{
public:
	void Print(int x) override /*final*/ { cout << "B" << endl; } // overriding!
	// void Print(short x) �� �Ǹ� overloading���� �ν���
	// override �� �����ָ� ���򰥸�
	// final �� ������ ������� ��ӽ�Ű�ڴٴ°� �ǹ��� (�� Ŭ������ �θ�� ��� �Ұ���)
};

class C : public B
{
public:
	void Print(int x) override { cout << "C" << endl; }
};

int main()
{
	A a;
	B b;
	C c;

	a.Print(0); // A
	b.Print(0); // B
	c.Print(0); // C

	A& a1 = b;
	A& a2 = c;

	a1.Print(0); // A ����
	a2.Print(0); // A ���� --> Up casting �̳� �����Ͱ� ���������� ����Ű�� Ŭ������ ���ǵ�
	// --> virtual ����ϸ� �ذ�(B, C ����)

	return 0;
}