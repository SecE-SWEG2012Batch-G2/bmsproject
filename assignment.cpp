
#include <iostream>
#include <fstream>    //needed manipulating file stram objects
#include <string>
#include <cstdlib> //for exit()
#include <iomanip>
using namespace std;
struct customer
{
	int accpass_number;
	string name;
	char lastName[10];
	int password;
	float total_Balance;
};
void log_in()
{
	int i = 0;
	string name, fname;
	long pass, num;
	ifstream log;
	log.open("file.txt");
	if (log.fail())
	{
		cout << "the file was not successfully opened. " << endl;
		exit(1);
	}
	getline(log, fname, '#');//displays the records stored in the file
	log >> num;//read a record
	cout << "you have three chance of trial :";
	while (i < 3)
	{
		cout << "enter your username : "
			 << "your " << i + 1 << "trial. " << endl;
		cin>> name;
		cout << "enter your password:" << endl;
		cin >> pass;

		if (name == fname && pass == num)
		{
			cout << "you have logged in successfully";
			break;
		}
		else
		{
			cout << "try to enter your correct username and password. :";
		}
		i++;
	}
}
void registerf(customer c)
{
	ofstream registerf;
	registerf.open("file.txt");
	if (registerf.fail())//determine whether the file was opened
	{
		cout << "the file was not successfully opened. " << endl;
		exit(1);
	}
	cout << "\n enter your user name  .";
	cin>>c.name;

	cout << "\n enter your password.";
	cin >> c.accpass_number;//write the record

	registerf << c.name << "#" << c.accpass_number << endl;
	cout<<"your file is registered succesfully."<<endl<<"Enter 2 to continue";
} //end of registerf function

int main()
{
	int choice;

	struct customer c1;

	cout << "\n\n\n=============== Bank managmement system ==≠==============";
	cout << "\n\t welcome to our home page";
	cout << "\n1. register ";
	cout << "\n2.log in if you have an existing account ";
	cout << "\n3. exit " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		registerf(c1);//writes records to a sequential access file
		
		cin>>choice;
		system("cls");
		if (choice==2)
		log_in();
		 break;
   	case 2:
		log_in();
		break;
	case 3:
		exit(0);
		break;
	default:
		cout << "\n enter a correct choice ";
	}

		return 0; //end of main function 
	}
