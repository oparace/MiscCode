#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  char Cups, Ounces, Tablespoons, Teaspoons;
  
   double a; double b; double c;
  
  
  //cup = 8*ounce;
  //cup = 16*tablespoon;
  //cup = 48*teaspoon;
  //ounce = 6*teaspoon;
  //ounce = 2*tablespoon;
  //teaspoon = tablespoon/3;

  cout<<"Cups = 1, Ounces = 2, Tablespoons = 3, Teaspoons = 4"<<endl;
  do
    {
  cout<<"Conversion from:";
  cin>>a;
  if(a<1 || a>4)
    {cout<<"Please Try Again"<<endl;}
    }
  while(a<1 || a>4);
  
  do
    {
  cout<<"Conversion to:";
  cin>>b;
  if(b<1 || b>4)
    {cout<<"Please Try Again"<<endl;}
    }
  while(b<1 || b>4);
  
  if(a==1)
    {
    cout<<"Enter the amount in Cups:";  //conversion from Cup to others
    cin>>c;
    if(a==1)
    {
      if(b==1)
	cout<<c<<" Cups is "<<c<<" "<<"Cups"<<endl;
      if(b==2)
	cout<<c<<" Cups is "<<c*8<<" "<<"Ounces"<<endl;
      if(b==3)
	cout<<c<<" Cups is "<<c*16<<" "<<"Tablespoons"<<endl;
      if(b==4)
	cout<<c<<" Cups is "<<c*48<<" "<<"Teaspoons"<<endl;
    }
    }

  if(a==2)
    {
    cout<<"Enter the amount in Ounces:"; //conversion from Ounces to others
    cin>>c;
      if(a==2)
    {
      if(b==1)
	cout<<c<<" Ounce is "<<c/8<<" "<<"Cups"<<endl;
      if(b==2)
	cout<<c<<" Ounces is "<<c<<" "<<"Ounces"<<endl;
      if(b==3)
	cout<<c<<" Ounces is "<<c*2<<" "<<"Tablespoons"<<endl;
      if(b==4)
	cout<<c<<" Ounces is "<<c*6<<" "<<"Teaspoons"<<endl;
    }
    }

  if(a==3)
    {
      cout<<"Enter the amount in Tablespoons:";  //conversion from Tablespoons to others
    cin>>c;
     if(a==3)
    {
      if(b==1)
	cout<<c<<" Tablespoons is "<<c/16<<" "<<"Cups"<<endl;
      if(b==2)
	cout<<c<<" Tablespoons is "<<c/2<<" "<<" Ounces"<<endl;
      if(b==3)
	cout<<c<<" Tablespoons is "<<c<<" "<<"Tablespoons"<<endl;
      if(b==4)
	cout<<c<<" Tablespoons is "<<c*3<<" "<<"Teaspoons"<<endl;
    }
    }

  if(a==4)
    {
    cout<<"Enter the amount in Teaspoons:";
    cin>>c;
    if(a==4)
    {
      if(b==1)
	cout<<c<<" Teaspoons is "<<c/48<<" "<<"Cups"<<endl;  //conversion from Teaspoons to others
      if(b==2)
	cout<<c<<" Teaspoons is "<<c/6<<" "<<"Ounces"<<endl;
      if(b==3)
	cout<<c<<" Teaspoons is "<<c/3<<" "<<"Tablespoons"<<endl;
      if(b==4)
	cout<<c<<" Teaspoons is "<<c<<" "<<"Teaspoons"<<endl;
    }
    }

  return 0;
}

  
  

  

