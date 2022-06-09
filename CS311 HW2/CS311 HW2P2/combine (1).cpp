using namespace std;
#include <iostream>
#include <vector>

// CS311 YOSHII S22 combine.cpp
// Must use the algorithm that is in the notes! 
//  NEVER delete my comments!!
//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: **Salma Rashed
//Compiler: g++
//--------------------------------------------

// combines two sorted lists A and B into R
// displays comparison every time it is done
void combine( vector<int> A, vector<int> B, vector<int> &R )
{
  //   ** // you can find out the size of A using the
  int ia=0;//index for A
  int ib=0;//index for B
  int ir=0;//index for R
  // ** // size function. Treat A and B like arrays.     
  //till you run out of elements in A and b 
  while(ia<A.size()&& ib<B.size()){
   if(A[ia]<B[ib]){
     //get the A  element to R
      R.push_back(A[ia]);     
      ia++;
    }else{
      //get the B element to R
      R.push_back(B[ib]);
       ib++;
    }
    ir++;
 cout << "comparison" << endl;
  }
 // **
     // be careful -- R comes in as an empty vector with no slots so you have to use push_back

 //if you still have A elements left , copy them into r
 if(ia<A.size()){
   //to keep checking
   while(ia<A.size()){  
      R.push_back(A[ia]);
      ia++;
    }

 }else{//copy the remaining B elements into R
   
   while (ib<B.size()){
	 R.push_back(B[ib]);
       	 ib++;
       }
 
  }//end of the else statment
 // }//end of the while loop
  ir++;
  cout<<"The rest of the second one goes down"<<endl;
}//end of the vector function

int main()
{  
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);} 

  cout << "List2"  << endl; 
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L2.push_back(e);} 
  

  // call combine here to combine L1 and L2 into L3
  // **
  combine(L1,L2,L3);
  
  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;


}// end of main
