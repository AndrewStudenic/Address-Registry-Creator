// @author Andrew Studenic

// @file addressBook.cpp

// @version 2019-04-18

// @brief This program contains the various functions required to make the 
// addressBook class work properly.

// @note Time to write: .5 hours Time to test: .5 hour Time to debug: .5 hour

#include "addressBook.h"
#include "addressType.h"
#include <string>
#include <iostream>

using namespace std;

//Mutator functions
void addressBook::setFullAddress(addressType fAddress)
{
	fullAddress = fAddress;
}
void addressBook::setFirstName(string fName)
{
	firstName = fName;
}

void addressBook::setLastName(string lName)
{
	lastName = lName;
}

void addressBook::setPhoneNumber(string phone)
{
	phoneNumber = phone;
}

void addressBook::setBirthDate(string bDay)
{
	birthDate = bDay;
}


//Accessor functions
addressType addressBook::getFullAddress() const
{
	return fullAddress;
}
string addressBook::getFirstName() const
{
	return firstName;
}

string addressBook::getLastName() const
{
	return lastName;
}

string addressBook::getPhoneNumber() const
{
	return phoneNumber;
}

string addressBook::getBirthDate() const
{
	return birthDate;
}


void addressBook::printAddress() const
{
	addressType tempAddressInfo;

	tempAddressInfo = getFullAddress();

	cout << "First Name: " << getFirstName() << endl;
	cout << "Last Name: " << getLastName() << endl;
	tempAddressInfo.printAddress();
	cout << "Phone Number: " << getPhoneNumber() << endl;
	cout << "Date of Birth: " << getBirthDate() << endl;
	cout << endl;
}
addressBook::addressBook()
{
	addressType tempAddressInfo = addressType();
	fullAddress = tempAddressInfo;
	firstName = " ";
	lastName = " ";
	phoneNumber = " ";
	birthDate = " ";

}
addressBook::addressBook(addressType fAddress, string fName,
	string lName, string phone, string bDay)
{
	fullAddress = fAddress;
	firstName = fName;
	lastName = lName;
	phoneNumber = phone;
	birthDate = bDay;
}
