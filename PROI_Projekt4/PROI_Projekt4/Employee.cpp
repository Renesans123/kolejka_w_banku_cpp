#include "Employee.h"
#include "mainHeader.h"
using namespace std;

set<int> Employee::takenNumbers{};
Name Employee::getName()
{
	return this->name;
}

Employee::Employee(string firstName, string lastName)
: name{Name(firstName, lastName)}
{
	this->generateEmployeeNumber();
}

Employee::Employee(string firstName, string lastName, int nr)
	: name{ Name(firstName, lastName) }, employeeNumber{nr}
{}


Employee::~Employee() {
};

void Employee::generateEmployeeNumber()
{
	bool foundNr{ false };
	if (takenNumbers.size() >= 9000)
		throw(AllNumbersTakenError());
	while (!foundNr)
	{
		int nr = rand() % 9000 + 1000;
		if (find(takenNumbers.begin(), takenNumbers.end(), nr) == takenNumbers.end())
		{
			foundNr = true;
			this->employeeNumber = nr;
			takenNumbers.insert(nr);
		}
	}
}

void Employee::setEmployeeNumber(int newNr) {
	if (takenNumbers.size() >= 9000)
		throw(AllNumbersTakenError());
	auto itNewNr = find(takenNumbers.begin(), takenNumbers.end(), newNr);
	if (itNewNr != takenNumbers.end())
		throw(EmployeeNumberTaken(newNr));
	else
	{
		// delete current number from takenNumbers
		auto it = find(takenNumbers.begin(), takenNumbers.end(), this->employeeNumber);
		if (it != takenNumbers.end())
		{
			takenNumbers.erase(it);
		}
		this->employeeNumber = newNr;
		takenNumbers.insert(newNr);
	}
}

int Employee::getEmployeeNumber() const {
	return this->employeeNumber;
};

const set<permission>& Employee::getPermissionsGranted() const
{
	return this->permissions;
}

void Employee::addPermission(permission permissionGranted) {
	this->permissions.insert(permissionGranted);
}
const set<responsibility>& Employee::getResponsibilities() const {
	return responsibilities;
}
void Employee::removePermission(permission permissionToRemove) {
	this->permissions.erase(permissionToRemove);
	set<responsibility> responsibilitiesToRemove;
	for (auto r : this->getResponsibilities())
		if (!(this->canHaveResposibility(r)))
			responsibilitiesToRemove.insert(r);
	for (auto r : responsibilitiesToRemove)
		this->removeResposibility(r);
}
void Employee::clearPermissions() {
	this->permissions.clear();
}

bool Employee::addResponsibility(responsibility responsibilityAdded) {
	if (this->canHaveResposibility(responsibilityAdded)){
		this->responsibilities.insert(responsibilityAdded);
		return true;
	}
	return false;
}

void Employee::removeResposibility(responsibility responsibilityToRemove) {
	this->responsibilities.erase(responsibilityToRemove);
}

bool Employee::canHaveResposibility(const responsibility resp) {
	for (auto p : this->permissions){
		if (possibleResponsibilities[p].count(resp))
			return true;
	}
	return false;
}

void Employee::clearResponsiblities() {
	this->responsibilities.clear();
}

string Employee::getFirstName()
{
	return this->getName().getFirstName();
}
string Employee::getLastName()
{
	return this->getName().getLastName();
}

bool Employee::operator<(const Employee& r)
{
    return this->getEmployeeNumber()< r.getEmployeeNumber();
}

bool operator<(const Employee& l, const Employee& r)
{
        return l.getEmployeeNumber()< r.getEmployeeNumber();
}

bool operator ==(const Employee &l, const Employee &r) {
	return l.getEmployeeNumber()==r.getEmployeeNumber();
}

std::ostream& operator <<(std::ostream &os, Employee &l) {
	os << "Name: " << l.getFirstName() << " " << l.getLastName() << " | "
		<< "Employee number: " << l.getEmployeeNumber() << endl;
	os << "Designation:";
	for (auto p : l.getPermissionsGranted())
	{
		os << " " << EnumToStr(p) << " |";
	}
	os << "\b \nPermissions: ";
	for (auto r : l.getResponsibilities())
	{
		os << " " << EnumToStr(r) << " |";
	}
	os << "\b \n";
	return os;
}

std::ostream& operator <<(std::ostream &os, set<Employee> &l) {
	for (auto e: l)
		os << e << endl;
	return os;
}
