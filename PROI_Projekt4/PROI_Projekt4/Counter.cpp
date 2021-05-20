#include "Counter.h"
#include <string>
#include <algorithm>
using namespace std;

Counter::Counter(unsigned nr_, Employee e, std::deque<Client> queue_)
	: nr{ nr_ }, employee{ e }, queue{queue_}
{
	if (!this->checkIfNrValid(this->nr))
		throw(InvalidCounterNr(this->nr));
}

bool Counter::operator==(const Counter& c)
{
	if (this->getNr() == c.getNr())
		return true;
	return false;
}

bool Counter::checkIfNrValid(unsigned counterNr)
{
	string n = to_string(counterNr);
	if (n.length() != 4)
		return false;
	return true;
}

unsigned Counter::getNr() const
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

void Counter::changeCounterNr(unsigned newNr)
{
	if (!this->checkIfNrValid(newNr))
		throw(InvalidCounterNr(newNr));
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
