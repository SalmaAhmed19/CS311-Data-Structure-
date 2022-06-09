//CS311 Yoshii S22 Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//  NEVER delete my comments!!!!
//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: **Salma Rashed
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{ cout << "... in llist constructor..." << endl;
  //construncter  
 //intializing front and rear to null
  Front=NULL;
  Rear=NULL;
  //intializing count to 0
  Count=0;//list is empty
 }

llist::~llist()
{
  el_t temp;//represent the node to be deleted 
 cout << ".... in llist destructor..." << endl;
 while (!isEmpty()){
    //calling deleteFront to delete all nodes repeatedly
   deleteFront(temp);
  }


 }

//PURPOSE:to check if the linked list is empty 
//PARAMETER:no parameters
bool llist::isEmpty() {
  //return true when front AND rear are null AND count=0 , which means the list is empty
  if(Front==NULL && Rear==NULL&& Count==0){
    return true;
  }else{//if it is not empty return false
    return false;
  }

 } // be sure to check all 3 data members

//PURPOSE:to display each element in the list starting from front enclosed in [] followed by endl, and if the list is enpty will display [empty]
//PARAMETER:no parameters
void llist::displayAll() {
  if(isEmpty()){//to check if the list is empty
    cout<<"[empty]"<<endl;
  }else{//else there is something to display
    Node*P=Front; //set a temperory value to the front of the list
    cout<< "[";
    while(P!=NULL){//While P isn't null(at the end) display

      cout<<" "<<P->Elem<<" ";//displaying elements
      P=P->Next;//move pointer to the next node 
    }
    cout<<"]"<<endl;

  }

 }  // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4]
// You MUST use while (P != NULL) loop or you will not get the credit!
  
//PURPOSE:adds a new node to the rear, if this is the first node then must create a new node and make front and rear point to it 

//PARAMETER:the element that will be added to the back of the list 

void llist::addRear(el_t NewNum) {

  //special case
  if(Front==NULL){//if this is the very first node 
    Front=new Node;//front now points to new node
    Rear=Front; //Rear and front are pointing at the same node
    Rear->Elem=NewNum;//front elem goes to new num
    Count++;//count is updated
  }else{
    //normal case
    Rear->Next=new Node;//add a node to the very end
    Rear=Rear->Next;// rear and rear next meet
    Rear->Elem=NewNum;//for the new node
    Rear->Next=NULL;//Rear->next should always be null to avoid having a danging pointer
    Count++;//count is updated
 } // comment the 2 cases
}
//PURPOSE: add a new node at the front and puts NewNum in the elem field  
//PARAMETER:the element that will be added in front of the list 
void llist::addFront(el_t NewNum) {
  //special case
  if(Front==NULL){// if this is the very first node
    Front=new Node;// front now points to a new node
    Rear=Front;//front and rear are now pointing at the same point
    Front->Elem=NewNum; //adding a newElem
    Front->Next=NULL;// to avoid having a dangling point 
    Count++;//update Count 
  }else{
    //regular case 
    Node*temp=new Node;//create a new node
    temp->Next=Front;// temp->next meets the front pointer 
    Front=temp;//front goes to where tep is 
    Front->Elem=NewNum;//put NewNum in the Elem field of the new Node 
    Count++;// update Count 
  }



 } // comment the 2 cases

//PURPOSE:delete front node and elem
//PARAMETER:the variable we will be passing the old elem  to be deleted 
void llist::deleteFront(el_t& OldNum) {
  //error case : if the list is emoty throw an exception
  if(isEmpty()){
    throw Underflow();
  }else if(Count==1){
  // special case: 
	   // if this is going to make the list empty, give back the front node element through OldNum (pass by reference) and also remove the front node. Count is updated.  Make sure both Front and Rear both become NULL
    OldNum=Front->Elem;//give back the front node elem through OldNum
    delete Front;//deleting front 
	   Front=NULL;//front becomes null
	   Rear=NULL;//rear becomes null
	   Count--;//decrement count
  }else{
    //regular case, give back the front node element through OldNum (pass by reference)
    // and also remove the front node. Count is updated.
    OldNum=Front->Elem;//give back the front node elem through OldNum
    Node*Second;
    Second=Front->Next;//know the second node
    delete Front;//delete the front node
    Front=Second;//front moves down
    Count--;//decrement count
  }


 } // comment the 3 cases

//PURPOSE:delete rear node and pass elem back 
//PARAMETER:the variable that will recieve the old elem 
void llist::deleteRear(el_t& OldNum){
  //special case: if is empty throw an exception
  if(isEmpty()){
    throw Underflow();
  }else if(Count==1){
    //special case:    if this is going to make the list empty,
    // give back the rear node element through OldNum (pass by reference)
    //	      and also remove the rear node. Count is updated.
    //        Make sure both Front and Rear become NULL).
    OldNum=Rear->Elem;//give back the rear node element through OldNum
    delete Rear;//remove the rear node
    Front=NULL;//set front=NULL
    Rear=NULL;//set Rear=Null
    Count--;//decrement 

  }else{
    OldNum=Rear->Elem;//give back the rear node element through OldNum
    Node*Second=Front;

    while(Second->Next!=Rear){//to stop at second to last 

      Second=Second->Next;//second next and second meet
    }
    delete Rear;//delete the rear
    Rear=Second;
    // Front=NULL;//set the front to null
    // Rear=NULL;//set the rear to null
    Rear->Next=NULL;   
 Count--;//decrement 

  }


} // comment the 3 cases


/*
/* --- harder ones for case 2 and 3 follow -- */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node  
  for ( int K = 1;K<=J-1;K++ ){
     temp = temp->Next;
  }
 

}

//PURPOSE:Delete the Ith node 
//PARAMETER:the node that will be deleted and the variable to use the old elem 
void llist::deleteIth(int I, el_t& OldNum) {
  //error case : if I is an illegal value 
  if(I>Count || I<1){
    throw OutOfRange();
  }else if ( I==1){
    //special case: if I =1 delete the front  by calling deleteFront
    deleteFront(OldNum);
  }else if(I==Count){
    //special case:  if I=count delete the rear by calling deleteRear
    deleteRear(OldNum);

  }else{
    //normal case
    Node*P=Front;//make P point to front 
    moveTo(I-1,P);//call move to function
    Node*Q=P->Next;//Q points to the Ith term
    P->Next=Q->Next;//P is pointing to the position after the ith 
    OldNum=Q->Elem;//old num gets Q's element
    delete Q;//release/delete Q
    Count--;//decrement count

  }

 } // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE:to add right before the ith node 
//PARAMETER:the element to be added and the designated element 
void llist::insertIth(int I, el_t newNum) {
  //error case: 
  if(I>Count+1 || I<1){
    throw OutOfRange();
  }else if(I==1){
    //special case: call add front incase i=1
    addFront(newNum);
  }else if (I==Count+1){
    //special case: call addrear in case i=count+1
    addRear(newNum);
  }else{
    //regular case
    Node*P=Front ;//set a new node  p and make it point to front
    moveTo(I-1,P);//call move to 
    Node*Q=new Node;//create a new node and make Q point to it 
    Q->Next=P->Next;//moves Q pointer to the ith term
    P->Next=Q;//p  points to the new node that is in front of ith  
    Q->Elem=newNum;//Q->Elem get newNum
    Count++;//increment count
  }

 } // must use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE:allow passing the list by value and returning by value 
//PARAMETER:sends the original data to be copied 
llist::llist(const llist& Original) {

  Front=NULL;
  Rear=NULL;
  Count=0;

  el_t x;
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  if (&Original != this) {  //if not the same 
      // this-> object has to be emptied first.
      while (! this->isEmpty() )
	this->deleteRear(x);  
      // this-> object has to be built up by allocating new cells with OtherOne elements (**)
      Node* P;  // local pointer for OtherOne
      P = Original.Front;
      while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
	  this->addRear(P->Elem);    //P’s element is added to this->
	  P = P->Next;                         // Go to the next node in OtherOne   
	} 
    }// end of if             
  //nothing to return here because it is a constructor

 } // use my code

//PURPOSE:to allow the client to use = for linked list objects
//PARAMETER:compare the pointers to the object from the original 
llist& llist::operator=(const llist& OtherOne) {



  el_t x;
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  if (&OtherOne != this)  // if not the same
    {
      // this-> object has to be emptied first.
      while (! this->isEmpty() )
	this->deleteRear(x);  
      // this-> object has to be built up by allocating new cells with OtherOne elements (**)
      Node* P;  // local pointer for OtherOne
      P = OtherOne.Front;
      while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
	  this->addRear(P->Elem);    //P’s element is added to this->
	  P = P->Next;                         // Go to the next node in OtherOne   
	} 
    }// end of if              
  return *this;    // return the result unconditionally.  Note that the result is returned by reference.

 } // use my code

