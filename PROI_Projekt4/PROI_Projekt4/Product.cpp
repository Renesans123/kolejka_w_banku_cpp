#include "Product.h"

Product::Product(std::string name_)
	: name{name_}
{
}

std::string Product::getName() const
{
	return this->name;
}

bool Product::operator==(const Product& p2)
{
	if (this->getName() == p2.getName())
		return true;
	return false;
}
