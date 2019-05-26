- I develop the program in Windows 10 with Microsoft Visual Studio Community 2015 (Version 14.0.25431.01 Updata 3)
  And I also compile it use U of M Linux with g++.


- How to compile and run:
  1. Copy the next 8 lines, and paste it to the command line.
  
	gcc -c -I ../include Object.cpp
	gcc -c -I ../include Actor.cpp
	gcc -c -I ../include Movie.cpp
	gcc -c -I ../include Node.cpp
	gcc -c -I ../include LinkedList.cpp
	gcc -c -I ../include main.cpp
	g++ -o output main.o Node.o Object.o Movie.o LinkedList.o Actor.o
	
  2. Then type the command follow this format:  output <filename>
     For example, type:				output a2q1.txt
   
   
- Each classes's information and relationships.
	Object class is the abstract class of Actor class, Movie class and Node class.
	Actor class store the inforamtion of actors.  Movie class store the information of movies.
	Node class is used for organizing the actor and movie.
	LinkedList class makes Node connected, it is the exactly function of normal LinkedList that we use.
	main class have two method.  One is read the files and create linkedlist to connect it.  The other method is the main method.