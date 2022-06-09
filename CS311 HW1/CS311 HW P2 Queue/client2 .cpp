//CS311 Yoshii S22 client2.cpp
//INSTRUCTION:
//Look for ** to complete this program and comments.
//The string output should match my hw1queueDemo.out 
// NEVER delete my comments!!!!
//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: **Salma Rashed
//Complier:  **g++
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: **Given a set of characters ,we want to display all the string this charcters can do 
//Algorithm: **looping by removing a string and displaying it .Add the string "+A", add the string"+B" and add the string "+C"

int main()
{// ** //  place "A", "B", "C" in the queue
  string character;
  queue myQueue;
  myQueue.add("A");
  myQueue.add("B");
  myQueue.add("C");
  // ** //  while loop -- indefinitely while(true)
  while(true) 

   {
      try
	{// **  // do the steps noted in the notes 
	 
	  myQueue.remove(character);
	  cout<<character<<endl;

	  myQueue.add( character+"A");
	  myQueue.add(character+"B");
	  myQueue.add(character+"C");



	}
      //      catches **

      catch (queue:: Overflow)	{
	// **
	cerr<<"Error Overflow , queue is full"<<endl;
	exit(1) ;
	}
      catch( queue:: Underflow){
        cerr<<"Error Underflow";
        exit(1);
      }
    }// end of loop

}

