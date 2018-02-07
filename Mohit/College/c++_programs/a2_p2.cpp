#include<iostream>
#include<conio.h>
using namespace std;

class Sort
{private:
    int num[10],t,i=0,j;
 public:
  int input(int n)
   {num[i]=n;
    i++;}

  void sortinput()
   {for(i=0;i<10;i++)
     {for(j=i+1;j<10;j++)
       {if(num[i]>num[j])
         {t=num[i];
          num[i]=num[j];
          num[j]=t;
         }
       }
     }
    }

  void outputsort()
    {cout<<"Sorted Output is"<<endl;
     for(i=0;i<10;i++)
      cout<<num[i]<<endl;
    }
};
int main()
{Sort S1;
 int i,A[10];
 cout<<"Enter The Elements to be Sorted"<<endl;

 for(i=0;i<10;i++)
 {cin>>A[i];}

 for(i=0;i<10;i++)
  {S1.input(A[i]);}
 S1.sortinput();
 S1.outputsort();

 return 0;}
