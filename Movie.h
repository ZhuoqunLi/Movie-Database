#include <iostream> 
#include "Object.h"
#include <string>
using namespace std;

class Movie : public Object 
{
private:
	string title;
	int year;
	string familyname;
	string givenName;
	int birth;
	char gender;
public:
	void print();
	Movie(string title, int year, string familyname, string givenName,int birth,char gender);
	Movie();
	int getActorInfor(string familyname, string givenName, string movieName, int movieYear);
}; 
#pragma once
