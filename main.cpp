//-----------------------------------------
// NAME		: Zhuoqun Li
// STUDENT NUMBER	: 7740173
// COURSE		: COMP 2150
// INSTRUCTOR	: Gabriel Faucher
// ASSIGNMENT	: assignment 2
// QUESTION	: question 1      
// 
// REMARKS: Sort the input file, and print
//			it with 3 parts: Movies, Female
//			actors and Male actors
//-----------------------------------------

#include <iostream> 
#include <fstream>
#include <sstream>
#include <stdio.h>
using namespace std;
#include <string>
#include "LinkedList.h"
#include "Movie.h"
#include "Actor.h"


//------------------------------------------------------
// readFile
//
// PURPOSE: read the input files, sorted it and print it
// PARAMETERS:
//     the name of the input files
// Returns: no return parameters
//------------------------------------------------------
void readFile(string filename)
{
	string s="";
	string c = "";
	LinkedList list1;//list for actor information
	LinkedList list2;//list for movie information

	ifstream in;
	in.open(filename);
	getline(in,s);

	while (s.length() != 0)
	{
		int count = 0;
		int year;
		char gender;
		string splitString[4];//split the line string to 4: family name, given name, birth year and gender

		for (int i = 0; (size_t)i < s.length(); i++)
		{
			if (s[i] == ' ')
				count++;
			else
				splitString[count] += s[i];

		}

		stringstream countStream1(splitString[2]);
		countStream1 >> year;//convert string to int
		stringstream countStream2(splitString[3]);
		countStream2 >> gender;//convert string to char

		list1.insert(new Actor(splitString[0], splitString[1], year, gender));//insert An actor to list1
		getline(in, s);
	}

	getline(in, s);
	

	while (s.length() != 0)
	{
		string movieName = "";
		int year;
		string fName="";
		string lName="";
		char actorGender=' ';
		int actorBirth=0;
		int addition;

		movieName = s;//first line is the name of the movie

		getline(in, s);//get next line

		if (s.length() > 4)//if next line's length is bigger than 4, then it has actor's information
		{
			int count = 0;
			string splitString[3];

			for (int i = 0; (size_t)i < s.length(); i++)//split the line's string to 3 part: released year of the movie, actor who played in this movie
			{
				if (s[i] == ' ')
					count++;
				else
					splitString[count] += s[i];
			}

			stringstream countStream(splitString[0]);
			countStream >> year;//convert string to int
			fName = splitString[1];
			lName = splitString[2];
			
			addition = list1.findActor(fName, lName, movieName, year);//find the birth year and gender of the actor

			if (addition < 0)
			{
				actorBirth = addition * -1;
				actorGender = 'F';
			}
			if (addition > 0)
			{
				actorBirth = addition;
				actorGender = 'M';
			}
			list2.insert(new Movie(movieName, year, fName, lName, actorBirth, actorGender));//insert the Movie to list2
		}
		else
		{
			stringstream countStream(s);
			countStream >> year;

			list2.insert(new Movie(movieName, year, fName, lName, actorBirth, actorGender));//in this case, actor's information is none
		}


		if (!in.eof())
			getline(in, s);
		else
			s = "";
	}

	list2.print();
	cout << endl << endl;
	list1.print();

	in.close();
}

int main(int argc,char *argv[])
{
	bool validFile = true;
	string fileName="a2q1.txt";

	/*if (argc != 2) 
	{
		cout << "usage: " << argv[0] << " <filename>\n";
		validFile = false;
	}
	else {
		ifstream the_file(argv[1]);
		if (!the_file.is_open())
		{
			cout << "Could not open file\n";
			validFile = false;
		}
	}*/


	if (validFile == true)
	{
		//fileName = argv[1];
		readFile(fileName);

	}

	
	return 0;
}