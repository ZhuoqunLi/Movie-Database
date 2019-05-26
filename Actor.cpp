// CLASS: Actor
//
// Author: Zhuoqun Li,7740173
//
// REMARKS: Store Actor information, and it also
//			can print informations of the actor
//-----------------------------------------

#include <iostream> 
using namespace std;
#include <string>
#include "Actor.h"

//------------------------------------------------------
// Actor	
//
// PURPOSE:		constructor of Actor class
// PARAMETERS:	family name, given name, birthyear and
//				gender of the actor
// Returns:		None
//------------------------------------------------------
Actor::Actor(string familyname, string givenName, int birthYear, char gender) 
{ 
	this->familyname = familyname;
	this->givenName = givenName;
	this->birthYear = birthYear;
	this->gender = gender;
	this->movie = "";
	if (gender == 'F')
		this->priority = true;//because we want to print female actors first, so we set famle actor's priority to true, then it will only print female actors when the first time called
	if (gender == 'M')
		this->priority = false;//because we want to print male actors after print female actors, we set male actors' preiority to false in the beginning

}

//------------------------------------------------------
// Actor	
//
// PURPOSE:		constructor of Actor class
// PARAMETERS:	None
// Returns:		None
//------------------------------------------------------
Actor::Actor() 
{ 
	familyname = "";
	givenName = "";
	birthYear = -1;
	gender = -1;
}

//------------------------------------------------------
// print	
//
// PURPOSE:		print current actor's information
// PARAMETERS:	None
// Returns:		None
//------------------------------------------------------
void Actor::print() 
{
	string splitString[100];
	int count = 0;

	if (this->priority == true)
	{
		if (sizeof(movie) <= 1)
			cout << givenName << " " << familyname << " (" << birthYear << ")" << movie << endl;
		else
		{
			cout << givenName << " " << familyname << " (" << birthYear << ")" << endl;

			for (int i = 0; (size_t)i < movie.length(); i++)
			{
				if (movie[i] == '&')
					count++;
				else
					splitString[count] += movie[i];//split the string of movies' information
			}

			for (int j = 1; j <= count; j++)
			{
				cout << "     " << splitString[j] << endl;//print the movie one by one
			}
		}
		this->priority = false;//set actor's priority to false if it was true, because next time we need to print other part of actors
	}

	else if (this->priority == false)
	{
		this->priority = true;//set actor's priority to true, because next time we call this method, we will print this part of actors
	}

}

//------------------------------------------------------
// getActorInfor	
//
// PURPOSE:		get the information for the specific actor
// PARAMETERS:	family name and given name of the Actor, 
//				the movie the actor played and year of the 
//				movie released
// Returns:		If found the actor,return a integer with	
//				birthyear and gender information.  If didn't
//				find the actor, return -1
//------------------------------------------------------
int Actor::getActorInfor(string familyname, string givenName, string movieName, int movieYear)
{
	int bYear=-1;
	int year;
	int result=-1;

	if (familyname == this->familyname  && givenName == this->givenName)
	{
		bYear = birthYear;
		string tranYear;
		ostringstream countSteam;
		countSteam << movieYear;
		tranYear = countSteam.str();


		if (sizeof(this->movie) <= 1)
		{
			this->movie = movieName + "(" + tranYear + ")";
		}
		else
		{
			this->movie = this->movie + "&"+ movieName + "(" + tranYear + ")";//add movie information to the actors
		}

	}


	if (bYear != -1)
	{
		year = bYear;

		if (gender == 'F')
			result = ~(year - 1);//if it's a female actor,then return the negative number of the birth year of the actor
		if (gender == 'M')
			result = year;//if it's a male actor,then return the positive number of tje birth year of the actor
	}
	
	return result;
}
