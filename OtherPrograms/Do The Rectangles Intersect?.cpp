#include <iostream>
using namespace std;



int main()
{

  int x,y,l,h;
  int abottom, atop, bbottom, btop, aleft, aright, bleft, bright;

    //Rectangle_1
    
  cout<< "Enter the information for the first rectangle"<< endl;
  cout<< "x-coordinate:";
  cin>>x;
  cout<< "y-coordinate:";
  cin>>y;

  cout<< "length:";
  cin>>l;
  cout<<"height:";
  cin>>h;

  abottom = y;
  atop = y+h;
  aleft = x;
  aright = x+l;  //inputs the rectangle1 dimensions

    
    //Rectangle_2
    
  cout<< "Enter the information for the second rectangle"<< endl;
  cout<< "x-coordinate:";
  cin>>x;
  cout<< "y-coordinate:";
  cin>>y;

  cout<< "length:";
  cin>>l;
  cout<<"height:";
  cin>>h;

  bbottom = y;
  btop = y+h;
  bleft = x;
  bright = x+l;  //inputs the rectangle2 dimensions

  if((abottom > btop) || (atop < bbottom) || (aright < bleft) || (aleft > bright))
      {
	cout<< "THE RECTANGLES DO NOT INTERSECT"<<endl;

      }
      else
      {
	cout<< "THE RECTANGLES INTERSECT" <<endl;
      }
//determines if the rectangles intersect
	return 0;
}
