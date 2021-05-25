#include "catch.hpp"

#include "mainHeader.h"
using namespace std;

TEST_CASE("function removeEndSpaces and function removeAllSpaces")
{
	string s{" sad ads wasdaw s    "};
	removeEndSpaces(s);
	REQUIRE(s == "sad ads wasdaw s");
	s = " p e p e   g  a ";
	removeAllSpaces(s);
	REQUIRE(s == "pepega");
}

TEST_CASE("Name class")
{
	SECTION("Name class constructor")
	{
		Name name("Tom", "Bombadil");
		REQUIRE(name.getFirstName() == "Tom");
		REQUIRE(name.getLastName() == "Bombadil");
	}
	SECTION("'Name::checkCaps' function")
	{
		Name name("TOm", "bombadIll");
		REQUIRE(name.getFirstName() == "Tom");
		REQUIRE(name.getLastName() == "Bombadill");
	}
	SECTION("changing first/last name")
	{
		Name name("TOm", "bombadIll");
		name.changeFirstName("jOhn");
		REQUIRE(name.getFirstName() == "John");
		name.changeLastName("ConNors");
		REQUIRE(name.getLastName() == "Connors");
	}
}

TEST_CASE("ID class")
{
	SECTION("Id class constructor")
	{
		Id id("21304124241", "Identity Card");
		REQUIRE(id.getPersonalNr() == "21304124241");
		REQUIRE(id.getType() == "Identity Card");
		id = Id("21304124241", "   Identity Card");
		REQUIRE(id.getType() == "Identity Card");
	}
	// REQUIRE_THROWS_AS(expression, exception type) 
	//expects that an exception (of any type) is be thrown during evaluation of the expression.
	SECTION("Id class exceptions")
	{
		REQUIRE_THROWS_AS(Id("2130412124241", "Identity Card"), InvalidIdNr);
		REQUIRE_THROWS_AS(Id("0412124.241", "Identity Card"), InvalidIdNr);
		REQUIRE_THROWS_AS(Id("21304124241", "Identitty Card"), InvalidIdType);
		REQUIRE_THROWS_AS(Id("21304124241", "Pass3port"), InvalidIdType);
	}
	SECTION("changing Id type and personal nr")
	{
		Id id("21304124241", "Passport");
		id.changePersonalNr("01234123124");
		REQUIRE(id.getPersonalNr() == "01234123124");
		id.changeType("Driver's License");
		REQUIRE(id.getType() == "Driver's License");
		REQUIRE_THROWS_AS(id.changePersonalNr("2130412124241"), InvalidIdNr);
		REQUIRE_THROWS_AS(id.changeType("pussport"), InvalidIdType);
	}
}

TEST_CASE("Client class")
{
	SECTION("Client Constructor")
	{
		Client cl("PePe  ", "PEpegus ", "Passport", "21304124241", 123421, "2412");
		REQUIRE(cl.getFirstName() == "Pepe");
		REQUIRE(cl.getLastName() == "Pepegus");
		REQUIRE(cl.getIdType() == "Passport");
		REQUIRE(cl.getIdNr() == "21304124241");
		REQUIRE(cl.getClientCode() == 123421);
		REQUIRE(cl.getPIN() == "2412");
		REQUIRE(cl.getProducts().size() == 0);
	}
	SECTION("checkIfPINValid and checkIfClientCodeValid")
	{
		Client cl("JoHn  ", "Bree", "Passport", "21304124241", 123421, "2412");
		REQUIRE(cl.checkIfPINValid("213") == false);
		REQUIRE(cl.checkIfPINValid("2132") == true);
		REQUIRE(cl.checkIfClientCodeValid(123421) == true);
		REQUIRE(cl.checkIfClientCodeValid(123421213) == false);
	}
	SECTION("comparePIN() and compareClientCode()")
	{
		Client cl("JoHn  ", "Bree", "Passport", "21304124241", 123421, "2412");
		REQUIRE(cl.comparePIN("2412") == true);
		REQUIRE(cl.comparePIN("241") == false);
		REQUIRE(cl.comparePIN("3214") == false);
		REQUIRE(cl.compareClientCode(123421) == true);
		REQUIRE(cl.compareClientCode(312424) == false);
		REQUIRE(cl.compareClientCode(44422145) == false);
	}
	SECTION("Changing parameters")
	{
		Client cl("JoHn  ", "Bree", "Passport", "21304124241", 123421, "2412");
		REQUIRE_THROWS_AS(cl.changeClientCode(1232314213), InvalidClientCode);
		cl.changeClientCode(123213);
		REQUIRE(cl.getClientCode() == 123213);
	}
	SECTION("Modifying products")
	{
		Client cl("JoHn  ", "Bree", "Passport", "21304124241", 123421, "2412");
		cl.addProduct(Product("Credit Card"));
		REQUIRE(cl.getProducts()[0].getName() == "Credit Card");
		REQUIRE_THROWS_AS(cl.addProduct(Product("Credit Card")), DuplicateProduct);
		REQUIRE_THROWS_AS(cl.removeProduct(Product("credit")), ProductNotFound);
		cl.addProduct(Product("Debit Card"));
		REQUIRE(cl.getProducts().size() == 2);
		cl.removeProduct(Product("Credit Card"));
		REQUIRE(cl.getProducts().size() == 1);
		cl.clearProducts();
		REQUIRE(cl.getProducts().size() == 0);
	}
}

TEST_CASE("Counter class")
{
	Counter c1(2311, Employee("John", "Jackson", 2342));
	Counter c2(1221, Employee ("Jonathan", "Jackson", 2323));
	Employee e3("Joeffrey", "Jackson", 3122);

	//SECTION("Counter class Constructor")
	//{
		REQUIRE(c1.getNr() == 2311);
		REQUIRE(c1.getQueue().size() == 0);
		REQUIRE_THROWS_AS(Counter(342, e3), InvalidCounterNr);
		REQUIRE_THROWS_AS(Counter(10000, e3), InvalidCounterNr);
		REQUIRE_THROWS_AS(Counter(2311, e3), DuplicateCounterNr);
	//}
	//SECTION("Change counter nr")
	//{
		c1.changeCounterNr(1231);
		REQUIRE(c1.getNr() == 1231);
		REQUIRE_THROWS_AS(c1.changeCounterNr(12312), InvalidCounterNr);
		REQUIRE_THROWS_AS(c1.changeCounterNr(9), InvalidCounterNr);
		REQUIRE_THROWS_AS(c2.changeCounterNr(1231), DuplicateCounterNr);
	//}
	//SECTION("Queue")
	//{
		c1.newClient(Client("JoHn  ", "Bree", "Passport", "54404124241", 123421, "1412"));
		c1.newClient(Client("PePe  ", "PEpegus ", "Passport", "21304214241", 763421, "2212"));
		REQUIRE(c1.getQueue().front().getLastName() == "Bree");
		REQUIRE(c1.getQueue().back().getLastName() == "Pepegus");
		REQUIRE(c1.getQueue().size() == 2);
		c1.clientLeftAfterService();
		REQUIRE(c1.getQueue().size() == 1);
		c1.clearQueue();
		REQUIRE(c1.getQueue().size() == 0);
		c1.newClient(Client("PePe  ", "PEpegus ", "Passport", "21304214241", 763421, "2212"));
		REQUIRE_THROWS_AS(c1.clientLeft(Client("JoHn  ", "Bree", "Passport", "54404124241", 121421, "1412")), ClientNotFound);
		c1.clientLeft(Client("PePe  ", "PEpegus ", "Passport", "21304214241", 763421, "2212"));
		REQUIRE(c1.getQueue().size() == 0);
	//}
	//SECTION("Employee")
	//{
		REQUIRE(c1.getEmployee().getName().getLastName() == "Jackson");
		c1.assignEmployee(Employee("Jackson", "Pollock", 2312));
		REQUIRE(c1.getEmployee().getName().getLastName() == "Pollock");
		REQUIRE_THROWS_AS(c2.assignEmployee(Employee("Jackson", "Pollock", 2312)), EmployeeAlreadyAssigned);
	//}
}
