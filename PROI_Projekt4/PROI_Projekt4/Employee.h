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
	int employeeNumber,stationNumber;
	set<permision> permissions;
	set<responsibility> responsibilities;
public:
	Employee(std::string firstName, std::string lastName);
	Name getName();
	virtual ~Employee();
	int getEmployeeNumber() const;
	void setEmployeeNumber(int empoyeeNumber);
	void setEmployeeNumber();
	string getFirstName();
	string getLastName();
	int getStationNumber() const;
	void setStationNumber(int stationNumber);
	const set<permision>& getPermisionsGranted() const;
	void addPermision(permision permisionGranted);
	void removePermision(permision permisionToRemove);
	void clearPermisions();
	bool canHaveResposibility(const responsibility resp);
	bool addResponsibility(responsibility responsibilityAdded);
	void removeResposibility(responsibility responsibilityToRemove);
	void clearResponsiblities();
	const set<responsibility>& getResponsibilities() const;
	bool operator<(const Employee& r);
	std::ostream& operator<<(std::ostream& os);
};
bool operator==(const Employee& l, const Employee& r);
bool operator<(const Employee& l, const Employee& r);
std::ostream& operator<<(std::ostream& os, Employee& l);
std::ostream& operator<<(std::ostream& os, set<Employee>& l);
