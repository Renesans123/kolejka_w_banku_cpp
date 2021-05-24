#pragma once
#include "Employee.h"
#include "Client.h"
#include <deque>
#include <memory>
#include <algorithm>

class Counter
{
	static std::set<int> nrsInUse;
	static std::set<Employee> employeesAssigned;
	int nr; // 4 digits - counter nr is unique
	Employee employee; // each employee can only be assigned to one counter at a time 
	std::deque<Client> queue;
public:
	Counter(int nr_, const Employee &e, std::deque<Client> queue_ = {});
	bool operator==(const Counter& c) const noexcept;
	bool checkIfNrWithinBounds(const int &counterNr);
	bool checkIfNrIsUnique(const int &counterNr);
	bool checkIfEmployeeIsFree(const Employee& e) const;

	int getNr() const;
	Employee getEmployee() const;
	std::deque<Client> getQueue() const;
	int getNrsInUseSize();

	void changeCounterNr(int newNr);
	void newClient(Client newCl);
	void clientLeftAfterService();
	void clientLeft(Client cl);
	void clearQueue();
	void assignEmployee(Employee e);
	void dismissEmployee(const Employee &e) const;
};


