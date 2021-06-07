#pragma once
#include "Name.h"
#include <string>
#include "permission.h"
#include <set>
#include <iostream>

class Employee
{
	Name name;
	static set<int> takenNumbers;
	int employeeNumber{}; // 4 digits
	set<permission> permissions;
	set<responsibility> responsibilities;
public:
	Employee(std::string firstName, std::string lastName);
	Employee(std::string firstName, std::string lastName, int nr);
	Name getName();
	virtual ~Employee();
	void generateEmployeeNumber();
	int getEmployeeNumber() const;
	void setEmployeeNumber(int);
	string getFirstName();
	string getLastName();
	const set<permission>& getPermissionsGranted() const;
	void addPermission(permission permissionGranted);
	void removePermission(permission permissionToRemove);
	void clearPermissions();
	bool canHaveResposibility(const responsibility resp);
	bool addResponsibility(responsibility responsibilityAdded);
	void removeResposibility(responsibility responsibilityToRemove);
	void clearResponsiblities();
	const set<responsibility>& getResponsibilities() const;
	bool operator<(const Employee& r);
};
bool operator==(const Employee& l, const Employee& r);
bool operator<(const Employee& l, const Employee& r);
std::ostream& operator<<(std::ostream& os, Employee& l);
std::ostream& operator<<(std::ostream& os, set<Employee>& l);
