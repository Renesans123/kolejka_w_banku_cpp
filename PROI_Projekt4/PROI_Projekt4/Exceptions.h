#pragma once
#include <string>
#include <exception>

class InvalidIdType : public std::exception
{
private:
	std::string input;
public:
	InvalidIdType(std::string s)
		: input{ s }
	{};
	std::string what()
	{
		return "\n'" + this->input + "' is not a Valid Id Type!\n";
	}
};

class InvalidIdNr : public std::exception
{
private:
	std::string input;
public:
	InvalidIdNr(std::string s)
		: input{ s }
	{};
	std::string what()
	{
		return "\n'" + this->input + "' is not a Valid Id Number!\n";
	}
};

class InvalidClientCode : public std::exception
{
	int code;
public:
	InvalidClientCode(int code_)
		: code { code_ }
	{};
	std::string what()
	{
		return "\n'" + std::to_string(code) + "'is not a valid client code.\n";
	}
};

class DuplicateProduct : public std::exception
{
public:
	DuplicateProduct() = default;
	std::string what()
	{
		return "\nDuplicate products are not allowed!\n";
	}
};

class ProductNotFound : public std::exception
{
	std::string productName;
public:
	ProductNotFound(std::string productName_)
		: productName{ productName_ }
	{};
	std::string what()
	{
		return "\nProduct '" + productName + "' not found.\n";
	}
};

class InvalidCounterNr : public std::exception
{
	int nr;
public:
	InvalidCounterNr(int nr_)
		: nr{ nr_ }
	{};
	std::string what()
	{
		return "\nProduct '" + std::to_string(this->nr) + "' not found.\n";
	}
};

class DuplicateCounterNr : public std::exception
{
	int nr;
public:
	DuplicateCounterNr(int nr_)
		: nr{ nr_ }
	{};
	std::string what()
	{
		return "\nCounter numbers must be unique! Nr '" + std::to_string(this->nr) + "' already in use.\n";
	}
};

class CounterNrNotFound : public std::exception
{
	std::string what()
	{
		return "\nCounter Nr not found. \n";
	}
};

class ClientNotFound : public std::exception
{
	int code;
public:
	ClientNotFound(int code_)
		: code{ code_ }
	{};
	std::string what()
	{
		return "\nClient with a code '" + std::to_string(code) + "'was not found.\n";
	}
};

