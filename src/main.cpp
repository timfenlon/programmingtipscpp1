/*! \file */ 
/*
 * @file main.cpp
 * @author Copyright (C) 2016 by Tim Fenlon
 * @date 16 November 2016
 * @brief Description : LinkedList in C++
 ============================================================================
 */
#include <iostream>
#include <cstring>
#include <string>

#include "logging.hpp"

#include "LinkedListCpp.hpp"

using namespace std;
using namespace linked_list_cpp;

 /**
 * @brief prints out a menu for our program
 *
 * @param  const char* title, must be null terminated at end of char array
 * @param  uint32_t menuVersion, number of version for linked list program
 *
 * @return void no return value
 */
void printMenu(const char* title, uint32_t menuVersion, shared_ptr<CLinkedList>& theList)
{
	cout << "Menu Title " << title << " version " << menuVersion << endl;
	cout << "We have created" << theList->getNumNodes() << " nodes" << endl;
	cout << "1. Insert a certain number of randomly generated List Nodes" << endl;
	cout << "2. Print LinkedList Nodes" << endl;
	cout << "3. Recursive Print LinkedList Nodes" << endl;
	cout << "4. Delete All Linked List Nodes" << endl;
	cout << "5. Recursive Delete All Linked List Nodes" << endl;
	cout << "6. or q or Q will Quit Program" << endl;
	cout << ">";
}

/**
* @brief prints out a help menu for our program menu
*
* @return void no return value
*/
void printMenuHelp()
{
	cout << "Invalid Selection" << endl;
	cout << "1. Insert Bunch of Random Linked List Nodes" << endl;
	cout << "2. Print LinkedList Nodes" << endl;
	cout << "3. Recursive Print LinkedList Nodes" << endl;
	cout << "4. Delete All Linked List Nodes" << endl;
	cout << "5. Recursive Delete All Linked List Nodes" << endl;
	cout << "6. or q or Q will Quit Program" << endl;
}

/**
* @brief prints out a help menu for our program
*
* @return void no return value
*/
void printHelp()
{
	printf("Invalid Parameter Values! optional[-v number] [-m \"Menu Title\"]\n");
	printf("You can include -v for version number and -menu for menu title\n");
	printf("Version number is '-v' followed by integer number of version ex, -v 1\n");
	printf("Menu Title is '-menu' followed by character array of Title ex, -menu \"Linked List\"\n");
}

/**
 * @brief main() entry point into console program
 *
 * @param  int argc  number of arguments sent to the progam
 * @param  char *argv[] a array cooresponding to arc each array is a parameter
 * @param  argv[0] number of elements
 * @param  argv[1] '-v', argv[2] is integer value of version number for menu
 * @param  argv[3] '-menu', argv[4] is char array indicating name of menu must be less than 256 chars
 *
 * @return int if success return value is 0
 */
int main(int argc, char *argv[])
{
	uint32_t exitProgram = 0;//false

	char menuTitle[256];
	memset(menuTitle, '\0', CLinkedList::MAX_TITLE_LENGTH);

	char menuInput[256];
	memset(menuInput, '\0', CLinkedList::MAX_INPUT_LENGTH);

	/*Loop counter*/
	size_t i = 0;
	uint32_t menuVersion = 0;

	/* prints Hello Linked Lists */
	print_hello_linked_list();

	printf("There are %d arguments\n\n", argc);
	/*
	* Parse Command Line
	*/
	for (i = 1; i < argc; i++) {
		printf("argv[%zu] = %s\n", i, argv[i]);
		if (argv[i][0] == '-') {
			if (argv[i][1] == 'v')
			{
				if (argc >(i + 1)) {
					menuVersion = atoi(argv[++i]);
					continue;
				}
				else {
					printHelp();
					exitProgram = 1;//true
					break;
				}
			}
			else if (argv[i][1] == 'm')
			{
				//NOTE: -m or -menu are okay values
				if (argc > (i + 1)) {
					i++;
					memcpy(menuTitle, argv[i], ((strlen(argv[i]) < CLinkedList::MAX_TITLE_LENGTH) ? strlen(argv[i]) : CLinkedList::MAX_TITLE_LENGTH));
					continue;
				}
				else {
					printHelp();
					exitProgram = 1;//true
					break;
				}
			}
			else {
				printHelp();
				exitProgram = 1;//true
				break;
			}
		}
	}

	if (exitProgram)
	{
		return -1;
	}

	bool loopMenu = true;
	//Create our Linked List Object
	shared_ptr<CLinkedList> myCLinkedList = CLinkedList::getSingleton();

	while (loopMenu)
	{
		int retVal = 0;/**< evaluates function return values >= 1 success or <= 0 failed*/

		printMenu(menuTitle, menuVersion, myCLinkedList);

		string choice;
		getline(std::cin, choice);
		if ((choice[0] == 'Q') || (choice[0] == 'q'))
		{
			loopMenu = false;
			cout << "Quit Pressed...exited" << endl;
			continue;
		}
		int num_choice = atoi(choice.c_str());
		switch (num_choice)
		{
		case 1:
		{
			retVal = myCLinkedList->createNumRandomNodes(myCLinkedList);
			if (retVal <= 0)
			{
				cout << "An error occurred calling createNumRandomNodes()" << endl;
				printMenuHelp();
				continue;
			}
			break;
		}
		case 2:
		{
			retVal = myCLinkedList->printAllLinkedListNodes(myCLinkedList);
			if (retVal <= 0)
			{
				printf("An error occurred calling printAllLinkedListNodes()\n");
			}
			break;
		}
		case 3:
		{
			retVal = myCLinkedList->printAllLinkedListNodesRecursive(myCLinkedList);
			if (retVal <= 0)
			{
				printf("An error occurred calling printAllLinkedListNodesRecursive()\n");
			}
			break;
		}
		case 4:
		{
			retVal = myCLinkedList->deleteAllLinkedListNodes(myCLinkedList);
			if (retVal <= 0)
			{
				printf("An error occurred calling deleteAllLinkedListNodes()\n");
			}
			break;
		}
		case 5:
		{
			retVal = myCLinkedList->deleteAllLinkedListNodesRecursive(myCLinkedList);
			if (retVal <= 0)
			{
				printf("An error occurred calling deleteAllLinkedListNodesRecursive()\n");
			}
			break;
		}
		case 6:
		{
			loopMenu = false;
			break;
		}
		default:
		{
			cout << "Unrecognized Command: enter number 1, 2, 3 ..." << endl;
		}
		break;
		}
	}//end while
	return 0;
}
