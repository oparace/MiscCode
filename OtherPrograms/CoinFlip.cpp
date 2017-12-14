
#include <iostream>
using namespace std;


int choose(int N,int r)
    
  {
    
   if(r == 0 || r == N)
      return 1;
   // store C(n,r) in a matrix   
   int c[N+1][r+1];
   int i,j;
   for(i=0;i<=N;i++) {
      // C(i,0) = 1 for i = 0...n  
      c[i][0] = 1;
   }
   for(j=0;j<=r;j++) {
      // if n = 0, C(n,r) = 0 for all 'r'
      c[0][j] = 0;
   }
   for(i=1;i<=N;i++)
     {
      for(j=1;j<=r;j++)
	{
         if (i == j) {
            // C(n,n) = 1
            c[i][j] = 1;
         }
         else if (j > i) {
            // case when r > n in C(n,r)        
            	c[i][j] = 0;
         }
         else {
            // apply the standard recursive formula        
            c[i][j] = c[i-1][j-1] + c[i-1][j];
	    int comb =  c[N][r];
         }
      }
   }
   return c[N][r];
  }

int main()
{
    
    
    int N,r;
    char a;
    

do
     {
  cout<<"How many coins woud you like to flip?"<<endl;
  cin>>N;
  cout<<"How many heads do you want"<<endl;
  cin>>r;
  int comb= choose(N,r);
   cout<<"Flipping "<<N<<" coins, we can get "<<r<< " heads "<<comb<<" ways."<<endl;
  cout<<"Flip again? (y/n)"<<endl;
  cin>>a;
  if(a=='n')
    {break;}
     }
 while(a=='y');
 
return 0;
}
