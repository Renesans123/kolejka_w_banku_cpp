#include "Client.h"
#include "mainHeader.h"
using namespace std;

Client::Client(std::string firstName_, std::string lastName_, std::string idType_, std::string idNr_,
	int clientCode_, std::string PIN_, Product product_)
	: name{ Name(firstName_, lastName_) }, id{ Id(idNr_, idType_) }, clientCode{ clientCode_ },
	PIN{ PIN_ }, product{product_}
{
}

bool Client::operator==(const Client& cl)
{
	return (this->getClientCode() == cl.getClientCode());
}

bool Client::operator<(const Client& cl)
{
	return (this->getClientCode() < cl.getClientCode());
}

std::string Client::getFirstName()
{
	return this->name.getFirstName();
}
std::string Client::getLastName()
{
	return this->name.getLastName();
}
std::string Client::getIdType()
{
	return this->id.getType();
}
std::string Client::getIdNr()
{
	return this->id.getPersonalNr();
}
int Client::getClientCode() const
{
	return this->clientCode;
}
std::string Client::getPIN()
{
	return this->PIN;
}
//std::vector<Product> Client::getProducts()
//{
//	return this->products;
//}

bool Client::checkIfClientCodeValid(const int &code)
{
	string code_ = to_string(code);
	if (code_.length() != 6)
		return false;
	for (char c : code_)
		if (!isdigit(c))
			return false;
	return true;
}
bool Client::checkIfPINValid(const string &pin)
{
	if (pin.length() != 4)
		return false;
	for (char c : pin)
		if (!isdigit(c))
			return false;
	return true;
}

void Client::changeClientCode(int newClientCode)
{
	if (!this->checkIfClientCodeValid(newClientCode))
		throw(InvalidClientCode(newClientCode));
	this->clientCode = newClientCode;
}

bool Client::comparePIN(std::string PIN_)
{
	return compareStrings(this->PIN, PIN_);
}

bool Client::compareClientCode(int clientCode_)
{
	return this->clientCode == clientCode_;
}

//void Client::addProduct(const Product& p)
//{
//	if (find(this->products.begin(), this->products.end(), p) != products.end())
//		throw(DuplicateProduct());
//	products.push_back(p);
//}

//void Client::removeProduct(const Product& p)
//{
//	auto it = find(this->products.begin(), this->products.end(), p);
//	if (it == products.end())
//		throw(ProductNotFound(p.getName()));
//	products.erase(it);
//}

Product Client::getProduct() {
	return this->product;
}

bool Client::reduceProductTime() {
	this->product.reducetime();
	return this->product.isDone();
}

const Name& Client::getName() const {
	return name;
}

//void Client::clearProducts()
//{
//	this->products.clear();
//}

bool operator <(const Client &cl, const Client &sc) {
	return (cl.getClientCode() < sc.getClientCode());
}

std::ostream& operator <<(std::ostream &os, Client &l) {
	os<<"Cl:"<<l.getClientCode()<<" "<<l.getName()<<" "<<l.getIdType()<<" "<<l.getIdNr()<<" "<<l.getProduct();
	return os;
}

std::ostream& operator <<(std::ostream &os, set<Client> &l) {
	for (auto c : l)
		os<<" "<<c<<endl;
	return os;
}
