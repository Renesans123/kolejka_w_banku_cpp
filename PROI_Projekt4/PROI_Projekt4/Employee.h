#pragma once
#include "Name.h"
#include <string>

class Employee
{
	Name name;
public:
	Employee(std::string firstName, std::string lastName)
		: name{Name(firstName, lastName)}
	{}
	Name getName()
	{
		return this->name;
	}
};


