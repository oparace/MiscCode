#include <iostream>
#include <string>

using namespace std;

int main()

{
  
  int n, i, g;
  int h;
  int f;
  
  do
    {
  bool isPrime = true;

   cout << "Enter a positive integer: ";
   cin >> n;
  
   if(n<0)
     {cout<<"I don't deal with negativity"<<endl;
     }
   
   else if(n==0)
     {cout<<"0"<<endl;
     }
   
   else if(n==1)
     {cout<<"1"<<endl;
     }
   
   else
     { 
       for(g=1; g<=n; g++) 
	 {

       if(n % g ==0)
      {
	if(g<n)
	{ f = g;
	  cout<<f<<", ";
	}
	if(g == n)
	{
	h = g;
	cout<<h<<endl;
	}
	
       	
	
      }
	 }
       for(i = 2; i < n; ++i)
	 {
	   if(n % i == 0)
	   
	     {
	       isPrime = false;
	       break;
	     }
	 }
       if (isPrime)
	 cout << "This number is prime!"<<endl;
       else
	 cout <<""<<endl;
     }
    }  while(n>=0);
		
       return 0;
}
