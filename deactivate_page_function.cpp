#include <iostream>
#include <cstring>
#include <string.h>
#include <iomanip>

using namespace std;

struct Date
{
	unsigned int day, month, year;
};

struct Acc_type
{
	char name[10];
	int initial;
	float interest;
	int max_withdraw;
};

Acc_type acc_types[4] = {
	{"Saving", 50, 0.08, 200000},
	{"Children", 200, 0.12, 1000},
	{"Education", 200, 0.1, 500},
	{"Sharia", 50, 0.0, 200000}
};

struct Transaction
{
	string name;
	Date date;
	float amount;
};

Date date = {20, 12, 2013};

struct Account
{
	string name;
	unsigned int age, Index = 0;
	unsigned long long int acc_no;
    int phone;
	string city;
	//char e_mail[20];
	unsigned int acc_type;
	Transaction transactions[6];
	string password;
	float balance;
} customer[10];

int customer_counter = 0, user = 0;
long int initial_acc_no = 1000123456789, *Index;
string option;

int deposit_page();
int withdraw_page();
int transfer_page();
int deactivate_page();
int create_new_account_page();
int login_page();
int account_info_page();

void accept(string message, int *value, int min, int max)
{
accept:
	cout << message;
	cin >> *value;
	if (!cin || *value > max || *value < min)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input! Try again." << endl;
		goto accept;
	}
}

void accept(string message, string *value, int len)
{
accept:
	cout << message;
	cin >> *value;
	if ((*value).length() > len)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input! Try again." << endl;
		goto accept;
	}
}
int deactivate_page()
{
	string decision;
	int newIndex = 0;
	accept("Do you really want to deactivate your account?(y/n) ", &decision, 3);
	if (decision == "y")
	{
		for (int i = 0; i < customer_counter; i++)
		{
			if (i != user)
			{
				customer[newIndex] = customer[i];
				++newIndex;
			}
		}
		return 1;
	}
	return 0;
}

int main() 
{
deactivate_page();
    return 0;
}
