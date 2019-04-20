// @author Andrew Studenic

// @file addressType.cpp

// @version 2019-04-18

// @brief This program contains the various functions required to make the 
// addressType class work properly.

// @note Time to write: .5 hours Time to test: .5 hour Time to debug: .5 hour

#include "addressType.h"
#include <string>
#include <iostream>

using namespace std;

// Mutator functions
void addressType::setAddress(string address)
{
	aAddress = address;
}

void addressType::setCity(string city)
{
	aCity = city;
}

void addressType::setState(string state)
{
	aState = state;
}

void addressType::setZipCode(string zipCode)
{
	aZipCode = zipCode;
}

//Accessor functions
string addressType::getAddress() const
{
	return aAddress;
}

string addressType::getCity() const
{
	return aCity;
}

string addressType::getState() const
{
	return aState;
}

string addressType::getZipCode() const
{
	return aZipCode;
}

// Output function
void addressType::printAddress() const
{
	cout << "Street Address: " << aAddress << endl;
	cout << "City: " << aCity << endl;
	cout << "State: " << aState << endl;
	cout << "Zip Code: " << aZipCode << endl;
}

// Constructor with parameters
addressType::addressType(string address, string city, string state,
	string zipCode)
{
	aAddress = address;
	aCity = city;
	aState = state;
	aZipCode = zipCode;
}