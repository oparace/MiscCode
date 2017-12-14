#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
  char Rock, Paper, Scissors;
  int a,b,c;
 
  do
    {
      cout<<"Choose Rock (0), Paper(1), or Scissors (2):"<<endl;
  cin>>a;
  
  if(a<0 || a>2)
    {
   cout<<"Please choose one of the options below!"<<endl;
    }
    }
  while(a<0 || a>2);


  srand(time(NULL));   //sync with time

  b = rand() % 3;  //pick random value from 1-3
  
  if(b==0)
    {
      cout<<"Computer chooses: Rock"<<endl;
    }
  if(b==1)
    {
      cout<<"Computer chooses: Paper"<<endl;
    }
  if(b==2)
    {
      cout<<"Computer chooses: Scissors"<<endl;
    }
//code to assign 'winner' and 'loser' based on input from computer
     
    if(a==0)
    {
      if(b==0)
	cout<<"You tie!"<<endl;
      if(b==1)
	cout<<"You lose!"<<endl;
      if(b==2)
	cout<<"You win!"<<endl;
    
    }
    

  if(a==1)
    {
      if(b==0)
	cout<<"You win!"<<endl;
      if(b==1)
	cout<<"You tie!"<<endl;
      if(b==2)
	cout<<"You lose!"<<endl;
    }


  if(a==2)
    {
     if(b==0)
       cout<<"You lose!"<<endl;
      if(b==1)
	cout<<"You win!"<<endl;
      if(b==2)
	cout<<"You tie!"<<endl;
    }
  
  return 0;
}

  
  

  

