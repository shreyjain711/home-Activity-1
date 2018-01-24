

//////////////////////LIBRARY MANAGEMENT SYSTEM/////////////////////


#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <vector>

using namespace std;

void main_menu();

class book{

public:
    char book_name[40];
    char ISBN[20];  ///   ISBN CODE SHOULD BE OF 5 DIGITS
    char author[20];
    int total_copies;
    int no_of_copies_avail;
    bool is_avail;
    bool issued[100];
    time_t issue_arr[100];

public:
    book()
    {
        for(int i=0;i<100;i++){
        	issued[i]=false;
        }
        is_avail=false;
        total_copies=0;
        no_of_copies_avail=total_copies;
    }

    void create_book(){
        char c;
        cin.get(c);
		is_avail=true;
        cout<<"Enter the book name : ";
        cin.getline(book_name,40,'\n');
        cout<<"Enter the book ISBN code : ";
        cin.getline(ISBN,20,'\n');
        cout<<"Enter the author name : ";
        cin.getline(author,20,'\n');
        cout<<"Enter the total number of copies : ";
        cin>>total_copies;
        no_of_copies_avail=total_copies;
    }

    void display_book(){
        if(is_avail){
            cout<<"Book name : "<<book_name<<endl;
            cout<<"Book ISBN code : "<<ISBN<<endl;
            cout<<"Author's name : "<<author<<endl;
            cout<<"Total number of copies : "<<total_copies<<endl;
            cout<<"Number of copies available : "<<no_of_copies_avail<<endl;
            return;
        }
        else
            cout<<"BOOK NOT AVAILABLE"<<endl;
        return;
    }


    friend int copies_available();
    friend void book_search_name();
    friend void book_search_author();
    friend void book_search_ISBN();

};


class student{

public:
    char name[50];
    char roll_no[12]; /// ROLL NUMBER WILL BE OF 11 DIGITS LIKE 2016UCO1657
    char address[100];
    int contact_no;
    char email_id[50];
    int token;
    int fine;
    bool is_member;
    char student_password[6];
    char student_id[11];
    int issued_books[3];
    char bookissue[3][40];

public:
	student(){
		is_member=false;
		fine=0;
		token=0;
		for(int i=0;i<3;i++){
			issued_books[i]=-1;
			for(int j=0;j<40;j++)
				bookissue[i][j]='\0';
		}
	}

	void get_student_data(){
        char c;
        cin.get(c);
		cout<<"Enter name : ";
		cin.getline(name,50,'\n');
		cout<<"Enter roll_no : ";
		cin.getline(roll_no,12,'\n');
		cout<<"Enter address : ";
		gets(address);
		cout<<"Enter email_id : ";
		gets(email_id);
		cout<<"Enter contact_no : ";
		cin>>contact_no;
		token=0;
	}

	///CLASS FUNCTION TO DISPLAY STUDENT DATA

	void display_student(){
	    cout<<"STUDENT'S PROFILE"<<endl<<endl;
		cout<<"Name : "<<name<<endl;
		cout<<"Roll number : "<<roll_no<<endl;
		cout<<"Address : "<<address<<endl;
		cout<<"Email ID : "<<email_id<<endl;
		cout<<"Contact number : "<<contact_no<<endl;
		cout<<"Number of books issued : "<<token<<endl;
		//cout<<"Total fine : "<<fine<<endl;
		cout<<endl;
	}

	void student_menu();

};






book b;
student s;
//admin a;



///FUNCTION TO WRITE BOOK DATA ON FILE

void write_book_data(){

    fstream outbook;
    char choice;
    outbook.open("book.dat",ios::out|ios::app);
    if(!outbook)
        cout<<"File cannot be opened !! "<<endl;
    else {
        do{
            system("cls");
            b.create_book();
            outbook.write((char*)&b,sizeof(b));
            cout<<"Do you want to add more books ?(Y/N)"<<endl;
            cin>>choice;
        }while(choice=='y'||choice=='y');
   }
   outbook.close();
}



///FUNCTION TO WRITE STUDENT DATA ON FILE

void write_student_data()
{
    fstream outstud;
    char choice;
    outstud.open("student.dat",ios::out|ios::app);
    if(!outstud)
        cout<<"File cannot be opened ! "<<endl;
    else {
        do{
            system("cls");
            s.get_student_data();
            outstud.write((char*)&s,sizeof(s));
            cout<<"Do you want to add more students ? (Y/N)"<<endl;
            cin>>choice;
        }while(choice=='y' || choice=='Y');
    }
    outstud.close();
}


///FUNCTION TO SEARCH BOOK BY NAME

void book_search_name(){
	x:
	char n[40];
	bool found=false;
	char ch;
	cin.get(ch);
	cout<<"Enter book name : ";
	cin.getline(n,40,'\n');

	ifstream in;
	in.open("book.dat",ios::in);
	while(in.read((char* )&b,sizeof(b))){
		if(strcmp(b.book_name,n)==0){
            found=true;
			cout<<"\nBOOK FOUND!\n";
			b.display_book();
			cout<<endl;
			break;
		}
	}
	if(found==false)
        cout<<"\nBOOK NOT FOUND !"<<endl;
    in.close();
	char choice;
    cout<<"\nWould you like to search again? (Y/N)"<<endl;
    cin>>choice;
    if(choice=='Y' || choice=='y')
    {
        system("cls");
        goto x;
    }
    else{
        return;
	}
}


///SEARCH BOOK BY ISBN

void book_search_ISBN(){
	x:
	book b;
	char isbn[20];
	char c;
	cin.get(c);
	cout<<"Enter book ISBN : ";
	cin.getline(isbn,20,'\n');
    bool found=false;

	ifstream in;
	in.open("book.dat",ios::in);
	while(in.read((char*)&b,sizeof(b))){
		if(strcmp(b.ISBN,isbn)==0){
            found=true;
			cout<<"\nBOOK FOUND!\n";
			b.display_book();
            cout<<endl;
			break;
		}
	}
	if(found==false)
        cout<<"\nBOOK NOT FOUND !!!"<<endl;
    in.close();
	char ch;
	cout<<"\nWould you like to search again? (Y/N)\n";
	cin>>ch;
	if(ch=='Y' || ch=='y')
    {
        system("cls");
        goto x;
    }
    else
    {
        return;
    }
}

///SEARCH BOOK BY AUTHOR (DISPLAY BOOK BY TAKING AUTHOR'S NAME)

void book_search_author(){
	x:
	book b;
	char writer[20];
	char c;
	cin.get(c);
	cout<<"Enter author's name of the book to be searched : ";
	gets(writer);
    bool found=false;

	ifstream in;
	in.open("book.dat",ios::in);

	while(in.read((char*)&b,sizeof(b))){
		if(strcmp(b.author,writer)==0){
            found = true;
			cout<<"\nBook found!\n";
			b.display_book();
            cout<<endl;
			break;
		}
	}
	if(found==false)
        cout<<"\nBOOK NOT FOUND!!!"<<endl;
    in.close();
	char ch;
	cout<<"\nWould you like to search again? (Y/N)"<<endl;
	cin>>ch;
	if(ch=='Y' || ch=='y')
    {
        system("cls");
        goto x;
    }
    else {
        return;
    }
}

///FUNCTION TO SEARCH A STUDENT

void search_student(){
    x:
    fstream instud;
    instud.open("student.dat",ios::in);
    char rollno[12];
    char c;
    cin.get(c);
    cout<<"Enter the student's roll number : ";
    gets(rollno);
    bool found=false;
    while(instud.read((char*)&s,sizeof(s)))
    {
        if(strcmp(rollno,s.roll_no)==0)
        {
            s.display_student();
            found=true;
            break;
        }
    }
    if(found==false)
        cout<<"\nSTUDENT NOT FOUND!"<<endl;
    instud.close();
    char choice;
    cout<<"\nDo you want to search again? (Y/N)"<<endl;
    cin>>choice;
    if(choice=='y'||choice=='Y')
    {
        system("cls");
        goto x;
    }
    else{
        return;
    }

}

///FUNCTION TO DELETE A STUDENT

void delete_student()
{
    fstream instud,outstud;
    instud.open("student.dat",ios::in);
    outstud.open("tempstud.dat",ios::out|ios::app);
    x:
    system("cls");
    bool found=false;
    char confirm;
    char c;
    cin.get(c);
    char rollno[20];
    cout<<"Enter the ROLL NUMBER of student who will no longer be a member of THE LIBRARY : ";
    gets(rollno);
    while(instud.read((char*)&s,sizeof(s)))
    {
        if(strcmp(rollno,s.roll_no)==0)
        {
            found=true;
            s.display_student();
            cout<<"Are you sure you want to delete this student ? (Y/N)"<<endl;
            cin>>confirm;
            if(confirm=='n'||confirm=='N')
                outstud.write((char*)&s,sizeof(s));
        }
       else
           outstud.write((char*)&s,sizeof(s));
    }
    if(found==false)
        cout<<"Record not found !! \n";

    cout<<"Do you want to delete more students ?(Y/N)"<<endl;
    char choice;
    cin>>choice;
    if(choice=='y'||choice=='Y')
        goto x;
    else
        {
            instud.close();
            outstud.close();
            remove("student.dat");
            rename("tempstud.dat","student.dat");
    }
}

///FUNCTION TO DELETE A BOOK

void delete_book()
{
    system("cls");
    fstream inb,outb;
    inb.open("book.dat",ios::in);
    outb.open("tempbook.dat",ios::out|ios::app);
    x:
    system("cls");
    bool found=false;
    char confirm;
    char c;
    cin.get(c);
    char isbn[20];
    cout<<"Enter the ISBN code of the book to be deleted  : ";
    gets(isbn);
    while(inb.read((char*)&b,sizeof(b)))
    {
        if(strcmp(isbn,b.ISBN)==0)
        {
            found=true;
            b.display_book();
            cout<<"Are you sure you want to delete this book? (Y/N)";
            cin>>confirm;
            if(confirm=='n'||confirm=='N')
                outb.write((char*)&b,sizeof(b));
        }
       else
           outb.write((char*)&b,sizeof(b));
    }
    if(found==false)
        cout<<"Record not found !! \n";

    cout<<"\nDo you want to delete more books ? (Y/N)"<<endl;
    char choice;
    cin>>choice;
    if(choice=='y'||choice=='Y')
        goto x;
    else
        {
        inb.close();
        outb.close();
        remove("book.dat");
        rename("tempbook.dat","book.dat");
    }
}


///FUNCTION TO DISPLAY ALL BOOK DATA

void display_all_book(){
    fstream inf;
    inf.open("book.dat",ios::in);
    if(!inf)
    {
        cout<<"File cannot be opened !"<<endl;
        return;
    }
   // system("cls");
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"BOOK LIST :: "<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    int page;
    inf.read((char*)&b,sizeof(b));
    while(!inf.eof())
    {
        page=0;
        while(page<4 &&(!inf.eof()))
        {
            b.display_book();
            inf.read((char*)&b,sizeof(b));
            cout<<endl;
            page++;
        }
        cout<<"\nPress any key for next page...."<<endl;
        getch();
        system("cls");
    }

    inf.close();
    return;
}

///FUNCTION TO DISPLAY ALL STUDENT DATA

void display_all_student(){
    fstream inf;
    inf.open("student.dat",ios::in);
    if(!inf)
    {
        cout<<"File cannot be opened !"<<endl;
        return;
    }
   // system("cls");
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"STUDENT LIST :: "<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    int page;
    inf.read((char*)&s,sizeof(s));
    while(!inf.eof())
    {
        page=0;

        while(page<4 && (!inf.eof()))
        {
            s.display_student();
            inf.read((char*)&s,sizeof(s));
            cout<<endl;
            page++;
        }
        cout<<"Press any key for next page...."<<endl;
        getch();
        system("cls");
    }

    inf.close();
    return;
}


///MODIFY STUDENT

void modify_book(){
    system("cls");
    fstream inb,outb;
    inb.open("book.dat",ios::in);
    outb.open("tempbook.dat",ios::out);
    x:
    system("cls");
    bool b_found=false;
    char confirm;
    char c;
    cin.get(c);
    char isbn[20];
    cout<<"Enter the ISBN code of the book whose data is to be modified  : ";
    cin>>isbn;
    while(inb.read((char*)&b,sizeof(b)))
    {
        if((strlen(isbn)==strlen(b.ISBN)) && (strcmp(isbn,b.ISBN)==0))
        {
            b_found=true;
            b.display_book();
            cout<<"Are you sure you want to modify the data of this book? (Y/N)"<<endl;
            cin>>confirm;
            if(confirm=='n'||confirm=='N')
                outb.write((char*)&b,sizeof(b));
            else{
                b.create_book();
                outb.write((char*)&b,sizeof(b));
            }
        }
       else
           outb.write((char*)&b,sizeof(b));
    }

    if(b_found==false)
        cout<<"Book not found!!\n";

    cout<<"\nDo you want to modify the data of more books? (Y/N)"<<endl;
    char choice;
    cin>>choice;
    if(choice=='y'||choice=='Y')
        goto x;
    else
        {
        inb.close();
        outb.close();
        remove("book.dat");
        rename("tempbook.dat","book.dat");
    }
}

///MODIFY STUDENT

void modify_student(){
    system("cls");
    fstream ins,outs;
    ins.open("student.dat",ios::in);
    outs.open("tempstud.dat",ios::out);
    x:
    system("cls");
    bool s_found=false;
    char confirm;
    char c;
    cin.get(c);
    char rolln[12];
    cout<<"Enter the ROLL NUMBER of the student whose data is to be modified  : ";
    cin>>rolln;
    while(ins.read((char*)&s,sizeof(s)))
    {
        if((strlen(rolln)==strlen(s.roll_no)) && (strcmp(rolln,s.roll_no)==0))
        {
            s_found=true;
            s.display_student();
            cout<<"Are you sure you want to modify the data of this student? (Y/N)"<<endl;
            cin>>confirm;
            if(confirm=='n'||confirm=='N')
                outs.write((char*)&s,sizeof(s));
            else{
                s.get_student_data();
                outs.write((char*)&s,sizeof(s));
            }
        }
       else
           outs.write((char*)&s,sizeof(s));
    }

    if(s_found==false)
        cout<<"Student record does not exist!!\n";

    cout<<"\nDo you want to modify the data of more students? (Y/N)"<<endl;
    char choice;
    cin>>choice;
    if(choice=='y'||choice=='Y')
        goto x;
    else
        {
        ins.close();
        outs.close();
        remove("student.dat");
        rename("tempstud.dat","student.dat");
    }
}




///FUNCTION TO ISSUE BOOK

void book_issue(){
    system("cls");
	char r_no[12];
	bool st_found=false,b_found=false;
	char c;
	cin.get(c);
	cout<<"Input student's roll number : ";
	cin>>r_no;
    x:
	fstream in_stud("student.dat",ios::in|ios::out);
    fstream outtemp_stud("studtemp.dat",ios::out|ios::app);
	fstream in_book("book.dat",ios::in|ios::out);
    fstream outtemp_book("booktemp.dat",ios::out|ios::app);



	while(in_stud.read((char*)&s,sizeof(s))){
		if(strlen(s.roll_no)==strlen(r_no) && strcmp(s.roll_no,r_no)==0){
			st_found=true;
			if(s.token<3){
				cout<<"Input Book ISBN : ";
				char isbn[20];
				cin>>isbn;
				while(in_book.read((char*)&b,sizeof(b))){
					if(strlen(b.ISBN)==strlen(isbn) && strcmp(b.ISBN,isbn)==0){
						b.display_book();
						if(b.no_of_copies_avail==0){
							cout<<"Issuing not possible!";
                            outtemp_book.write((char*)&b,sizeof(b));
                            outtemp_stud.write((char*)&s,sizeof(s));
						}
                        else{
						    b_found=true;
						    s.token++;
						// unsigned long position = -1*sizeof(s);
						// unsigned long position2 = -1*sizeof(b);
						    int i;
						    for(i=0;b.issued[i]==true;)
							    i++;
						    b.issued[i]=true;
						    b.issue_arr[i]=time(0);
						    b.no_of_copies_avail--;

						    int j;
						    for(j=0;s.issued_books[j]!=-1;){
							   j++;
						    }
						    s.issued_books[j]=i;
						    strcpy(s.bookissue[j],b.book_name);

                            outtemp_book.write((char*)&b,sizeof(b));
                            outtemp_stud.write((char*)&s,sizeof(s));
						  // in_stud.seekp(tellg()+position);
						  // in_stud.write((char*)&s,sizeof(s));

						  // in_book.seekp(tellg()+position2);
						  // in_book.write((char*)&b,sizeof(b));
						    cout<<"Book issued ! \n\n\n";
						    b.display_book();
						    cout<<endl;
                        }
					}
                    else{
                          outtemp_book.write((char*)&b,sizeof(b));
                    }
				}
				if(!b_found){
                    cout<<"Book not found!"<<endl;
				}
			}
			else{
				cout<<"You cannot issue more than 3 books under your name. Kindly return the already issued books!!";
                //outtemp_book.write((char*)&b,sizeof(b));
                outtemp_stud.write((char*)&s,sizeof(s));
			}
		}
        else{
            outtemp_stud.write((char*)&s,sizeof(s));
        }
	}
	if(!st_found)
    {
        for(long long i=0;i<=600000;i++){}
        cout<<"Student is not a member of LIBRARY!"<<"\n\n\n";
        in_book.close();
        in_stud.close();
        outtemp_stud.close();
        outtemp_book.close();
        remove("student.dat");
        rename("studtemp.dat","student.dat");
        remove("booktemp.dat");

    }


    else
            {
                cout<<"Would you like to issue more books? (Y/N)"<<endl;
                char ch;
                cin>>ch;
                if(ch=='y' || ch=='Y')
                    {
                        in_book.close();
                        in_stud.close();
                        outtemp_stud.close();
                        outtemp_book.close();

                        remove("book.dat");
                        rename("booktemp.dat","book.dat");

                        remove("student.dat");
                        rename("studtemp.dat","student.dat");
                        goto x;

            }
                else{
                    in_book.close();
                    in_stud.close();
                    outtemp_stud.close();
                    outtemp_book.close();

                    remove("book.dat");
                    rename("booktemp.dat","book.dat");

                    remove("student.dat");
                    rename("studtemp.dat","student.dat");
                }
            }


}

void book_deposit(){
    x:
	char r_no[12];
	char c;
	bool st_found=false;
	cin.get(c);
	cout<<"Input student's roll number : ";
	cin>>r_no;
	fstream in_stud("student.dat",ios::in|ios::out);
    fstream outtemp_stud("studtemp.dat",ios::out|ios::app);
	fstream in_book("book.dat",ios::in|ios::out);
    fstream outtemp_book("booktemp.dat",ios::out|ios::app);

	while(in_stud.read((char*)&s,sizeof(s))){
		if(strlen(s.roll_no)==strlen(r_no) && strcmp(s.roll_no,r_no)==0){
            char ch;
            cin.get(ch);
            st_found=true;
			cout<<"Input Book Name to be returned : ";
			char bookn[40];
			cin.getline(bookn,40,'\n');
			for(int i=0;i<3;i++){
				if(strlen(s.bookissue[i])==strlen(bookn) && strcmp(s.bookissue[i],bookn)==0){
					s.token--;
					// unsigned long position = -1*sizeof(s);
					// unsigned long position2 = -1*sizeof(b);

					// s.bookissue[i]={'\0'};
					for(int k=0;k<40;k++)
						s.bookissue[i][k]='\0';


                    while(in_book.read((char*)&b,sizeof(b))){
                        // b.issued[s.issued_books[i]]=false;
                        if(strlen(b.book_name)==strlen(bookn) && strcmp(b.book_name,bookn)==0){
                            b.issued[s.issued_books[i]]=false;
                            b.no_of_copies_avail++;

                            outtemp_book.write((char*)&b,sizeof(b));
                        }
                        else{
                            outtemp_book.write((char*)&b,sizeof(b));
                        }
                    }

					if((difftime(time(0),b.issue_arr[s.issued_books[i]]))/(86400)>15)
						s.fine=(difftime(time(0),b.issue_arr[s.issued_books[i]]))/(86400);

					s.issued_books[i]=-1;
                    outtemp_stud.write((char*)&s,sizeof(s));


					// in_stud.seekp(tellg()+position);
					// in_stud.write((char*)&s,sizeof(s));

					// in_book.seekp(tellg()+position2);
					// in_book.write((char*)&b,sizeof(b));
                    cout<<"Book deposited !"<<endl;
					break;
				}
			}
		}
        else{
            outtemp_stud.write((char*)&s,sizeof(s));
        }
	}
	if(!st_found)
    {
        cout<<"Wrong roll number entered !! Try again?(Y/N)\n";
        char choice;
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {
            in_book.close();
            in_stud.close();
            outtemp_stud.close();
            outtemp_book.close();

            remove("booktemp.dat");

            remove("student.dat");
            rename("studtemp.dat","student.dat");
            goto x;
        }
        else
            return;
        in_book.close();
    }
    else{
        in_book.close();
        in_stud.close();
        outtemp_stud.close();
        outtemp_book.close();

        remove("book.dat");
        rename("booktemp.dat","book.dat");

        remove("student.dat");
        rename("studtemp.dat","student.dat");
        cout<<"Would you like to deposit more books? (Y/N)"<<endl;
        char ch;
        cin>>ch;
        if(ch=='y' || ch=='Y')
            goto x;
        else{
            return;
        }
    }

}

///CLASS ADMIN CONTAINS PASSWORD FUNCTION AND ADMIN MENU

class admin{

private:
    char password[5]={'r','i','y','a','\0'};

public:


    ///FUNCTION FOR ADMIN MENU
    void admin_menu(){
        system("cls");
        cout<<"ADMINISTRATOR'S MENU : \n\n\n";
        cout<<"1. LOGIN\n2. CHANGE PASSWORD\n3. RETURN TO MAIN MENU \n\n\n"
            <<"Choose course of action : ";
        int i;
        cin>>i;
        char ch;
        //system("cls");
        switch(i){
        case 1 :login();
                break;
        case 2 :change_pwd();
                cout<<"Would you like to login? (Y/N)\n";
                cin>>ch;
                if(ch=='Y' || ch=='y')
                    login();
                else
                    break;
                break;
        case 3:main_menu() ;
        default :main_menu();
            }
    }


    ///CHANGES PASSWORD

    void change_pwd(){
        char p[5];
        char ch;
        x:
        cout<<"Input old password after screen goes blank : ";
        for(long long k=0;k<80000000;k++){}
        system("cls");
        int i;
        for(i=0;ch!=13;){
            ch=getch();
            if(ch!=13 && ch!=8){
                cout<<"*";
                p[i++]=ch;
            }
            else if(ch==8){
                i--;
                system("cls");
                for(int j=1;j<=i;j++)
                    cout<<"*";
            }
        }
        p[i]='\0';
            if((strcmp(p,password)==0) && (strlen(p)==strlen(password))){
                char newp[5];
                cout<<"Input new password : ";
                cin>>newp;
                strcpy(password,newp);
            }
            else{
                cout<<"Wrong password!! \n"
                    <<"Try again? (Y/N)\n";
                char c;
                cin>>c;
                if(c=='Y' || c=='y')
                    goto x;
                else
                    return;
            }
        }



        ///LOGIN
        void login(){
            char p[5];
            z:
            system("cls");
            cout<<"Input password after screen goes blank : ";
            for(long long i=0;i<80000000;i++){}
            system("cls");
            int i;
            char ch='\0';
            for(i=0;ch!=13;){
                ch=getch();
                if(ch!=13 && ch!=8){
                    cout<<"*";
                    p[i++]=ch;
                }
                else if(ch==8){
                    i--;
                    system("cls");
                    for(int j=1;j<=i;j++)
                        cout<<"*";
                }
            p[i]='\0';
            }
            if(strcmp(p,password)==0){
                system("cls");
                cout<<":: LOGGED IN ::\n\n";
                x:
                    cout<<"1. SEE BOOK LIST\n2. SEE STUDENT LIST\n3. ADD NEW BOOK TO DIRECTORY\n4. REMOVE BOOK FROM DIRECTORY\n"
                    <<"5. ADD NEW STUDENT TO DIRECTORY\n6. REMOVE STUDENT FROM DIRECTORY\n7. MODIFY BOOK IN DIRECTORY\n8. MODIFY STUDENT'S DATA IN DIRECTORY\n"
                    <<"9. ISSUE BOOK TO A STUDENT\n10. DEPOSIT BOOK IN DIRECTORY\n11. EXIT \n\n\n";
                cout<<"Choose course of action : ";
                int choice;
                cin>>choice;
                char ch;
                switch(choice){
                case 1 :	system("cls");
                            display_all_book();
                            admin_menu();
                            break;
                case 2 :	system("cls");
                            display_all_student();
                            admin_menu();
                            break;
                case 3 :	write_book_data();
                            admin_menu();
                            break;
                case 4 :	delete_book();
                            admin_menu();
                            break;
                case 5 :	write_student_data();
                            admin_menu();
                            break;
                case 6 :	delete_student();
                            admin_menu();
                            break;
                case 7 :	modify_book();
                            admin_menu();
                            break;
                case 8 :	modify_student();
                            admin_menu();
                            break;
                case 9 :	book_issue();
                            admin_menu();
                            break;
                case 10 :	book_deposit();
                            admin_menu();
                            break;
                case 11 :	cout<<"LOGGED OUT!\n\n";
                            system("cls");
                            admin_menu();
                            break;
                default :	cout<<"Course of action not approved. Try again? (Y/N)\n";
                            cin>>ch;
                            if(ch=='Y' || ch=='y'){
                                system("cls");
                                goto x;
                            }
                            else
                                break;
                               // return;
                }
            }
            else{
                cout<<"Login not approved! Do you want to try again? (Y/N)\n";
                cin>>ch;
                if(ch=='Y' || ch=='y'){
                    system("cls");
                    goto z;
                }
                else
                    return;
            }
            return;
    }

};
admin a;

void student::student_menu()
    {
        cout<<endl;
        cout<<"1. BROWSE THROUGH ALL BOOKS \n2. SEARCH A BOOK BY NAME \n3. SEARCH A BOOK BY AUTHOR'S NAME\n4. EXIT\n\n\n"<<endl;
        int choice;
        cout<<"Choose course of action : "<<endl;
        cin>>choice;
        switch(choice){
            case 1: system("cls");
                    display_all_book();
                    main_menu();
                    break;
            case 2: system("cls");
                    book_search_name();
                    main_menu();
                    break;
            case 3: system("cls");
                    book_search_author();
                    main_menu();
                    break;
            case 4: main_menu();
            default:cout<<"WRONG CHOICE ENTERED !!";
                    main_menu();
        }
    }

void main_menu()
{
    system("cls");
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                                             WELCOME TO ONLINE PORTAL OF THE LIBRARY :D "<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    int choice ;
    cout<<"\n1. ADMINISTRATOR'S MENU  \n2. STUDENT'S MENU \n3. EXIT\n\n\n";
    cout<<"Choose course of action : ";
    cin>>choice;
        system("cls");
        switch(choice){
        case 1:cout<<"WELCOME TO ADMINISTRATOR'S PORTAL "<<endl;
               a.admin_menu();
               break;
        case 2:cout<<"WELCOME TO STUDENT'S PORTAL "<<endl;
               s.student_menu();
               break;
        case 3:break ;

    }
}

int main()
{
    main_menu();
    return 0;
}

