// CS311 Yoshii S22 - HW5 Priority Queue Implementation File
// Complete all ** parts and give good comments
// ** NEVER delete my comments.

// =================================================
// HW5 Priority Printer Queue 
// YOUR NAME: **Salma Rashed
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"


// constructor
pqueue::pqueue()
{  count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
// Remember that the current last job is in slot count-1.
void pqueue::insertjob(int j)
{
  cout << "Adding: " << j << endl;
  //  add the job j at the rear (and update count)
  //    if impossible else display error message. 
  // **
  if(count>=MAX){
    cout<< "..cannot add..FULL!!"<<endl;
  }else{
    Q[count]=j;
    count++;
  }
trickleup();//moves job to the right place 
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "Printing: " << Q[0] <<endl;
  reheapify(); 
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ cout << "Jobs: " ;
  // loop to display jobs from slot 0 to slot count-1 horizontally. No need to show a tree format.
  //**
  for(int i=0;i<=count-1 ;i++){
    cout<<Q[i]<<" ";//to display horizontally 
  }
  cout<<endl;
} 


// Utility functions follow: ------------------

void pqueue::swap(int loc1, int loc2)
{
  //  simply swap the values in these locations in Q
  // **
  int temp ;
  //loc1 is x and loc 2 is parent 
      temp=Q[loc1];
      Q[loc1]=Q[loc2];
      Q[loc2]=temp;
 
}//end of the function 

// Purpose: to make the very last job trickle up to the right location.
// Never do X--. 
void pqueue::trickleup()
{ 
  int x = count-1;  // the very last job's location
  //  While x is > 0   
  //    compare Q[x] with the parent value (*)
  //    and if the parent value is bigger call swap & update x 
  //    to be the parent location. Otherwise stop the loop.
  // (*) Call getParent to get the location of the parent
  //            based on the child's location.
  // **
  while(x>0){
    if( Q[x]<Q[getParent(x)]){
      swap (x,getParent(x));
      x=getParent(x);
    }else
      return;
  }  
}

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int childloc)
{ // ** //  return the parent location based on the child loc
  if(even (childloc)){
    return ((childloc-2)/2);
  }
  return ((childloc-1)/2);
}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; }
// Purpose: to reheapify the Pqueue after printing
//  This trickles down.  Never do X++.
void pqueue::reheapify()
{ int X;   // the current location
  Q[0] = Q[count-1];  // move the last job to the front
  count--;
  //  Start X at 0 (the root)
  // **
  X=0;
  int child;//to hold the current child 

  //  While X is within the array (the used portion):
  //       Find the location of the smaller child by calling getSmallerchild.
  //       (if the location of both children are off the tree, stop the loop).
  //       If the smaller child is smaller than the parent value,
  //          call swap and X becomes the smaller child's location.
  //       else no swaps so stop to loop.
  //  **
  while(X<count){
    child=getSmallerchild(X);
    if(Q[child]<Q[X]&& child!=-1){//-1 means that both children are beyond -1 
      swap(child,X);
      X=child;
    }else{
      return ;

    }//end of the else 
  }//end of the while loop 
}//end of the function
// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i)
{ int LC, RC; // locations of children
  int smallest; 
 // ** // set LC and RC first.
  LC=(2*i)+1;
  RC=(2*i)+2;

//    return the location of the smaller child 
//    Be careful because one or both of them may be
//    beyond count-1 or just the RC is beyond count-1.
//    Check boundaries before you 
//    compare Q contents!!!!
//    If both are beyond count-1, you want to return a special value.
// **
  if(LC>=count-1&& RC>=count-1){//both beyond count -1
    return -1;
  }else if (LC>=count-1 && RC<=count-1){//LC beyound count-1
    return RC;
  }else if(LC<=count-1 && RC>=count-1){//RC beyond count-1
    return RC;
  }else{//regular case-both NOT  beyond count-1
    if(Q[LC]>Q[RC]){
      return RC;
    }else{
      return LC;
    }
  }//end of 1st else
}//end of the function 

// NEVER GO TO UNUSED PART OF THE ARRAY 
