#include <iostream>
#include <conio.h>
using namespace std;
int power(int x,int y){

    int ans=1;
    for(int i=0;i<y;i++){
        ans*=x;
    }
    return ans;
}
float power(float x,int y){
    float ans=1;
    for(int i=0;i<y;i++){
        ans*=x;
    }
    return ans;
}
int main(){

	int y,xi;float xf;
	int a;
	cout<<"If base is an integer enter 1 otherwise 2";
	cin>>a;
	if(a==1){
	    cout<<endl<<"enter base and power:";
	    cin>>xi>>y;
	    int ans=power(xi,y);
	    cout<<endl<<"answer is :"<<ans;
	}
	else{
	    cout<<endl<<"enter base and power:";
	    cin>>xf>>y;
	    float ans=power(xi,y);
	    cout<<endl<<"answer is :"<<ans;
	}
	getch();
	return 0;
}
