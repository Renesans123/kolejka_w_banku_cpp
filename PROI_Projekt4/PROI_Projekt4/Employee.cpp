#include "Employee.h"
#include "mainHeader.h"
using namespace std;

set<int> Employee::availableNumbers;

Employee::Employee(std::string firstName, std::string lastName)
: name{Name(firstName, lastName)}
{
		this->setEmployeeNumber();
		this->setStationNumber(0);
}
Employee::~Employee() {
};

int Employee::getEmployeeNumber() const {
	return this->employeeNumber;
};

void Employee::setEmployeeNumber(int employeeNumber) {
	this->employeeNumber = employeeNumber;
};

int Employee::getStationNumber() const {
	return this->stationNumber;
};

void Employee::setStationNumber(int stationNumber) {
	this->stationNumber = stationNumber;
};

const set<permision>& Employee::getPermisionsGranted() const {
	return permissions;
}

void Employee::addPermision(permision permisionGranted) {
	this->permissions.insert(permisionGranted);
	//std::cout<<this->permissions.empty();
}
const set<responsibility>& Employee::getResponsibilities() const {
	return responsibilities;
}
void Employee::removePermision(permision permisionToRemove) {
	this->permissions.erase(permisionToRemove);
	set<responsibility> responsibilitiesToRemove;
	for (auto r : this->getResponsibilities())
		if (!(this->canHaveResposibility(r)))
			responsibilitiesToRemove.insert(r);
	for (auto r : responsibilitiesToRemove)
		this->removeResposibility(r);
}
void Employee::clearPermisions() {
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
void Employee::setEmployeeNumber() {
	if (Employee::availableNumbers.empty())
		Employee::availableNumbers.insert(1);
	this->employeeNumber = *(Employee::availableNumbers).begin();
	if (Employee::availableNumbers.size()==1)
		Employee::availableNumbers.insert(this->employeeNumber+1);
	Employee::availableNumbers.erase(this->employeeNumber);
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

ostream& Employee::operator<<(ostream &os) {
	os<<"name:"<<this->getFirstName()<<" "<<this->getLastName()<<endl;
	os<<"Employee number:"<<this->getEmployeeNumber()<<endl;
	os<<"Permisions:";
	for (auto p : this->getPermisionsGranted()){
		os<<EnumToStr(p)<<" ";
	}
	os<<"\nResponsibilities:";
	for (auto r : this->getResponsibilities()){
		os<<EnumToStr(r)<<" ";
	}
	os<<"\n\n";
	return os;
}
bool Employee::operator<(const Employee& r)
    {
        return this->getEmployeeNumber()< r.getEmployeeNumber();
    }
