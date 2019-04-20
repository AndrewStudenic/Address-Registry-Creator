// @author Andrew Studenic

// @file addressType.h

// @version 2019-04-18

// @brief This program contains the header file for the addressType class, as 
// well as detailed pre and post condition documentation for each function.

// @note Time to write: .5 hours Time to test: .5 hour Time to debug: .5 hour

#pragma once
#include <string>
#include <iostream>

using namespace std;

class addressType
{
public:
	void setAddress(string address);
	/* Function to set the address
	 * Postcondition: aAddress = address;
	 */
	void setCity(string city);
	/* Function to set the city
	 * Postcondition: aCity = city;
	 */
	void setState(string state);
	/* Function to set the state
	 * Postcondition: aState = state;
	 */
	void setZipCode(string zipCode);
	/* Function to set the zip code
	 * Postcondition: aZipCode = zipCode
	 */
	string getAddress() const;
	/* Function to return the address
	 * Postcondition: The value of aAddress is returned
	 */
	string getCity() const;
	/* Function to return the city
	 * Postcondition: The value of aCity is returned
	 */
	string getState() const;
	/* Function to return the state
	 * Postcondition: The value of aState is returned
	 */
	string getZipCode() const;
	/* Function to return ther zip code
	 * PostCondition: The value of aZipCode is returned
	 */
	void printAddress() const;
	/* Function to output the address
	 */

	addressType(string address = "None", string city = "None",
		string state = "None", string zipCode = "");
	/* Constructor to set the address
	 * The member variables aAddress, aCity, aState, aZipCode are set
	 * according to the parameters.
	 * Postcondition: aAddress = address; aCity = city; aState = state;
	 * aZipCode = zipCode;
	 * If no values are specified, the default values are used to initialize
	 * the member variables.
	 */
private:
	string aAddress;
	string aCity;
	string aState;
	string aZipCode;
};
