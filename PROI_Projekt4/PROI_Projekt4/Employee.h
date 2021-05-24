#pragma once
#include "Name.h"
#include <string>
#include "permision.h"
#include <set>
#include <iostream>

class Employee
{
	Name name;
	static set<int> availableNumbers;
	int employeeNumber;
	//int stationNumber;
	//set<permision> permissions;
	//set<responsibility> responsibilities;
public:
	Employee(std::string firstName, std::string lastName, int employeeNr=0);
	Name getName() const;
		//virtual ~Employee();
	int getEmployeeNumber() const;
	bool operator==(const Employee& rhs) const noexcept;
	bool operator<(const Employee& r) const noexcept;

		//void setEmployeeNumber(int empoyeeNumber);
		//void setEmployeeNumber();
		//string getFirstName();
		//string getLastName();
		//int getStationNumber() const;
		//void setStationNumber(int stationNumber);
		//const set<permision>& getPermisionsGranted() const;
		//void addPermision(permision permisionGranted);
		//void removePermision(permision permisionToRemove);
		//void clearPermisions();
		//bool canHaveResposibility(const responsibility resp);
		//bool addResponsibility(responsibility responsibilityAdded);
		//void removeResposibility(responsibility responsibilityToRemove);
		//void clearResponsiblities();
		//const set<responsibility>& getResponsibilities() const;
		//std::ostream& operator<<(std::ostream& os);
};
