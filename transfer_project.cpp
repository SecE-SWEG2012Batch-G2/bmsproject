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
int transfer_page()
{
	int recipient_index = 0;
	string recname;
	int cash;
	system("cls");
	cout << endl;
accept:
	accept("     Enter recepient name: ", &recname, 20);
	for (int i = 0; i < customer_counter; i++)
	{
		if (customer[i].name == recname)
		{
			recepient_index = i;
			goto cash;
		}
	}
	cout << "     There is no customer named " << recname << "!" endl;
	cout << "     please Enter the name correctly." << endl;
	goto accept;
cash:
	accept("     Amount of momey: ", &cash, 50, (int)customer[user].balance - acc_types[customer[user].acc_type - 1].initial);
	//money for transfer is dependent on customers initial holdings in savings
	cout <<"     Enter 1 to confirm transfer to " << recname << " or another key to cancel: ";
	cin >> option;
	
	if (option == "1")
	{
		customer[recipient_index].balance += cash;  //money is added to the recepients unique index from senders balance
		customer[user].balance -= cash;  //money is removed from senders balance
		customer[user].transactions[customer[user].Index % 6].date = time(0);
		customer[user].transactions[customer[user].Index % 6].name = "Transfer";
		customer[user].transactions[customer[user].Index % 6].amount = -cash;
		customer[user].Index++;
		
		cout <<"     Enter any key to continue: ";
		cin >> option;
	}

	return 1;
}

int main() {
	transfer_page();
	return 0;
}
