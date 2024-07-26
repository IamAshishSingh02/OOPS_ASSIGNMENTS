#include<bits/stdc++.h>
using namespace std;

class Rectangle
{
private:
   int width;
   int height;

public:
   //Default Constructor
   Rectangle():width(0),height(0)
   {
      cout<<"Default Constructor called"<<endl;
   }

   //Parameterized Constructor
   Rectangle(int w,int h):width(w),height(h)
   {
      cout<<"Parameterized Constructor called with width = "<<width<<" and height = "<<height<<endl;
   }

   //Copy Constructor
   Rectangle(const Rectangle& other):width(other.width),height(other.height)
   {
      cout<<"Copy Constructor called"<<endl;
   }

   //Move Constructor
   Rectangle(Rectangle&& other) noexcept:width(other.width),height(other.height)
   {
      cout<<"Move Constructor called"<<endl;
      //Reset other object
      other.width = 0;
      other.height = 0;
   }

   //Display function
   void display() const
   {
      cout<<"Rectangle(width="<<width<<",height="<<height<<")"<<endl;
   }
};

int main()
{
   //Default Constructor
   Rectangle r1;
   r1.display(); //Should display:Rectangle(width=0,height=0)

   //Parameterized Constructor
   Rectangle r2(10,20);
   r2.display(); //Should display:Rectangle(width=10,height=20)

   //Copy Constructor
   Rectangle r3(r2);
   r3.display(); //Should display:Rectangle(width=10,height=20)

   //Move Constructor
   Rectangle r4(std::move(r2));
   r4.display(); //Should display:Rectangle(width=10,height=20)
   r2.display(); //Should display:Rectangle(width=0,height=0),as r2 has been moved from

   return 0;
}