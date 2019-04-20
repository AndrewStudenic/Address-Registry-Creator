// @author Andrew Studenic

// @file addressBook.h

// @version 2019-04-18

// @brief This program contains the header file for the addressBook class, as 
// well as detailed pre and post condition documentation for each function.

// @note Time to write: .5 hours Time to test: .5 hour Time to debug: .5 hour

#pragma once
#include <string>
#include <iostream>
#include "addressType.h"

using namespace std;

class addressBook
{
public:
	void setFullAddress(addressType fAddress);
	/* Function to set the fullAddress according to the parameter.
	 * Postcondition: fullAddress = fAddress;
	 */
	void setFirstName(string fName);
	/* Function to set the firstName according to the parameter.
	 * Postcondition: firstName = fName;
	 */
	void setLastName(string lName);
	/* Function to set the lastName according to the parameter.
	 * Postcondition: lastName = lName;
	 */
	void setPhoneNumber(string phone);
	/* Function to set the phoneNumber according to the parameter.
	 * Postcondition: phoneNumber = phone;
	 */
	void setBirthDate(string bDay);
	/* Function to set the birthDate according to the parameter.
	 * Postcondition: birthDate = bDay;
	 */
	addressType getFullAddress() const;
	/* Function to return the fullAddress.
	 * Postcondition: the value of fullAddress is returned.
	 */
	string getFirstName() const;
	/* Function to return the firstName.
	 * Postcondition: the value of firstName is returned.
	 */
	string getLastName() const;
	/* Function to return the lastName.
	 * Postcondition: the value of lastName is returned.
	 */
	string getPhoneNumber() const;
	/* Function to return the phoneNumber.
	 * Postcondition: the value of phoneNumber is returned.
	 */
	string getBirthDate() const;
	/* Function to return the phoneNumber.
	 * Postcondition: the value of phoneNumber is returned.
	 */
	void printAddress() const;
	/* Function that outputs the entire address file nicely.
	 */
	addressBook();
	/* No-Arg Constructor
	 */
	addressBook(addressType fAddress, string fName = "",
		string lName = "", string phone = "", string bDay = "");
	/* Constructor
	 * Sets firstName, lastName, fullAddress, phoneNumber and birthdate
	 * according to the parameters.
	 * Postcondition: firstName = fname; lastName = lname; fullAddress =
	 * fAddress; phoneNumber = phone; birthDate = bDay;
	 */
private:
	addressType fullAddress;
	string firstName;
	string lastName;
	string phoneNumber;
	string birthDate;
};

