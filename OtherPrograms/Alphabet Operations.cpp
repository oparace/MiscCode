#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>
#include<cstdlib>
#include <ctype.h>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <locale>
using namespace std;

int main()

{
  char a,c;
  int e;
  int d;
  std::string f;
  char i[27];
  char j[27];
  char k[27];
  char l[27];
  int b;
 

  do
    {
      cout<<"Enter char:"<<endl;
      cin>>a;
      if(!isalpha(a))
       {
      cout<<"Illegal input"<<endl;
       }
    }
  while(!isalpha(a));
  
  do
    {
      cout<<"Choose an operation: (1) change case; (2) reverse alphabet; (3) encrypt."<<endl;
      cin>>b;
      if((b<1) || (b>3))
       {
	 cout<<"Illegal operation"<<endl;
       }
    }
   while((b<1) || (b>3));
  
//switches between letter cases 
   if(b==1)
     {
       if(islower(a))
	 {
	   a = toupper(a);
	   cout<<"Result: "<<a<<endl;
	     }
      
       
       else if(isupper(a))
	 {
	   a = tolower(a);
	   cout<<"Result: "<<a<<endl;
	 }
      
     }

     if(b==2)
       {
	 char i[33]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','\0'};
	 char j[27]= {'z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','\0'};
	 char k[33]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','\0'};
	 char l[27]= {'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A','\0'};

	   if(islower(a))
	     
	   {
	   a  = toupper(a);
	   
	 for(e=0; e<27; e++)
	   {
	 if(k[e] == a)
	   {
	     d=e;
	   }
	   }
	  c=l[d];
	   }
	 
	 else if(isupper(a))
	 {
	   a = tolower(a);

	   for(e=0; e<27; e++)
	   {
	 if(i[e] == a)
	   {
	     d=e;
	   }
	   }
	  c=j[d];
	 }
	   cout<<"Result: "<< c <<endl;
       }

     if(b==3)
       {
	  char i[33]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','\0'};
	 char j[27]= {'z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','\0'};
	 char k[33]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','\0'};
	 char l[27]= {'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A','\0'};
	 
         if(islower(a))
	   {
	   a  = toupper(a);
  
	 for(e=0; e<27; e++)
	   
	   {
	 if(k[e] == a)
	   {
	     d = (e + 6);
	   }
	   }
	   
       	 c=i[d];
	   }
	 
	 else if(isupper(a))
	   {
	   a = tolower(a);

	   for(e=0; e<27; e++)
	   {
	 if(i[e] == a)
	   {
	     d = (e + 6);
	     
	   }
	   }
	  c=k[d];
       }
	 cout<<"Result: "<<c<<endl;
       }
 
  return 0;
}
