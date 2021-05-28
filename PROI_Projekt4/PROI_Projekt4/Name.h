#pragma once
#include <string>
#include <iterator>
#include <iostream>

class Name
{
private:
	std::string firstName;
	std::string lastName;
public:
	Name(std::string first, std::string last);
	Name(const Name& n);
	std::string getFirstName() const;
	std::string getLastName() const;
	void changeFirstName(std::string newFirstName);
	void changeLastName(std::string newLastName);
	void checkCaps(std::string& s);
};
std::ostream& operator<<(std::ostream& os,const Name& l);
