// CLASS: Node
//
// Author: Zhuoqun Li,7740173
//
// REMARKS: "convert" each Object(Actor or Movie)
//			as Node, and connect the next Object
//-----------------------------------------

#include <iostream> 
#include "Object.h"
#include "Node.h"
using namespace std;

//------------------------------------------------------
// Node
//
// PURPOSE:		constructor of Node class
// PARAMETERS:	Object that we need to stored, and the pointer
//				to next Node
// Returns:		None
//------------------------------------------------------
Node::Node(Object *initItem, Node *initLink)
{
	theItem = initItem; 
	link = initLink;//Node's next pointer
}

//------------------------------------------------------
// getObjectType
//
// PURPOSE:		test the current Object is Actor or Movie
// PARAMETERS:	None
// Returns:		return true if it's Actor, return false if
//				it's anything else other than Actor
//------------------------------------------------------
bool Node::getObjectType()
{
	Actor *test = dynamic_cast<Actor*>(theItem);
	bool isActorType;

	if (test == NULL)
	{
		isActorType = false;
	}
	else
	{
		isActorType = true;
	}

	return isActorType;
}


//------------------------------------------------------
// print
//
// PURPOSE:		called each Object print method
// PARAMETERS:	None
// Returns:		None
//------------------------------------------------------
void Node::print()
{
	theItem->print();

	if (link != NULL) {
		link->print();//recursion
	}
		
}

//------------------------------------------------------
// getActorInfor
//
// PURPOSE:		get the information of the actor we want to find
// PARAMETERS:	family name and last name of the actor we want to
//				find, Name of the Movie he played and year of the
//				movie released
// Returns:		return the information of actor's gender and birth 
//				year
//------------------------------------------------------
int Node::getActorInfor(string fName,string lName, string movieName, int movieYear)
{
	Object *tempObject = theItem;
	int additionInfor;
	static int answer=-1;


	additionInfor =tempObject->getActorInfor(fName,lName,movieName,movieYear);//get the return value from getActorInfor() method
	if (((additionInfor>1000 || additionInfor<-1000)))//if value is bigger than 1000 or smaller than 1000, it means we get the useful return value
	{
		answer = additionInfor;
	}
	if (link != NULL)
	{
		link->getActorInfor(fName, lName,movieName,movieYear);
	}
	return answer;
}