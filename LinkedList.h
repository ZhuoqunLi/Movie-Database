#include <iostream> 
#include "Object.h"
#include "Node.h"
using namespace std;

class LinkedList
{
private:
	Node *top;
public:
	LinkedList();
	void print();
	void insert(Object *newItem);
	int findActor(string fName, string lName,string movieName, int movieYear);
}; 
#pragma once
