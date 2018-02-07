#include<iostream>
#include<conio.h>
using namespace std;
int i;

class Prime
{private:
  int num;
 public:
  int primecheck(int n)
   {for(i=2;i<n;i++)
     {if(i==n-1)
       return 1;
      else if(n%i==0)
       return 0;
     }
   }

  void setnum(int n)
   {num=n;}

  void shownum()
   {cout<<num<<endl;}

};

int main()
{Prime P1;

 int j;
 cout<<"Odd Prime Numbers between 1-100 are"<<endl;

 for(j=3;j<101;j++)
  {if(P1.primecheck(j))
     {P1.setnum(j);
      P1.shownum();
     }
   }
return 0;
}
