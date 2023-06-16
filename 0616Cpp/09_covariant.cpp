#include <iostream>

using namespace std;

// 공변반환형 --> 반환되는 타입이 달라도 overriding이 가능 --> this를 리턴하는 함수의 경우

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
	// typeid : 런타임때 객체의 형식(자료형) 확인 가능

	cout << endl << endl;

	A& ref = b; // Up Casting
	ref.print(); // ref는 A 클래스 파생이라 A의 print 호출
	cout << "Adress : " << ref.GetThisPointer() << endl; // A의 GetThisPointer는 virtual이라 B의 것을 오버라이딩
	cout << "typeid : " << typeid(ref.GetThisPointer()).name() << endl; // typeid는 A로 잡힘

	return 0;
}

/*
	RTTI : Run Time Type Information
*/