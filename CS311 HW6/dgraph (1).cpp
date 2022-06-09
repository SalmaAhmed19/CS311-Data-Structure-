//CS311 Yoshii S22 dgraph.cpp 
// INSTRUCTION:
//   Complete all the functions you listed in dgraph.h
//   Comment the file completely using How to Comment file.
//   Use HW6-help.docx to finish the functions.
//  NEVER delete my comments!!!
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: **Salma Rashed
// File Type: **Implementation file for dgraph.cpp
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

dgraph::dgraph()
 // initialize vertexName (blank) and visit numbers (0) for all slots of the table
 // initialize countUsed to be 0
{
  countUsed=0;
  for (int i=0;i<SIZE;i++){
    Gtable[i]. vertexName=' ';
   Gtable[i]. visit=0;
  }
 
}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
  //destructor is called automatically 

}

void dgraph::fillTable()  // be sure to read from a specified file
// you will have to use a linked list function addRear. 
{
  char X;
  string fname;
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname

  // the rest is in HW6-help
 
  while(fin>>Gtable[countUsed].vertexName){
    fin>>Gtable[countUsed].outDegree;
    for(int i=0;i<Gtable[countUsed].outDegree;i++){
      fin>>X;
      (Gtable[countUsed].adjacentOnes).addRear(X);
    }
    countUsed++;
  }
  fin.close();
}
void dgraph::displayGraph() // be sure to display
// you will have to use a linked list function displayAll. 
{// in a really nice table format -- all columns but no unused rows and include the total number of edges at the top
  int num_edge=0;
  for(int i=0;i<countUsed;i++){
    num_edge+=Gtable[i].outDegree;
  } 

  cout<<"** The number of edges is : "<<countUsed<<endl;
  cout<<"Out  Visit  Adj \n";
  cout<<"---------------------------------"<<endl;
  for (int i=0;i<countUsed;i++){
    cout<<Gtable[i].vertexName<<" "<<Gtable[i].outDegree;
    cout<<"\t"<<Gtable[i].visit<<"\t";
    (Gtable[i].adjacentOnes).displayAll();
  }
}

int dgraph::findOutDegree(char V)// throws exception if not found
{// does not use a loop - go directly to a slot using V
  int index=V-65;
  if(index>countUsed || index<0){
    throw BadVertex();

  }else{
    return Gtable[index].outDegree;
  }
 }
slist dgraph::findAdjacency(char V)// throws exception if not found
{// does not use a loop - go directly to a slot using V
  int index=V-65;
  if(index>countUsed || index<0){
    throw BadVertex();
  }else
    return Gtable[index].adjacentOnes;
}
