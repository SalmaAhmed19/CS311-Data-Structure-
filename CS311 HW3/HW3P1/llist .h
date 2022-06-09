//CS311 Yoshii S22 llist.h
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: **Salma Rashed
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 private:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //**
  //checks to see if empty  
  bool isEmpty();
    
  //**
  //Display linked list
  void displayAll();

  //**
  //purpose: creates a node and adds it to the front of the list 
  //parameter: the value of the node to be added 
 void addFront(el_t);
    
  //**
 //purpose: creates a node and adds it to the rear of the list
 //parameter: the value of the node to be added 
  void addRear(el_t);

  //** 
  //purpose : deletes the first element in the list 
  //parameter:the value that is removed  
  void deleteFront(el_t&);
  
  
    
  //**
  //purpose: delete the last element in the list 
  //parameter : the value thatis removed 
  void deleteRear(el_t&);
  //-------------------------------------  
  //**
  //purpose: delete the Ith element (Ith=user input )
  //parameter: the value that is removed 
  void deleteIth(int, el_t&);  // calls moveTo

  //**    
  //Purpose: to add an element before the designated element
  //parameter: the designated elem and the variable we send the old number to 
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
