//INSTRUCTION: S22 queue.cpp
//Look for ** using control-S
//Then, fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors
// NEVER delete my comments!!!
//=========================================================
//HW#: HW1P2 queue
//Your name: **Salma Rashed
//Complier:  **g++
//File type: **  queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{  // initialize data members as in the notes 
  count=0;
  front=0;
  rear=-1;

}

//destructor 
queue::~queue()
{ // nothing
}

// PURPOSE: returns true if queue is empty, otherwise false - checks count
bool queue::isEmpty()
{
  if(count==0){//when count is =0 then this means it is empty otherwise it is not empty 
    return true;
  }else{
    return false;
  }
}

// PURPOSE: returns true if queue is full, otherwise false - checks count
bool queue::isFull()
{
  if(count==MAX_SIZE){
    return true;
  }else{
    return false;
  }
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  if(isFull()){
    throw Overflow();
  }
  //the add function for the rear
    rear=(rear+1)%MAX_SIZE;
    el[rear]=newElem;
    count++;
   
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  if(isEmpty()){
    throw Underflow();
  }
  //the remove function
  removedElem=el[front];
  front=(front+1)%MAX_SIZE;
  count--;
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
 if(isEmpty()){
   throw Underflow();
 }
 theElem=el[front];
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return count;
}

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue::displayAll()
{
  if (isEmpty()) {
  cout << "[ empty ]" << endl;
  }
    else {
     int j = front;
     cout << "[";
     
     for (int i = 1; i <= count; i++) {
   // **
       cout<<el[j];
	 j= (j+1)%MAX_SIZE;//incrementing
	  
      }
      cout << "]" << endl;   
    }  
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
void queue::goToBack()

{
       
	  if(isEmpty()){
	    throw Underflow();
	  }           
	//no condition needed when count =1 becaue it will do nothing 
	//**
	el_t temp ; //need a local variable , el_t is more flexible 
	if(count>0){
	  //remove and add function;
	  remove(temp);
	  add(temp);
	}  
}

