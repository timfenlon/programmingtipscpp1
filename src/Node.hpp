/**
* @file Node.hpp
* @author Copyright (C) 2016 by Tim Fenlon
* @date 16 November 2016
* @brief Header for linked list node, singly linked list
*/
#pragma once

#include <cstdint>
#include <memory>

using namespace std;

namespace linked_list_cpp
{

	/**
	* @brief Header for singly linked list CNode
	* @description mData and mNext singly linked list
	*/
	class CNode
	{
	public:
		CNode(void);
		~CNode(void);

		int mData;
		shared_ptr<CNode> mNext;
	};

}//linked_list_cpp