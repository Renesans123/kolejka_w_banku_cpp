#pragma once
#include <string>
class Product
{
	std::string name;

public:
	Product(std::string name_);
	std::string getName() const;
	bool operator==(const Product& p2);
};

