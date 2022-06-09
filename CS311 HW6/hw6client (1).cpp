// CS311 Yoshii S22 hw6client.cpp
// HW6 Client file 
// INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client 
// Name: **Salma Rashed
// File type:  ** client program  (tester)
// ================================================

//** // includes
#include "dgraph.h"
#include"cstdlib"
#include"iomanip"

//** // comments
//main program 
using namespace std;

int main()
{// **
  char  ans;
  slist s1; 
    //0.Declare dgraph object
 dgraph TableObj;
   //1.fillTable()
 cout<<"Filling Table..."<<endl;
 TableObj.fillTable();
    //2.displayGraph()
 cout<<"Displaying Table..."<<endl;
 TableObj.displayGraph();
    //while (the user does not want to stop)
    //a.the user will specify which vertex     
    //b.findOutDegree of the vertex and display the result
    //b.findAdjacency of the vertex and display the result (see Hint)
    //c.catch exception to display error mesg but do not exit
 do{
   //ask the vertex from the user
   cout<<"Enter a vertex name or enter 0 to exit "<<endl;
   cin>>ans;
   try{
     if(ans!='0'){
       cout<<TableObj.findOutDegree(ans)<<" come out to:  "<<endl;
       s1=TableObj.findAdjacency(ans);
       s1.displayAll();
     }else
       break;
   }
   catch(dgraph::BadVertex){
     cerr<<"Error:Vertex not in graph"<<endl;
   }

 //end of while
 }while(ans!=0);
}
/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/
