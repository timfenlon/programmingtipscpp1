/**
 * @file logging.c
 * @author Copyright (C) 2016 by Tim Fenlon
 * @date 8 November 2016
 * @brief logs different messages to standard output using printf
 */

#include <iostream>
#include "logging.hpp"

using namespace std;

namespace linked_list_cpp
{

	/**
	 * @brief logs hello world using cout
	 */
	void print_hello_linked_list()
	{
		cout << "Hello Linked List C++!" << endl;
	}
}