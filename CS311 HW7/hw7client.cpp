// CS311 YOSHII S22 hw7client.cpp

//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: **
// File type: client hw7client.cpp 
//==========================================
#include<iostream>
#include<fstream>
#include<string>
#include "dgraph.h"
#include "stack.h"
using namespace std;
// ** Be sure to include both dgraph  and stack

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  // ** copy here the algorithm (read carefully) in the HW7
  // assignment sheet and use that for the comments. 
  /*D isplay the graph before DFS begins.

Push A onto the stack to start.
  While the stack is not empty do:
  {
    Remove a vertex v from the stack.
Display the vertex name.  E.G. “Removed B from stack”
      If v is not marked yet (visit number is 0) then 
      mark it (visit it **) and inform the user E.G. “Visit B as 2”
      get its adjacency list (slist)
if no adjacent ones inform the user E.G. “Deadend reached – backup”
  else put adjacent ones on the stack (delete from the rear and push) informing the user
    else inform the user E.G. “B had been visited already - backup.”
Display the stack clearly labeling it as the current stack
	   }
    Display the Graph nicely with visit numbers for all vertices.

							  (**) visit numbers will start at 1 and increase as you traverse and visit.
  */
  dgraph table ;//intialize a new graph
  slist tempList;//holds list given from adjacent vertex function
  stack tableStack;//stack for holding vertex pushed from the graph
  int visitNum=1;//indicates the current slot in the graph
 

  //display the graph before DFS begins 
  table.fillTable();//fill the graph
  table.displayGraph();//display without assigned visit numbers
  tableStack.push('A');//start with A

  //while stack is not empty
  while (!tableStack.isEmpty()){
    char vertex; 
   tableStack.pop(vertex);
    cout<<"\n Removed "<<vertex<<" from stack"<<endl;
      //if v is not marked yet (visit number is 0)
      if(!table.isMarked(vertex)){
	table.visit(visitNum,vertex);

	//inform the user 
	cout<<"\n Visit "<<vertex<<" as "<<visitNum<<endl;
	visitNum++;


	
	tempList=table.findAdjacency(vertex);

	if(tempList.isEmpty()){
	  //find the adjacent list from popped vertex 
           cout<<"Deadend rached -backup";
	}else {
	  //push the adjacent verteces until list is empty
	  while (!tempList.isEmpty()){
	    //store rear vertex into vertex
	    tempList.deleteRear(vertex);
	    tableStack.push(vertex);
	    cout<<"\n Pushing "<<vertex<<"into stack"<<endl;

	  }
	 }

	
        }else {
	
	  cout<<vertex<<"has been visited already-backup\n"<<endl;
	}
	tableStack.displayAll();

  }
    table.displayGraph();

}
