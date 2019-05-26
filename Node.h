#include "Object.h"
#include "Actor.h"
using namespace std;
#include <string>
#pragma once
class Node : public Object 
{
private:
	Object *theItem;
	Node* link;
public:
	Node(Object *initItem, Node *initLink);
	void print();
	int getActorInfor(string fName,string lName, string movieName, int movieYear);
	bool getObjectType();
};
