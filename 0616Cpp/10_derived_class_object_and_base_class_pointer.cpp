#include <iostream>

using namespace std;

class Animal
{
public:
	Animal(string name) : name(name){}

	virtual void Speak() const { cout << "??" << endl; }

protected:
	string name;
};

class Cat : public Animal
{
public:
	Cat(string name) : Animal(name) {}
	void Speak() const override { cout << "야옹" << endl; }
};

class Dog : public Animal
{
public:
	Dog(string name) : Animal(name) {}
	void Speak() const override { cout << "멍멍" << endl; }
};

int main()
{
	Cat cats[]{ Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
	Dog dogs[]{ Dog("dog1"), Dog("dog2"), Dog("dog3"), Dog("dog4"), Dog("dog5") };

	for (const auto& cat : cats)
		cat.Speak();

	for (const auto& dog : dogs)
		dog.Speak();

	cout << endl << endl;

	// 위 보다 밑의 Up casting을 사용하자
	Animal* animals[]
	{
		&cats[0],
		&cats[1],
		&cats[2],
		&cats[3],
		&cats[4],
		&dogs[0],
		&dogs[1],
		&dogs[2],
		&dogs[3],
		&dogs[4],
	};

	for (const auto& animal : animals)
		animal->Speak();
	// virtual을 안적어두면 cats, dogs 모두 ?? 로 뜨게됨

	return 0;
}