#include "Bank.h"
#include <random>
#include <fstream>
#include <time.h>
#include <iomanip>

#define P(s) cout<<s;file<<s;

using namespace std;

set<string> Bank::randomFirstNames;
set<string> Bank::randomSecondNames;

Bank::Bank(int m, int n) {
	if (randomFirstNames.empty() or randomSecondNames.empty())
		loadRandomNames("firstname.txt", "surname.txt");
	loadEmployees(m);
	loadClients(n);
	loadCounters(); // assuming that the nr of counters = nr of employees
}

void Bank::loadRandomNames(string firstNameFile, string lastNameFile) {
	ifstream file1(firstNameFile);
	string s;
	if (file1.is_open())
	{
		while (getline(file1, s))
		{
			randomFirstNames.insert(s);
		}
	}
	else
		throw(FileNotFoundError(firstNameFile));
	file1.close();

	ifstream file2(lastNameFile);
	if (file2.is_open())
	{
		while (getline(file2, s))
		{
			randomSecondNames.insert(s);
		}
	}
	else
		throw(FileNotFoundError(lastNameFile));
	file2.close();
}

string Bank::getRandomFirstName() 		// pick random first name
{
	auto it = randomFirstNames.cbegin();
	advance(it, rand() % randomFirstNames.size());
	return *it;
}

string Bank::getRandomLastName() 		// pick random last name
{
	auto it = randomSecondNames.cbegin();
	advance(it, rand() % randomSecondNames.size());
	return *it;
}

void Bank::loadCounters() {
	for (auto e : this->getEmployees())
		counters.push_back(Counter(e));
}

void Bank::loadEmployees(int m)
{
	for (int var = 0; var < m; ++var) {
		// pick random set of permissions
		permission permissionGranted = static_cast<permission>(rand() % lastPermission);
		// initialize an employee with those parameters and random first/last name
		Employee e = Employee(this->getRandomFirstName(), this->getRandomLastName());
		e.addPermission(permissionGranted);
		for (responsibility r : possibleResponsibilities[permissionGranted])
			e.addResponsibility(r);

		this->employees.insert(e);
	}
}

void Bank::loadClients(int n)
{
	for (int var = 0; var < n; ++var)
	{
		int Ptime = 5 + rand() % 12;
		responsibility requiredResponsibility = static_cast<responsibility>(rand() % lastResponsibilty);
		Client e = Client(this->getRandomFirstName(), this->getRandomLastName(), Product(requiredResponsibility, Ptime, ""));
		this->clients.insert(e);
	}
}

void Bank::loadQueues()
{
	for (Client c : this->getClients())
	{
		sort(this->counters.begin(), this->counters.end()); // < operator for counters is overloaded - sorting is done based on queue length
		this->counters[0].newClient(c);
	}
}

bool Bank::allQueuesEmpty()
{
	bool r = true;
	for (Counter c : this->counters)
		if (c.getQueueSize() != 0)
			r = false;
	return r;
}

ostream& operator <<(ostream& os, Bank& l)
{
	os << setw(21) << setfill('=') << right << " " << "BANK SIMULATION " << setw(21) << setfill('=') << " " << endl;
	set<Employee> e = l.getEmployees();
	set<Client> cl = l.getClients();
	vector<Counter> co = l.getCounters();

	os << "-> EMPLOYEES:\n\n";
	os << e;
	os << "-> CLIENTS:\n\n";
	os << cl;
	os << "\n-> COUNTERS:";
	os << co;

	return os;
}


void Bank::simulate(double update_time)
{
	ofstream file("BankLogs.txt");
	this->loadQueues();
	P(*this);

	P("\n\nSIMULATION:\n")
	int time = 0;
	while (!allQueuesEmpty())
	{
		for (unsigned int i{}; i < counters.size(); i++)
		{
			if (counters[i].getQueueSize()!=0 && counters[i].handleClient())
			{
				// At [time]:
				// Employee [name], id: [nr] of designation [permission]
				// helped client [name], code: [clientCode]
				// with [responsibility]
				P("T: " << time << " - " << counters[i].getEmployee().getFirstName() << " "
					<< counters[i].getEmployee().getLastName() << " helped client: " << counters[i].getfront().getFirstName() << " "
					<< counters[i].getfront().getLastName() << " with action '" << EnumToStr(counters[i].getfront().getProduct().getResponsibility()) << "'.\n");
				counters[i].clientLeftAfterService();
				//sleep((int)(update_time));
			}
		}
		time ++;
	}
	file.close();
	P(setw(21) << setfill('=') << right << " " << "END OF SIMULATION " << setw(21) << setfill('=') << " " << endl);
}





const set<Client>& Bank::getClients() const {
	return clients;
}

void Bank::setClients(const set<Client> &clients) {
	this->clients = clients;
}

const vector<Counter>& Bank::getCounters() const {
	return counters;
}

void Bank::setCounters(const vector<Counter> &counters) {
	this->counters = counters;
}

const set<Employee>& Bank::getEmployees() const {
	return employees;
}

void Bank::setEmployees(const set<Employee> &employees) {
	this->employees = employees;
}



