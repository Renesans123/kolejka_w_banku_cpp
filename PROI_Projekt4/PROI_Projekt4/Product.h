#pragma once
#include <string>
#include "permission.h"
using namespace std;

class Product
{

	responsibility requiredResponsibility;
	int time;
	string name;

public:
	Product(responsibility requiredResponsibility, int time, string name);
	bool operator==(const Product& p2);
	responsibility getResponsibility() const;
	void setResponsibility(responsibility requiredResponsibility);
	void reducetime();
	void reducetime(int t);
	bool isDone();
	int getTime() const;
	void setTime(int time);
	const string& getName() const;
	void setName(const string &name);
};
std::ostream& operator<<(std::ostream& os,const Product& l);
