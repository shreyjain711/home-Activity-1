#include <iostream>
#include <conio.h>
using namespace std;
class usdToInr{
    int usd;
    public:
        inline void getVal(){
            cout<<"Enter your amount in USD($):";
            cin>>usd;
            cout<<endl;
        }
        inline int convert(){
            int x=usd;
            x*=65;
            return x;
        }
};
int main(){

    usdToInr obj;
    obj.getVal();
    int amtInInr=obj.convert();
    cout<<"Your amount in INR is: Rs "<<amtInInr<<endl;
    getch();
}
