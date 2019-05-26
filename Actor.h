#include <iostream> 
#include "Object.h"
#include <string>
#include <sstream>
using namespace std;
#pragma once

class Actor : public Object 
{
private:
	string familyname;
	string givenName;
	int birthYear;
	char gender;
	string movie;
	bool priority;
public:
	void print();
	Actor(string familyname, string givenName, int birthYear, char gender);
	Actor();
	int getActorInfor(string familyname,string givenName, string movieName, int movieYear);
}; 

