#include <iostream>

using namespace std;

class Animal
{
public:
	virtual void printType()
	{
		cout << "Animal" << endl;
	}
};

class Pig : public Animal
{
public:
	virtual void printType() override
	{
		cout << "Pig" << endl;
	}
	void eat()
	{
		cout << "Eat pig!!" << endl;
	}
};

int main()
{
	Animal* pig = new Pig();
	(*pig).printType();
}