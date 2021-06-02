#pragma once
#include "Exceptions.h"
#include <string>
#include <vector>

class Id
{
private:
	std::string personalNr; // 11 digits
	std::string type;
public:
	static const std::vector<std::string> validIdTypes;
	Id(std::string IdNr, std::string IdType);
	Id();
	void setRandomNr(); // 11 digits
	void setRandomType();
	std::string getPersonalNr();
	std::string getType();
	void changePersonalNr(std::string newNr);
	void changeType(std::string newType);
	bool checkPersonalNr(std::string n);
	bool checkType(std::string& t);
};


