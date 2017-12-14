#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main()
{
  

  int a,b,diff,i,j,hd;
  std::stringstream ss;
  std::stringstream st ;
  std::string c;
  std::string d;
  int lengthofstring1;
  int lengthofstring2;

  j=0;
  hd=0;

  cout<<"Enter two positive integers"<<endl;

 
  do
    {
      
  cout<<"First Integer: ";
  cin>>a;
 
  if(a<0)
  {
  cout<<"Please input a positive integer"<<endl;
  }
    } while(a<0);  //sanitie first input
  
  do
    {
  cout<<"Second Integer: ";
  cin>>b;
 
  if(b<0)
  {
  cout<<"Please input a positive integer"<<endl;
  }
    }
  while(b<0); //sanitize second input

  if(a!=b)
    {
    
      ss << hex << a; //convert integer to string

  ss >> c;

  st << hex << b;
  
  st >> d;

 lengthofstring1 = c.length();
 lengthofstring2 = d.length(); //find lengths of numbers

  diff = abs(lengthofstring1-lengthofstring2); 
  
  if(lengthofstring1 < lengthofstring2)
    {
      for(i=0; i<diff; i++)
      {
	  c = '0' + c;
	  
	 
      } 
    }                                           //zero padding

  if(lengthofstring2 < lengthofstring1)
    {
      for(i=0; i<diff; i++)
      {
	  d = '0' + d;
	  
      }
    }
 
  while(j<(c.length())) //find hamming distance
  {
       if(c[j] != d[j])
	 {
	   hd = hd+1;
	   j = j+1;
          
	 }
  }
    }


    cout<<"The Hamming Distance between "<<a<<" and "<<b<<" when numbers are in hex format is: "<<hd<<endl;
    
 
  return 0;
}
   
