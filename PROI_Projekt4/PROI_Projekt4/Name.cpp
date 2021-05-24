#include "Name.h"
#include "mainHeader.h"

Name::Name(std::string first, std::string last)
	: firstName{ first }, lastName{ last }
{
	removeEndSpaces(firstName); removeAllSpaces(lastName); 
	this->checkCaps(this->firstName); this->checkCaps(this->lastName);
}
Name::Name(const Name& n)
	: firstName{n.getFirstName()}, lastName{ n.getLastName() }
{}
std::string Name::getFirstName() const
{
	return this->firstName;
}
std::string Name::getLastName() const
{
	return this->lastName;
}
void Name::changeFirstName(std::string newFirstName)
{
	this->firstName = newFirstName;
	removeEndSpaces(this->firstName);
	checkCaps(this->firstName);
}
void Name::changeLastName(std::string newLastName)
{
	this->lastName = newLastName;
	removeAllSpaces(this->firstName);
	checkCaps(this->lastName);
}
void Name::checkCaps(std::string& s)
{
	for (auto it = s.begin(); it != s.end(); advance(it, 1))
	{
		if (it == s.begin())
			*it = toupper(*it);
		else
			*it = tolower(*it);
	}
}