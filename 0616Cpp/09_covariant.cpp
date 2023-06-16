#include <iostream>

using namespace std;

// ������ȯ�� --> ��ȯ�Ǵ� Ÿ���� �޶� overriding�� ���� --> this�� �����ϴ� �Լ��� ���

class A
{
public:
	virtual A* GetThisPointer() { cout << "A::GetThis" << endl; return this; }

	void print()
	{
		cout << "A" << endl;
	}
};

class B : public A
{
public:
	B* GetThisPointer() { cout << "B::GetThis" << endl; return this; }

	void print()
	{
		cout << "B" << endl;
	}
};

int main()
{
	B b;
	b.print(); // B
	cout << "Adress : " << b.GetThisPointer() << endl;
	cout << "typeid : " << typeid(b.GetThisPointer()).name() << endl;
	// typeid : ��Ÿ�Ӷ� ��ü�� ����(�ڷ���) Ȯ�� ����

	cout << endl << endl;

	A& ref = b; // Up Casting
	ref.print(); // ref�� A Ŭ���� �Ļ��̶� A�� print ȣ��
	cout << "Adress : " << ref.GetThisPointer() << endl; // A�� GetThisPointer�� virtual�̶� B�� ���� �������̵�
	cout << "typeid : " << typeid(ref.GetThisPointer()).name() << endl; // typeid�� A�� ����

	return 0;
}

/*
	RTTI : Run Time Type Information
*/