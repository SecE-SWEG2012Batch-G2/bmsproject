#include <iostream>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <ctime>
using namespace std;

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
	time_t date;
	float amount;
};

struct Account {
	string name;
	unsigned int age;
	char sex;
	int phone;
	string city;
	unsigned int acc_type;
	string password;
	float balance;
	unsigned int Index = 0;
	unsigned long long int acc_no;
	Transaction transactions[6];
} customer[10];

int customer_counter = 0;
int user = 0;
int initial_acc_no = 10000000;
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

int sleep(float seconds)
{
	clock_t startClock = clock();
	float secondsAhead = seconds * CLOCKS_PER_SEC;
	while (clock() < startClock + secondsAhead);
	return 1;
}

int main()
{
	int option;
main_menu:
	system("cls");
	cout << endl;
	cout << setfill('=') << setw(44) << left << "        " << endl;
	cout << setfill(' ');
	cout << "                 WELCOME TO G5 BANK" << endl;
	cout << setfill('=') << setw(44) << left << "        " << endl;
	cout << setfill(' ');
	cout << "                    ::MAIN MENU::" << endl
		 << endl;
	cout << "        1. LOG IN" << endl
		 << "        2. CREATE NEW ACCOUNT" << endl
		 << "        3. EXIT" << endl
		 << endl;
	accept("        Enter option number(1-3): ", &option, 1, 3);

	switch (option)
	{
	case 1:
		if (login_page())
			goto account_home;
		else
			goto main_menu;
	case 2:
		if (create_new_account_page())
			goto account_home;
		else
			goto main_menu;
	default:
		return 0;
	}

account_home:
	system("cls");
	cout << endl;
	cout << setfill('=') << setw(31) << left << "     " << endl;
	cout << setfill(' ');
	cout << "          ACCOUNT HOMEPAGE" << endl
		 << endl
		 << "     NAME: " << customer[user].name << endl
		 << "     ACCOUNT NUMBER: " << customer[user].acc_no << endl
		 << "     BALANCE: " << customer[user].balance << endl;
	cout << setfill('=') << setw(30) << left << "     " << endl;
	cout << setfill(' ') << endl;

	cout << "     1. DEPOSIT" << endl;
	cout << "     2. WITHDRAW" << endl;
	cout << "     3. TRANSFER" << endl;
	cout << "     4. ACOUNT INFO" << endl;
	cout << "     5. DIACTIVATE ACCOUNT" << endl;
	cout << "     6. LOG OUT" << endl
		 << endl;

	accept("     Enter option number(1-6): ", &option, 1, 6);
	switch (option)
	{
	case 1:
		if (deposit_page() || true)
		{
			sleep(5);
			goto account_home;
		}
	case 2:
		if (withdraw_page() || true)
		{
			sleep(5);
			goto account_home;
		}
	case 3:
		if (transfer_page() || true)
			goto account_home;
	case 4:
		if (account_info_page() || true)
			goto account_home;
	case 5:
		if (deactivate_page())
			goto main_menu;
		else
			goto account_home;
	case 6:
		goto main_menu;
	}

	return 0;
}

//all functions below have to return 0 or 1
//that is the way it returns to the main() function
//not by calling it main();

int create_new_account_page(){
	return 1;
}
int login_page()
{
	//should return 1 if successfully logged in but 0 if failed
	return 1;
}
int account_info_page()
{
	return 1;
}
int withdraw_page()
{
	return 1;
}
int deposit_page()
{
	return 1;
}
int transfer_page()
{
	return 1;
}
int deactivate_page()
{
	//should return 1 if successfully diactivated or zero if cancelled
	return 1;
}
