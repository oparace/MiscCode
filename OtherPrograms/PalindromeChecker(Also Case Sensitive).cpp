#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
using namespace std;


int main()
{
    char string1[20];
    int i, length;
    

    bool is_palindrome = false;
    bool is_case_palindrome = false;

do
  {   
    cout << "String: ";

cin.getline(string1,sizeof(string1));



    if(string1[0] == 0)
      {
	break;
      }
   
   
   
    length = strlen(string1);
    
    for(i=0;i < length ;i++)
      {
	if((toupper(string1[i]) == toupper(string1[length-i-1])) && ((islower(string1[i]) && isupper(string1[length-i-1])) || (isupper(string1[i]) && islower(string1[length-i-1]))))
	  
	  {
		    is_case_palindrome = true;
		    break;
	  }
      
	  
	     
	 if(string1[i] == string1[length-i-1])
	       {
	 is_palindrome = true;
	 is_case_palindrome = false;
	       }

       
	 if(string1[i] != string1[length-i-1])
	       {
		  is_case_palindrome = false;
		 is_palindrome = false;
	       }
      }
     
	  if(is_palindrome==true && is_case_palindrome == false )
      { cout<<"The string "<<string1<<" is a palindrome"<<endl;}
    
    if(is_case_palindrome ==true)
      {
	cout<<"The string "<<string1<<" is a palindrome with inverted case"<<endl;
      }
    if(is_palindrome == false &&  is_case_palindrome == false)
      {
	cout<<"The string "<<string1<<" is not a palindrome"<<endl;
      }  
	      

  }
 while(!(string1[0] = 0));

 if(string1[0] == 0)
     {
       cout<<"Bye Bye!"<<endl;
     }
   
   
    return 0;
}
