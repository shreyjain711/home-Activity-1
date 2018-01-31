#include<iostream>
#include<string>

using namespace std;


class String {
    public :
    char a[30];
    string(){
        a[]={"hello"};
    }
    String(char s[]){
        strcpy(a,s);
    }
    String operator +(String b) {
        return b(strcat(a,b.a));
    }
};

int main(){
    String c1,c2;
    srtcpy(c1.a,"c++ ");
    strcpy(c2.a,"programing");
    c1 = c1 + c2;
    cout<<c1.a;
    return 0;
}
