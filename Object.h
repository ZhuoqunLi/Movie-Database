#pragma once
using namespace std;
#include <string>
class Object 
{
public:
	virtual ~Object() = 0;
	virtual void print() = 0;
	virtual int getActorInfor(string fName,string lName, string movieName, int movieYear)=0;
};
