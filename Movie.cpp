// CLASS: Movie
//
// Author: Zhuoqun Li,7740173
//
// REMARKS: Store Movie informations, and this
//			class can print the information of
//			the movie
//-----------------------------------------

#include "Movie.h"
#include <string>
using namespace std;

//------------------------------------------------------
// Movie	
//
// PURPOSE:		constructor of Movie class
// PARAMETERS:	movie's name, released year of the movie
//				actor's name who played in this movie, and
//				gender and birth of the actor
//				gender of the actor
// Returns:		None
//------------------------------------------------------
Movie::Movie(string title, int year, string familyname, string givenName,int birth,char gender)
{
	this->title = title;
	this->year = year;
	this->familyname = familyname;
	this->givenName = givenName;
	this->birth = birth;
	this->gender = gender;

}

//------------------------------------------------------
// Movie	
//
// PURPOSE:		constructor of Movie class
// PARAMETERS:	None
// Returns:		None
//------------------------------------------------------
Movie::Movie()
{
	title = "";
	year = -1;
	familyname = "";
	givenName = "";
}

//------------------------------------------------------
// print	
//
// PURPOSE:		print information of current movie
// PARAMETERS:	None
// Returns:		None
//------------------------------------------------------
void Movie::print() {
	if (birth != 0 || gender != ' ')//if we know who played in the movie, then we print it follow this form
		cout << title << " (" << year << "£© starring " << givenName << " " << familyname << " (" << birth << ") " << gender  << endl;
	else//if we don't know who played in the movie, then we print it follow this form
		cout << title << " (" << year << "£©" << endl;

}

//------------------------------------------------------
// getActorInfor	
//
// PURPOSE:		nothing,just for abstract class
// PARAMETERS:	family name and given name of the Actor, 
//				the movie the actor played and year of the 
//				movie released
// Returns:		result -1 all the time
//------------------------------------------------------
int Movie::getActorInfor(string familyname, string givenName, string movieName, int movieYear)
{
	int result=-1;

	return result;
}