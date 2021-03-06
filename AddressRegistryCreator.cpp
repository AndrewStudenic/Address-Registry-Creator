﻿// @author Andrew Studenic

// @file AddressRegistryCreator.cpp

// @version 2019-04-18

// @brief This program demonstrates the mastery of linked lists, using them
// to create a working address book. It collects information from the user
// and stores it into a linked list, which it can add to, delete from, 
// print to the console, and output to a text file.

// @note Time to write: 4 hours
// Time to test: 1 hour 
// Time to debug: 1 hour

#include <iostream> // for cin/cout
#include <string> // for use of strings
#include <fstream> // for file output
#include "addressType.h" // imports for the classes
#include "addressBook.h"

using namespace std;

struct addressBookIterator // node structure for the linked list
{
	addressBook entry; // holds addressBook info
	addressBookIterator *link; // hold pointer link value 
};

// Prototypes
int optionsScreen();
bool goAgain(string);
void createList(addressBookIterator* &fname, addressBookIterator* &Lname);
void listOutput(addressBookIterator* list);
void deleteEntry(addressBookIterator* &fname, addressBookIterator* &lname);
void fileOutput(addressBookIterator* list);

int main() // Begin main
{
	addressBookIterator *first = NULL; // instantiates the first node of the linked list
	addressBookIterator *last = NULL; // instantiates the last node of the linked list


	int optionNumber = 0; // integer that stores the value for choosing an 
						  // option on from the menu
	bool goAgainChoice = false; // boolean that stores the value that decides
								// if the user wishes to perform another action

	while (!goAgainChoice) // while loop goes until the user decides to quit 
	{
		optionNumber = optionsScreen(); // function calls the options screen, 
										// and stores the returned integer

		switch (optionNumber) // switch statement decides which option to 
		{                     // run based on the user decision 
		case 1:
			createList(first, last); // case 1 calls the createList function
									 // that correlates with creation of an 
									 // addressBook linked list
			break;
		case 2:
			deleteEntry(first, last); // case 2 calls the deleteEntry function
						   // that correlates with deletion of an entry.
			break;
		case 3:
			listOutput(first); // case 3 calls the listOutput function that
						   // correlates with output of all entries.
			break;
		case 4:
			fileOutput(first); // case 4 calls the optionFour function that
						   // correlates with output of all entries.
			break;
		}

		goAgainChoice =
			goAgain("Would you like to choose another option? (y/n): ");
		// function call for the goAgain function,
		// which asks the user if they would like
		// to go again, and stores it in a boolean
	}

	return 0; // end main
}

int optionsScreen() // Begin optionsScreen 
{
	string option; // variable to hold the user response from the menu 
	bool validOption = false; // boolean that will help with validation of the
							  // string information

	cout << "           Choose an option            " << endl; // the menu
	cout << "---------------------------------------" << endl; // output
	cout << "1. Add Address Book entries" << endl;
	cout << "2. Delete an entry" << endl;
	cout << "3. Print the Address Book" << endl;
	cout << "4. Output the Address Book to a file" << endl;
	cout << "Please enter your option (1-4): " << endl;

	cin >> option; // string entered by user

	while (!validOption) // while boolean is false
	{
		if (option == "1" || option == "2" || option == "3" || option == "4")
		{
			validOption = true;// if 1-4, the boolean is set to true			
		}
		else
		{
			cout << "Sorry, that is an invalid entry." << endl;
			cout << endl; // if anything but 1-4, prompted to enter again
			cout << "Please enter your option (1-4): " << endl;
			cout << endl;
			cin >> option;
		}
	}

	return stoi(option); // converts the string to an integer value and returns 
}

bool goAgain(string message) // Begin goAgain 
{
	string choice; // string that holds the user input
	bool choiceBool = false; // boolean that holds the converted string info

	cout << message << endl;
	cout << endl;
	cin >> choice; // user enters input

	if (choice == "y" || choice == "yes" || choice == "Y" ||
		choice == "Yes" || choice == "YES") // if a variation of 'y', boolean
						    // set accordingly
	{
		choiceBool = false;
	}
	else
	{
		choiceBool = true;
	}

	return choiceBool; // boolean is returned
} // end goAgain

void createList(addressBookIterator* &fname, addressBookIterator* &lname) // begin createList
{
	bool goAgainChoice = false; // Holds user choice to go again

	string tempFName = ""; // String values that temporarily hold the info
	string tempLName = ""; // for user input that will be inserted into the
	string tempPhoneNum = ""; // nodes
	string tempBDay = "";
	string tempAddress = "";
	string tempCity = "";
	string tempState = "";
	string tempZipCode = "";

	addressType tempAddy = addressType(tempAddress, tempCity, tempState,
		tempZipCode); // temporary addressType object for new node creation

	addressBook tempBook = addressBook(tempAddy, tempFName, tempLName,
		tempPhoneNum, tempBDay); // temporary addressBook obj for node creation

	addressBookIterator *newNode; // temporary node to hold new information for insertion
	cin.ignore(); // clears the buffer for getline usage

	while (!goAgainChoice) // While loop performs as long as user wishes
	{
		newNode = new addressBookIterator;//creates the new node
		// These collect the new node information
		cout << "Please enter the First Name for this entry: " << endl;
		getline(cin, tempFName);
		cout << endl;

		cout << "Please enter the Last Name for this entry:" << endl;
		getline(cin, tempLName);
		cout << endl;

		cout << "Please enter the Street Address for this entry:" << endl;
		getline(cin, tempAddress);
		cout << endl;

		cout << "Please enter the City for this entry:" << endl;
		getline(cin, tempCity);
		cout << endl;

		cout << "Please enter the State for this entry:" << endl;
		getline(cin, tempState);
		cout << endl;

		cout << "Please enter the Zip Code for this entry:" << endl;
		getline(cin, tempZipCode);
		cout << endl;

		cout << "Please enter the Phone Number for this entry:" << endl;
		getline(cin, tempPhoneNum);
		cout << endl;

		cout << "Please enter the Birth Date for this entry:" << endl;
		getline(cin, tempBDay);
		cout << endl;
		// these add the temporary values into the temporary objects
		addressType tempAddy = addressType(tempAddress, tempCity, tempState,
			tempZipCode);

		addressBook tempBook = addressBook(tempAddy, tempFName, tempLName,
			tempPhoneNum, tempBDay);

		newNode->entry = tempBook; // sets the info into the node
		newNode->link = NULL; // sets the node link to NULL

		if (fname == NULL) // if catches if it is the first item in the list
		{
			fname = newNode; // sets it to both first and last item
			lname = newNode;
		}
		else // else catches if not the first item in the list
		{
			lname->link = newNode; // sets the info to the next item
			lname = newNode;
		}
		goAgainChoice = goAgain("Would you like to add another entry? (y/n)");
		// goAgain Function collects users desire to go again
		cin.ignore(); // fixes the input for getline
	}
} // end createList

void listOutput(addressBookIterator* list) // begin listOutput
{
	addressBookIterator *current; // creates a current node
	current = list; // sets it to the first entry

	while (current != NULL) // while the item is not the last
	{
		current->entry.printAddress(); // prints info from entry
		current = current->link; // sets to next link
	}
} // end listOutput

void deleteEntry(addressBookIterator* &fname, addressBookIterator*&lname) // begin deleteEntry
{
	cin.ignore(); // clears buffer for getline usage

	bool found = false; // boolean for checking if entry is found
	bool confirm = false; // boolean for confirming deletion

	string searchFName = ""; // string to hold first name search 
	string searchLName = ""; // string to hold last name search

	addressBookIterator *current; // the current item iterating
	addressBookIterator *trailCurrent = NULL; // the one before that

	if (fname == NULL) // if it is empty list, this is caught
	{
		cout << "The list is empty, delete operation was unsuccessful."
			<< endl;
		cout << endl;
	}
	else // if there is a list
	{
		cout << "Please enter the first name of the entry you wish to delete: "
			<< endl;
		getline(cin, searchFName); // collects the name to search for
		cout << endl;

		cout << "Please enter the last name of the entry you wish to delete: "
			<< endl;
		getline(cin, searchLName);
		cout << endl;

		current = fname; // sets current item in list to the first item

		while (current != NULL && !found) // while loop iter until found
			if (current->entry.getFirstName() == searchFName &&
				current->entry.getLastName() == searchLName)
			{
				found = true; // set to true if first and last name found
			}
			else
			{
				trailCurrent = current; // if not found, sets trail to current
				current = current->link; // sets current to next
			}

		if (found) // if the item is found
		{
			current->entry.printAddress(); // prints the information
			cout << "The entry was found." << endl;
			cout << endl;
			confirm = goAgain("Do you wish to delete this entry? (y/n): ");
			if (!confirm) // confirms desire to delete
			{
				if (fname == current) // if it is the first item in the list
				{
					fname = fname->link; //first is set to the next item
					if (fname == NULL)
					{
						lname = NULL;
					}
					delete current; // deletes current
				}
				else // if it is not the first item
				{
					trailCurrent->link = current->link; // trail is set to the
					// link
					if (current == lname) // if it is the last item
					{
						lname = trailCurrent; // set to the trail
					}
					delete current; // deletes current
				}
				cout << "The Item has been deleted." << endl;
				cout << endl;
			}
			else // confirms no deletion
			{
				cout << "OK, the item will not be deleted." << endl;
				cout << endl;
			}
		}
		else // message for item not being found
		{
			cout << "Sorry, that entry was not found, please try again."
				<< endl;
			cout << endl;
		}
		cin.ignore(); // clears buffer
	}
} // end deleteEntry
void fileOutput(addressBookIterator* list) // begin fileOutput
{
	ofstream outData; // creates ofstream variable
	string fileName = ""; // string to hold filename

	addressBookIterator *current; // creates the node to perform operations
	current = list; // sets it to first item in the list

	cout << "Please enter the name of the file you wish to export to." << endl;
	cout << "(Example: yourFile.txt): " << endl;
	cout << endl;  // prompt

	cin >> fileName; // collects filename from user

	outData.open(fileName); // opens the file

	while (current != NULL) // ehile not NULL
	{
		addressType tempAddy = current->entry.getFullAddress(); // creates a 
		// temp addresstype for output
		// Outputs each item using getters
		outData << "First Name: " << current->entry.getFirstName() << endl;
		outData << "Last Name: " << current->entry.getLastName() << endl;
		outData << "Address: " << tempAddy.getAddress() << endl;
		outData << "City: " << tempAddy.getCity() << endl;
		outData << "State: " << tempAddy.getState() << endl;
		outData << "Zip Code: " << tempAddy.getZipCode() << endl;
		outData << "Phone Number: " << current->entry.getPhoneNumber() << endl;
		outData << "Date of Birth: " << current->entry.getBirthDate() << endl;
		outData << endl;

		current = current->link; // iterates to next link
	}
	outData.close(); // closes the file

	cout << "File Output Complete." << endl;
	cout << endl;
} // end fileOutput
