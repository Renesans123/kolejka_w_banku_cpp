#include "Bank.h"
#include <unistd.h>
#include <random>
#include <fstream>
#include <time.h>

#define P(s) cout<<s;file<<s;

using namespace std;

set<std::string> Bank::randomFirstNames;
set<std::string> Bank::randomSecondNames;

Bank::Bank(int m, int n) {
	srand( (unsigned)time(NULL) );
	if (randomFirstNames.empty() or randomSecondNames.empty())
		loadRandomNames();
	loadEmployees(m);
	loadClients(n);
	loadCounters();
}

void Bank::Simulate(double update_time) {
	ofstream file("BankLogs.txt");
	Loadqueues();
	P(*this);
	P("Queues:\n")
	int time = 1;
	for (Counter c : counters){
		P(c);
	}
	P("Symulation:\n")
	while (!queuesEmpty()) {
		for (unsigned int i=0; i<counters.size();i++){
			if (counters[i].getSize()!=0 and counters[i].handleClient()){
				P("t:"<<time<<" "<<counters[i].getEmployee().getFirstName()<<" "<<counters[i].getEmployee().getLastName()<<" handled client: "<<counters[i].getfront().getFirstName()<<" "<<counters[i].getfront().getLastName()<<"\n");
				counters[i].clientLeftAfterService();
				//sleep((int)(update_time));
			}
		}
		time ++;
	}
	file.close();
}

void Bank::loadClients(int n) {
	responsibility requiredResponsibility;
	int clientCode,Ptime;
	string firstName,lastName,idType,idNr,PIN;
	for (int var = 0; var < n; ++var) {
		auto r = randomFirstNames.cbegin();
		advance(r, rand() % randomFirstNames.size());
		firstName = *r;
		r = randomSecondNames.cbegin();
		advance(r, rand() % randomSecondNames.size());
		lastName = *r;
		idType = Id::validIdTypes[rand() % 3];
		idNr = to_string(10000 + rand() % 10000);
		idNr += to_string(100000 + rand() % 100000);
		clientCode = 100000 + rand() % 100000;
		Ptime = 5 + rand() % 12;
		PIN = to_string(1000 + rand() % 1000);
		Client e = Client(firstName, lastName , idType , idNr ,clientCode, PIN, Product(requiredResponsibility, Ptime, ""));
		requiredResponsibility = static_cast<responsibility>(rand() % new_user_help);
		clients.insert(e);
	}
}

void Bank::loadEmployees(int m) {
	string firstName,lastName;
	permision permisionGranted;
	auto r = randomFirstNames.cbegin();
	for (int var = 0; var < m; ++var) {
		r = randomFirstNames.cbegin();
		advance(r, rand() % randomFirstNames.size());
		firstName = *r;
		r = randomSecondNames.cbegin();
		advance(r, rand() % randomSecondNames.size());
		lastName = *r;
		permisionGranted = static_cast<permision>(rand() % account_manager);
		Employee e = Employee(firstName, lastName);
		e.addPermision(permisionGranted);
		for (responsibility r :possibleResponsibilities[permisionGranted])
			e.addResponsibility(r);
		employees.insert(e);
	}
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

bool Bank::queuesEmpty() {
	bool r = true;
	for (Counter c : this->counters)
		if (c.getSize()!=0)
			r = false;
	return r;
}

void Bank::loadCounters() {
	for (auto e : this->getEmployees())
		counters.push_back(Counter(e.getEmployeeNumber()+1000, e));
}

void Bank::Loadqueues() {
	for (Client c : this->getClients()){
		Counter cont = counters[rand() % counters.size()];
		Counter shortestQueue = cont;
		for (int i =0; i<4; i++){
			if (cont.canHandleProdukt(c.getProduct()) and cont.getSize()<shortestQueue.getSize())
				shortestQueue = cont;
		}
		counters[rand() % counters.size()].newClient(c);
	}
}

void Bank::loadRandomNames() {
	ifstream file1("firstname.txt");
	string s;
	while (getline (file1, s)) {
		randomFirstNames.insert(s);
	}
	file1.close();

	ifstream file2("surname.txt");
	while (getline (file2, s)) {
		randomSecondNames.insert(s);
	}
	file1.close();
}

std::ostream& operator <<(std::ostream &os, Bank &l) {
	set<Employee> e = l.getEmployees();
	set<Client> c = l.getClients();
	os<<"Employees"<<endl;
	os<<e;
	os<<"Clients"<<endl;
	os<<c;
	return os;
}
