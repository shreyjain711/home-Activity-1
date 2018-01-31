#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

class card
{private:
   char title[20],auther[20];
   int copies;
 public:
   void store(char pname[],char qname[],int n)
    {strcpy(title,pname);
     strcpy(auther,qname);
     copies=n;
    }
   void show()
    {cout<<"The Title of Book is "<<title<<endl;
     cout<<"The Auther of Book is "<<auther<<endl;
     cout<<"The Number of Copies of Book is "<<copies<<endl;

    }
};

int main()
{card B1,B2;

 int C;
 char A[20],B[20],D[20];

cout<<"Enter the Title of Book"<<endl;
scanf("%[^\n]s",A);
strcpy(D,A);
fflush(stdin);
cout<<"Enter the Auther of the Book"<<endl;
scanf("%[^\n]s",B);
cout<<"Enter the Number of Copies of the Book"<<endl;
cin>>C;

 B1.store(D,B,C);
 B2.store("The Wings of Fire","APJ Abdul Kalam",5);

 B1.show();
 B2.show();

 return 0;
}
