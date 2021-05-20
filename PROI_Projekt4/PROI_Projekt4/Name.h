#pragma once
#include <string>
#include <iterator>

class Name
{
private:
	std::string firstName;
	std::string lastName;
public:
	Name(std::string first, std::string last);
	std::string getFirstName();
	std::string getLastName();
	void changeFirstName(std::string newFirstName);
	void changeLastName(std::string newLastName);
	void checkCaps(std::string& s);
};

