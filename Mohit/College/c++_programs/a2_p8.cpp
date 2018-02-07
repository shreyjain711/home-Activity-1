#include <iostream>
#include <conio.h>
using namespace std;

class complex{
    int x,y;
    public:
        void getVal(){
            cout<<"Enter the values of real and imaginary components of the complex number"<<endl;
            int a,b;
            cin>>a>>b;
            x=a;y=b;
        }
        complex operator+(complex c){
            complex temp;
            temp.x=x+c.x;
            temp.y=y+c.y;
            return temp;
        }
        complex operator-(complex c){
            complex temp;
            temp.x=x-c.x;
            temp.y=y-c.y;
            return temp;
        }
        void disp(){
            cout<<"Real part is: "<<x<<" & Imaginary part is: "<<y<<endl;
        }
};
int main() {
    clrscr();
    complex c1,c2,c3,c4;
    c1.getVal();
    c2.getVal();
    c3=c1+c2;
    c4=c1-c2;
    cout<<"c3(=c1+c2)"<<endl;c3.disp();
    cout<<"c4(=c1-c2)"<<endl;c4.disp();
    getch();
    return 0;
}
