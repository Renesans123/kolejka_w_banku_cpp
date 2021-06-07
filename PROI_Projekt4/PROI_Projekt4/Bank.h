#pragma once
#include "mainHeader.h"

class Bank
{
	vector<Counter> counters{};
	set<Employee> employees{};
	set<Client> clients{};

	static set<string> randomFirstNames;
	static set<string> randomSecondNames;
public:
	Bank(int m, int n);

	string getRandomFirstName();
	string getRandomLastName();

	void loadEmployees(int m);
	void loadClients(int n);
	void loadCounters();
	void loadQueues();

	void simulate(string filename);
	bool allQueuesEmpty();
	const set<Client>& getClients() const;
	void setClients(const set<Client> &clients);
	const vector<Counter>& getCounters() const;
	void setCounters(const vector<Counter> &counters);
	const set<Employee>& getEmployees() const;
	void setEmployees(const set<Employee> &employees);
	void loadRandomNames(string, string);
};
std::ostream& operator<<(std::ostream& os, Bank& l);
