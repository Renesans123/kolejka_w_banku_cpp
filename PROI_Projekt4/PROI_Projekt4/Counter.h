#pragma once
#include "Employee.h"
#include "Client.h"
#include <deque>
#include <memory>

class Counter
{
	unsigned nr; // 3 digits?
	Employee employee;
	std::deque<Client> queue;
public:
	Counter(unsigned nr_, Employee e, std::deque<Client> queue_ = {});
	bool operator==(const Counter& c);
	bool checkIfNrValid(unsigned counterNr);
	 
	unsigned getNr() const;
	Employee getEmployee();
	std::deque<Client> getQueue();

	void changeCounterNr(unsigned newNr);
	void newClient(Client newCl);
	void clientLeftAfterService();
	void clientLeft(Client cl);
	void clearQueue();
	void assignEmployee(Employee e);
};


