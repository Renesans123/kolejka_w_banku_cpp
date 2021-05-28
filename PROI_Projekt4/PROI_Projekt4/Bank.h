#pragma once
#include "mainHeader.h"
#include "Employee.h"
#include "vector"

class Bank
{
	vector<Counter> counters;
	set<Employee> employees;
	set<Client> clients;

	static set<string> randomFirstNames;
	static set<string> randomSecondNames;
public:
	Bank(int m, int n);
	void loadEmployees(int m);
	void loadClients(int n);
	void loadCounters();
	void Loadqueues();

	void Simulate(double update_time);
	bool queuesEmpty();
	const set<Client>& getClients() const;
	void setClients(const set<Client> &clients);
	const vector<Counter>& getCounters() const;
	void setCounters(const vector<Counter> &counters);
	const set<Employee>& getEmployees() const;
	void setEmployees(const set<Employee> &employees);
	void loadRandomNames();
};
std::ostream& operator<<(std::ostream& os, Bank& l);
