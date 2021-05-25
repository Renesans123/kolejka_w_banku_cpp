#pragma once
#include "Name.h"
#include "Id.h"
#include "Product.h"
#include <vector>
#include <string>
#include <algorithm>

class Client
{
private:
	Name name;
	Id id;
	int clientCode; // 6 digits / can't start with zero
	std::string PIN; // 4 digits
	std::vector<Product> products;
public:
	Client(std::string firstName_, std::string lastName_, std::string idType_, std::string idNr_,
		int clientCode_, std::string PIN_, std::vector<Product> products_ = {});
	bool operator==(const Client& cl);
	bool operator<(const Client& cl);
	std::string getFirstName();
	std::string getLastName();
	std::string getIdType();
	std::string getIdNr();
	int getClientCode() const;
	std::string getPIN();
	std::vector<Product> getProducts();

	bool checkIfClientCodeValid(const int &code);
	bool checkIfPINValid(const std::string &pin);

	void changeClientCode(int newClientCode);

	bool comparePIN(std::string PIN);
	bool compareClientCode(int clientCode);

	void addProduct(const Product& p);
	void removeProduct(const Product& p);
	void clearProducts();
};


