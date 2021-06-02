#include "Product.h"

Product::Product(responsibility requiredResponsibility, int time, string name) {
	this->requiredResponsibility=requiredResponsibility;
	this->time=time;
}
bool Product::operator==(const Product& p2)
{
	return (this->getResponsibility() == p2.getResponsibility()) and (this->getTime() == p2.getTime());
}

responsibility Product::getResponsibility() const {
	return requiredResponsibility;
}

void Product::setResponsibility(responsibility requiredResponsibility) {
	this->requiredResponsibility = requiredResponsibility;
}

void Product::reducetime() {
	this->time--;
}

void Product::reducetime(int t) {
	this->time-=t;
}

bool Product::isDone() {
	return this->time<=0;
}

int Product::getTime() const {
	return time;
}

void Product::setTime(int time) {
	this->time = time;
}

const string& Product::getName() const {
	return name;
}

void Product::setName(const string &name) {
	this->name = name;
}

std::ostream& operator <<(std::ostream &os,const Product &l) {
	return os << "Product: '" << EnumToStr(l.getResponsibility()) << "' " << l.getName() << " r. time: " << l.getTime();
}
