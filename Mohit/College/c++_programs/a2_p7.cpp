#include <iostream>
#include <conio.h>
using namespace std;
class box{
    double l,b,h,volume;
    public:
        box(double x,double y,double z){
            l=x;b=y;h=z;volume=l*b*h;
        }
        void vol(){
            cout<<"The volume of the box is: "<<volume<<endl;
        }
};
int main() {

    box b1(2.05,3.500,6.846);
    b1.vol();
    getch();
    return 0;
}
