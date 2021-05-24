#pragma once
#include "Employee.h"
#include "Client.h"
#include <deque>
#include <memory>
#include <algorithm>
#include <vector>

class Counter
{
	static std::set<int> nrsInUse;
	static std::vector<Employee> employeesAssigned;
	int nr; // 4 digits
	Employee employee;
	std::deque<Client> queue;
public:
	Counter(int nr_, const Employee &e, std::deque<Client> queue_ = {});
	bool operator==(const Counter& c);
	bool checkIfNrWithinBounds(const int &counterNr);
	bool checkIfNrIsUnique(const int &counterNr);

	int getNr() const;
	Employee getEmployee();
	std::deque<Client> getQueue();

	void changeCounterNr(int newNr);
	void newClient(Client newCl);
	void clientLeftAfterService();
	void clientLeft(Client cl);
	void clearQueue();
	void assignEmployee(Employee e);
};


