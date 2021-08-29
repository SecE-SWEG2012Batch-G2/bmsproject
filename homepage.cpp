# include<iostream>
#include<iomanip>
using namespace std;
 struct customer
{

    int account_number;
    string firstName;
    char lastName[10];
    int password;
    float total_Balance;

};
   void log_in(customer p ){
   	int acct;
   	cout<<"\nEnter your account number: ";
   	cin>>acct;
   	if(acct==p.account_number)
   	cout<<"you have log_in sucsessfully "<<endl;
   	else{cout<<"invalid account num ";}
   }
int main()
{
 
customer user={10,"muhe"};
int choice;

cout<<"\n\n\n=============== Bank managmement system ==≠==============";
cout<<"\n\t welcome to our home page";
cout<<"\n1. log in ";
cout<<"\n2.create a new account ";
cout<<"\n3. exit "<<endl;
cin >>choice;
switch(choice){
	case 1: log_in(user);
	break;
	case 2: 
	break;
	case 3: exit(0);
	break;
	default:cout<<"\n enter a correct choice ";
}

return 0;
}