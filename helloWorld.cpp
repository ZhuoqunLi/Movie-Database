/*
* GenList.cpp
* COMP 2150 Object Orientation
*
* Generic Linked List
*
* This group of classes implements a generic linked list, making use
* of abstract classes and methods.
*/

#include <iostream>
using namespace std;


//*****************************************************************
// interface section
//*****************************************************************

//*****************************************************************
//An abstract class defining the group of things that could appear
//as data in a list.  Remember, you could have shared code here in
//the form of concrete methods as well!
//*****************************************************************
class ListItem {
public:
	//pure virtual print() - print() will be used polymorphically to
	//print any type of list item! note the fact that it's pure virtual
	//makes this an abstract class too!
	virtual void print() = 0;
	// because this class uses polymorphism, C++ will recognize and
	// offer a warning that the destructor for this class should be
	// polymorphic too - I've written one just to take care of that
	// warning, we'll be talking about destructors later...
	virtual ~ListItem();
};


//*****************************************************************
//A node for a singly linked list:  Holds any subclass of ListItem.
//*****************************************************************
class Node {
private:
	ListItem *theItem;
	Node* link;
public:
	Node(ListItem *initItem, Node *initLink);
	void print();
};

//*****************************************************************
//Integer data value for a list item - just defines the int as data
//and defines a print suitable for integers.
//*****************************************************************
class IntAtom : public ListItem {
private:
	int data;
public:
	void print();
	IntAtom(int i);
	IntAtom();
};

//*****************************************************************
//Char data value for a list item - just defines the char as data
//and defines a print suitable for floating point numbers.
//*****************************************************************
class CharAtom : public ListItem {
private:
	char data;
public:
	void print();
	CharAtom(char c);
	CharAtom();
};

//*****************************************************************
//LIST data value for a list item - just defines the list as data,
//includes a basic insert, and customizes print so that we're
//printing an entire list off.
//*****************************************************************
class GenericList : public ListItem {
private:
	Node *top;
public:
	GenericList();
	void print();
	void insert(ListItem *newItem);
};

//*****************************************************************
// implementation section
//*****************************************************************

//*****************************************************************
//ListItem's methods
//*****************************************************************

//technically this is just defining a null body for the virtual
//destructor, but even a null body is technically executable code, so
//it shouldn't be in your class definition unless for some reason
//you're doing all your methods inline.

ListItem::~ListItem() {}

//*****************************************************************
//IntAtom's methods
//*****************************************************************

//constructors
IntAtom::IntAtom(int i) { data = i; }
IntAtom::IntAtom() { data = 0; }

//basic print, nothing much to see here, move along...
void IntAtom::print() { cout << data; }


//*****************************************************************
//CharAtom's methods
//*****************************************************************

//basic constructors
CharAtom::CharAtom(char c) { data = c; }
CharAtom::CharAtom() { data = ' '; }
//basic print, just add asterisks around the char 
//so you can see where it would be if it's unprintable
void CharAtom::print() {
	cout << "*" << data << "*";
}


//*****************************************************************
//GenericList's methods
//*****************************************************************

//null constructor
GenericList::GenericList() { top = NULL; }

//print for a list: use brackets to denote start,end of list.
void GenericList::print() {
	cout << "(";
	if (top != NULL)
		top->print();
	cout << ")";
}

//basic insert at front - note because of the way we set up node's
//constructor (to allow the pointer-to-next be supplied as an
//argument) we can just do the insert using that!
void GenericList::insert(ListItem *newItem) {
	top = new Node(newItem, top);
}

//*****************************************************************
//Node's methods
//*****************************************************************

//constructor
Node::Node(ListItem *initItem, Node *initLink)
{
	theItem = initItem; link = initLink;
}

//method print just passes print on to the data item, and to the
//next node if this isn't the end of the list...
void Node::print() {
	theItem->print();
	if (link != NULL) {
		cout << " ";
		link->print();
	}
}

//*****************************************************************
//Main method to test all this out!
//*****************************************************************
int main(void) {
	GenericList list1, list2; //two stack-based objects!
							  //we insert pointer-based objects in the lists...
	list1.insert(new IntAtom(34));
	list1.insert(new CharAtom('A'));
	cout << "List 1 is:" << " ";
	list1.print();
	cout << endl; //endl starts a new line in the stream
	list2.insert(new IntAtom(88));
	list2.insert(&list1); //insert list1 as data into list2 - requires a pointer-to-listitem
	list2.insert(new CharAtom(' '));
	cout << "List 2 is:" << " ";
	list2.print();
	cout << endl;

	list1.insert(new IntAtom(99));
	cout << "List 1 is:" << " ";
	list1.print();
	cout << endl;
	cout << "List 2 is:" << " ";
	list2.print();
	cout << endl << "That's all folks!" << endl;
	return(1);
}// main