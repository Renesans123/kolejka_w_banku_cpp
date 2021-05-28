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
	bool operator==(const Counter& c) const noexcept;
	bool checkIfNrWithinBounds(const int &counterNr);
	bool checkIfNrIsUnique(const int &counterNr);
	bool checkIfEmployeeIsFree(const Employee& e) const;
	bool canHandleProdukt(Product) const;
	bool handleClient();

	int getNr() const;
	Employee getEmployee();
	std::deque<Client> getQueue();
	int getNrsInUseSize();
	int getSize();
	Client getfront();

	void changeCounterNr(int newNr);
	void newClient(Client newCl);
	void clientLeftAfterService();
	void clientLeft(Client cl);
	void clearQueue();
	void assignEmployee(Employee e);
	void dismissEmployee(const Employee &e) const;
};
bool operator<(const Counter& c,const Counter& d);
std::ostream& operator<<(std::ostream& os, Counter& l);
std::ostream& operator<<(std::ostream& os, vector<Counter>& l);

