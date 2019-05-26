// CLASS: LinkedList
//
// Author: Zhuoqun Li,7740173
//
// REMARKS: Implement a normal linkedlist class
//			to connect each nodes
//-----------------------------------------

#include <iostream> 
#include "LinkedList.h"
using namespace std;

//------------------------------------------------------
// print
//
// PURPOSE:		ask each node to do the print method
// PARAMETERS:	None
// Returns:		None
//------------------------------------------------------
void LinkedList::print() 
{
	if (top!= NULL)
	{
		if (top->getObjectType() == true)//get the linkedlist's Node type, is actor or movie
		{
			cout << endl << "Female acotrs:" << endl;
				top->print();//this time will only print female actors
			cout << endl << "Male acotrs:" << endl;
				top->print();//this time will only print male actors
		}
		else
		{
			cout << endl << "Movies:" << endl;
			top->print();
		}
	}

}

//------------------------------------------------------
// insert
//
// PURPOSE:		insert Object to the current linkedlist
// PARAMETERS:	The Object we want to insert
// Returns:		None
//------------------------------------------------------
void LinkedList::insert(Object *newItem) 
{
	top = new Node(newItem, top);
}

//------------------------------------------------------
// LinkedList
//
// PURPOSE:		constructor of LinkedList class
// PARAMETERS:	None
// Returns:		None
//------------------------------------------------------
LinkedList::LinkedList()
{
	top = NULL; 
}

//------------------------------------------------------
// findActor
//
// PURPOSE:		ask Actor class to find the suitable information
// PARAMETERS:	family name and last name of the actor we want to
//				find, Name of the Movie he played and year of the
//				movie released
// Returns:		return the information of actor's gender and birth 
//				year
//------------------------------------------------------
int LinkedList::findActor(string fName, string lName,string movieName,int movieYear)
{
	int result=0;

	if (top != NULL)
	{
		result = (top->getActorInfor(fName, lName,movieName,movieYear));
	}
		
	return result;

}
