#include "Counter.h"
#include <string>
#include <algorithm>
using namespace std;

set<int> Counter::nrsInUse{};
vector<Employee> Counter::employeesAssigned{};

Counter::Counter(int nr_, const Employee &e, std::deque<Client> queue_)
	: employee{ e }, queue{queue_}
{
	if (!this->checkIfNrWithinBounds(nr_))
		throw(InvalidCounterNr(nr_));
	if (!this->checkIfNrIsUnique(nr_))
		throw(DuplicateCounterNr(nr_));
	nrsInUse.insert(nr_);
	this->nr = nr_;

}

bool Counter::operator==(const Counter& c)
{
	return (this->getNr() == c.getNr()) ? true : false;
}

bool Counter::checkIfNrWithinBounds(const int &counterNr)
{
	return (counterNr < 1000 || counterNr > 9999) ? false : true; // check if the nr's 4-digit
}

bool Counter::checkIfNrIsUnique(const int &counterNr)
{
	// check if nr's not alrsady used - must be unique
	return (find(nrsInUse.begin(), nrsInUse.end(), counterNr) != nrsInUse.end()) ? false : true;
}

int Counter::getNr() const
{
	return this->nr;
}
Employee Counter::getEmployee()
{
	return this->employee;
}
std::deque<Client> Counter::getQueue()
{
	return this->queue;
}

void Counter::changeCounterNr(int newNr)
{
	if (!this->checkIfNrWithinBounds(newNr))
		throw(InvalidCounterNr(newNr));
	if (!this->checkIfNrIsUnique(newNr))
		throw(DuplicateCounterNr(newNr));
	auto it = find(nrsInUse.begin(), nrsInUse.end(), this->nr);
	if (it == nrsInUse.end())
		throw(CounterNrNotFound());
	nrsInUse.erase(this->nr);
	nrsInUse.insert(newNr);
	this->nr = newNr;
}

void Counter::newClient(Client newCl)
{
	this->queue.push_back(newCl);
}

void Counter::clientLeftAfterService()
{
	if (this->queue.size() > 0)
		this->queue.pop_front();
}

void Counter::clientLeft(Client cl)
{
	auto it = find(this->queue.begin(), this->queue.end(), cl);
	if (it == this->queue.end())
		throw(ClientNotFound(cl.getClientCode()));
	this->queue.erase(it);
}

void Counter::clearQueue()
{
	this->queue.clear();
}

void Counter::assignEmployee(Employee e)
{
	this->employee = e;
}
