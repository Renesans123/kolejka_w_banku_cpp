#include "Id.h"
#include "mainHeader.h"
#include <string>
using namespace std;

const vector<string> Id::validIdTypes = { "Identity Card", "Passport", "Driver's License" };

Id::Id(string IdNr, string IdType)
	: personalNr{ IdNr }, type{ IdType }
{
	if (!checkType(this->type)) // throw exceptions
		throw (InvalidIdType(this->type));
	if (!checkPersonalNr(this->personalNr))
		throw(InvalidIdNr(this->personalNr));
};

Id::Id()
{
	this->setRandomNr();
	this->setRandomType();
}

void Id::setRandomNr() // 11 digits
{
	this->personalNr = to_string(10000 + rand() % 90000) + to_string(100000 + rand() % 900000); // + 6 digits
}

void Id::setRandomType()
{
	this->type = Id::validIdTypes[rand() % validIdTypes.size()];
}

string Id::getPersonalNr()
{
	return this->personalNr;
}

string Id::getType()
{
	return this->type;
}

void Id::changePersonalNr(string newNr)
{
	if (!checkPersonalNr(newNr))
		throw(InvalidIdNr(newNr));
	this->personalNr = newNr;
}

void Id::changeType(string newType)
{
	if (!checkType(newType))
		throw(InvalidIdType(newType));
	this->type = newType;
}

bool Id::checkType(string& t)// checks if entered type is valid
{
	removeEndSpaces(t);
	for (string validType : Id::validIdTypes)
		if (t == validType)
			return true;
	return false;
}

bool Id::checkPersonalNr(string nr)// checks if its a series of 11 integers
{
	if (nr.length() != 11)
		return false;
	for (char c : nr)
	{
		if (!isdigit(c))
			return false;
	}
	return true;
}