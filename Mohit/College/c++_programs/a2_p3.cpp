#include<iostream>
#include<string.h>

using namespace std;

class Student
{private:
    int B,i=0,L=100,H=0,Hno,Lno;
    char Namae[20];
 public:
  int name(char pname[])
   {strcpy(Namae,pname);}

  int marks(int marks)
    {B=marks;}

  int marksout()
    {return B;}

  void show()
   {cout<<Namae<<" "<<B<<endl;}

};


int main()
{Student S[10];

 int i,B,h,l,H=0,L=100,j;
 char A[20];

 for(i=0;i<10;i++)
  {cout<<"Enter the name of Student"<<endl;
   cin>>A;
   cout<<"Enter the marks of Student"<<endl;
   cin>>B;
    S[i].name(A);
    S[i].marks(B);
  }

 for(i=0;i<10;i++)
  {if(S[i].marksout()>H)
    {H=S[i].marksout();
    h=i;}
  }


 for(j=0;j<10;j++)
  {if(S[j].marksout()<L)
    {L=S[j].marksout();
     l=j;}
  }

 cout<<"The Highest scorer in test is "<<endl;
 S[h].show();
 cout<<"The Lowest scorer in test is "<<endl;
 S[l].show();

return 0;

}

