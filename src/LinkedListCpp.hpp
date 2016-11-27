/**
* @file LinkedListCpp.cpp
* @author Copyright (C) 2016 by Tim Fenlon
* @date 16 November 2016
* @brief Implementation file for linked list node, singly linked list
*/
//Add pragma once so include is only read once by compiler
#pragma once

#include <cstdint>
#include <memory>
#include <iostream>

#include "Node.hpp"

using namespace std;

namespace linked_list_cpp
{
	/**
	* @brief Header for abstract interface class
	* @description creates a pure virtual function for abstract base class interface
	*/
	class ICListBaseInterface
	{
	public:
		virtual uint64_t getNumNodes() = 0;/**< pure virtual function */
	};

	/**
	* @brief Header for singly linked list CListBase
	* @description creates a base class for common CLinkedList operations
	*/
	class CListBase : public ICListBaseInterface
	{
	public:
		//Define some constants for char sizes
		static const int MAX_TITLE_LENGTH = 256;
		static const int MAX_INPUT_LENGTH = 256;

	public:
		CListBase(void);
		virtual ~CListBase(void);/**< ensures that derived classes destructor is called*/

		virtual uint64_t getNumNodes() {
			return mNumNodes;
		}

	private:
		shared_ptr<CNode> mHeadNode;
		shared_ptr<CNode> mTailNode;
		uint64_t     mNumNodes;
	};

	/**
	* @brief Header for singly linked list CLinkedList
	* @description creates derived class to hold Linked Lists head and tail plus tracks number of linked list CNodes
	*/
	class CLinkedList : public CListBase
	{
	public:
		//Define some constants for char sizes
		static const int MAX_TITLE_LENGTH = 256;
		const static int MAX_INPUT_LENGTH = 256;

		//Make a globally accessible singleton
		static shared_ptr<CLinkedList>& getSingleton();
		static shared_ptr<CLinkedList> mgCLinkedList;
	public:
		CLinkedList(void);
		~CLinkedList(void);

		/**
		* @brief Creates a specified number of nodes, filled with random values
		*
		* @param  shared_ptr<CLinkedList>& node_list, pointer to valid node list
		*
		* @return int returns >= 1 if success and <= 0 if a failure occurred
		*/
		int	createNumRandomNodes(shared_ptr<CLinkedList>& node_list);

		/**
		* @brief prints out all of the linked list nodes using a loop
		*
		* @param  shared_ptr<CLinkedList>& node_list, pointer to valid node list
		*
		* @return int returns >= 1 if success and <= 0 if a failure occurred
		*/
		int	printAllLinkedListNodes(shared_ptr<CLinkedList>& node_list);

		/**
		* @brief prints out all of the linked list nodes using a recursive loop
		*
		* @param  shared_ptr<CLinkedList>& node_list, pointer to valid node list
		*
		* @return int returns >= 1 if success and <= 0 if a failure occurred
		*/
		int	printAllLinkedListNodesRecursive(shared_ptr<CLinkedList>& node_list);

		/**
		* @brief deletes all of the linked list nodes using a recursive loop and frees allocated memory
		*
		* @param  shared_ptr<CLinkedList>& node_list, pointer to valid node list
		*
		* @return int returns >= 1 if success and <= 0 if a failure occurred
		*/
		int	deleteAllLinkedListNodes(shared_ptr<CLinkedList>& node_list);

		/**
		* @brief deletes all of the linked list nodes using a loop and frees allocated memory
		*
		* @param  shared_ptr<CLinkedList>& node_list, pointer to valid node list
		*
		* @return int returns >= 1 if success and <= 0 if a failure occurred
		*/
		int	deleteAllLinkedListNodesRecursive(shared_ptr<CLinkedList>& node_list);

	};

}//linked_list_cpp