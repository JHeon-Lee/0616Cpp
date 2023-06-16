#include <iostream>

using namespace std;

// 자식클래스가 부모클래스의 함수를 재정의 --> 이름, 매개변수는 같아야함 

class A /* final --> 붙이게 되면 상속 불가 */
{
public:
	virtual void Print(int x) { cout << "A" << endl; }
	// virtual 붙이면 재정의된다는걸 알려주게됨
};

class B : public A
{
public:
	void Print(int x) override /*final*/ { cout << "B" << endl; } // overriding!
	// void Print(short x) 가 되면 overloading으로 인식함
	// override 를 붙혀주면 안헷갈림
	// final 이 붙으면 여기까지 상속시키겠다는걸 의미함 (이 클래스를 부모로 사용 불가능)
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

	a1.Print(0); // A 나옴
	a2.Print(0); // A 나옴 --> Up casting 이나 포인터가 실질적으로 가리키는 클래스로 정의됨
	// --> virtual 사용하면 해결(B, C 나옴)

	return 0;
}