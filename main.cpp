#include <iostream>
#include <vector>
#include "Animal.h"
#include "Lion.h"
#include "Tiger.h"
int main()
{
	std::vector<Animal*> animals;
	animals.push_back(new Lion());
	animals.push_back(new Tiger());
	for (auto animal : animals)
	{
		animal->Move();
	}
	for (auto animal : animals)
	{
		delete animal;
	}
	animals.clear();
	return 0;
}