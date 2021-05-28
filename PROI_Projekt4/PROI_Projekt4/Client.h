#pragma once
#include "Name.h"
#include "Id.h"
#include "Product.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Client
{
private:
	Name name;
	Id id;
	int clientCode; // 6 digits / can't start with zero
	std::string PIN; // 4 digits
	Product product;
public:
	Client(std::string firstName_, std::string lastName_, std::string idType_, std::string idNr_,
		int clientCode_, std::string PIN_, Product product);
	bool operator==(const Client& cl);
	bool operator<(const Client& cl);
	std::string getFirstName();
	std::string getLastName();
	std::string getIdType();
	std::string getIdNr();
	bool reduceProductTime();
	int getClientCode() const;
	std::string getPIN();
//	std::vector<Product> getProducts();
	Product getProduct();

	bool checkIfClientCodeValid(const int &code);
	bool checkIfPINValid(const std::string &pin);

	void changeClientCode(int newClientCode);

	bool comparePIN(std::string PIN);
	bool compareClientCode(int clientCode);

//	void addProduct(const Product& p);
//	void removeProduct(const Product& p);
//	void clearProducts();
	const Name& getName() const;
};

bool operator<(const Client& cl, const Client& sc);
std::ostream& operator<<(std::ostream& os, Client& l);
std::ostream& operator<<(std::ostream& os, set<Client>& l);
