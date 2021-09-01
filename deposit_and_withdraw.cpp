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
	{"Sharia", 50, 0.0, 200000}};
struct Transaction
{
	string name;
	time_t date;
	float amount;
};

struct Account
{
	string name;
	unsigned int age, Index = 0;
	unsigned long long int acc_no;
	char sex;
	int phone;
	string city;
	unsigned int acc_type;
	Transaction transactions[6];
	string password;
	float balance;
} customer[10];

int customer_counter = 0;
int user = 0;
unsigned long long int initial_acc_no = 1000123456789;
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
		if (deposit_page())
			goto account_home;
	case 2:
		if (withdraw_page())
			goto account_home;
	/*case 3:
		if (transfer_page())
			goto account_home;
	case 4:
		if (account_info_page())
			goto account_home;
	case 5:
		if (deactivate_page())
			goto main_menu;
		else
			goto account_home;
			*/
	default:
		goto main_menu;
	}

	return 0;
}

int login_page()
{
	string name, password;
	int chance = 5;
	if (!customer_counter)
	{
		cout << "NO ACCOUNT TO LOG IN! ENTER 1 TO REGISTER: ";
		cin >> name;
		if (name == "1")
			return create_new_account_page();
		else
			return 0;
	}
	system("cls");
	cout << endl;
	do
	{
	login:
		accept("ENTER USER NAME: ", &name, 20);
		for (int i = 0; i < customer_counter; ++i)
		{
			if (customer[i].name == name)
			{
				user = i;
				accept("ENTER PASSWORD: ", &password, 8);
				if (password != customer[user].password)
				{
					cout << "INCORRECT PASSWORD!" << endl;
					cout << chance << " CHANCES LEFT." << endl;
					break;
				}
				return 1;
			}
			cout << "NO ACCOUNT FOUND! ENTER CORRECTLY" << endl;
			goto login;
		}
	} while (chance);
	cout << endl
		 << "SORRY SHUT DOWN";
	return 0;
}

int create_new_account_page()
{
	string name;
	int age, phone;
	string city;
	int acc_type;
	string password;
	int balance;

	system("cls");
	cout << endl;
	cout << setfill('=') << setw(50) << left << "         " << endl;
	cout << setfill(' ');
	cout << "         CREATE NEW ACCOUNT" << endl
		 << endl;
	cout << "         PLEASE FILL THE FOLLOWING FORM." << endl;

	accept("\t Enter your name       |  ", &(customer[customer_counter].name), 20);
	accept("\t Enter your age        |  ", &(age), 0, 100);
	customer[customer_counter].age = age;
	accept("\t Enter your phone      |  +251", &(phone), 900000000, 999999999);
	customer[customer_counter].phone = phone;
	accept("\t Enter your city       |  ", &(customer[customer_counter].city), 10);

	cout << endl;
	cout << "CHOOSE ACCOUT TYPE FROM THE FOLLOWING" << endl;
	cout << setfill('-') << setw(14 * 4 + 4) << "-" << endl;
	cout << setfill(' ');
	cout << setw(4) << left << "No.";
	cout << setw(14) << left << "Type";
	cout << setw(14) << left << "Initial";
	cout << setw(14) << left << "Interest";
	cout << setw(14) << left << "Max withdraw" << endl;
	cout << setfill('-') << setw(14 * 4 + 4) << "-" << endl;
	cout << setfill(' ');

	for (int i = 0; i < 4; ++i)
	{
		cout << setw(4) << left << i + 1;
		cout << setw(14) << left << acc_types[i].name;
		cout << setw(14) << left << acc_types[i].initial;
		cout << setw(14) << left << acc_types[i].interest;
		cout << setw(14) << left << acc_types[i].max_withdraw << endl;
	}
	cout << setfill('-') << setw(14 * 4 + 4) << "-" << endl;
	cout << setfill(' ');

	accept("\t Account type(1-4)     |  ", &acc_type, 1, 4);
	customer[customer_counter].acc_type = acc_type;
	accept("\t Set a strong password |  ", &(customer[customer_counter].password), 8);
	customer[customer_counter].acc_no = initial_acc_no++;
	accept("\t Enter initial amount  |  ", &balance, acc_types[customer[customer_counter].acc_type - 1].initial, 1000);
	customer[customer_counter].balance = balance;

	customer[user].transactions[customer[user].Index % 6].name = "Deposit";
	customer[user].transactions[customer[user].Index % 6].date = time(0);
	customer[user].transactions[customer[user].Index % 6].amount = balance;
	customer[user].Index++;

	user = customer_counter++;
	return 1;
}

int deposit_page()
{
	system("cls");
	cout << endl;
	cout << "\t DEPOSIT PAGE" << endl;
	cout << "\t ======================" << endl << endl;
	cout << "\n\t Your current balance is: " << customer[user].balance << endl;
	cout << "\t Enter the deposit amount: ";
	cin >> customer[user].transactions[customer[user].Index % 6].amount;

	customer[user].balance += customer[user].transactions[customer[user].Index % 6].amount;
	customer[user].transactions[customer[user].Index % 6].name = "Deposit";
	customer[user].Index++;

	customer[user].transactions[customer[user].Index].date = time(0);
	char *date_time = ctime(&customer[user].transactions[customer[user].Index].date);

	cout << "\n\t Deposit made successfully!" << endl;
	cout << "\t Transaction time: " << date_time << endl;
	cout << "\t Now your balance is: " << customer[user].balance << endl;
	cout << "\t Enter any key to continue... ";
	cin >> option;
	return 1;
}


int withdraw_page()
{
	int cash;
	system("cls");
	cout << "\t WITHDRAW PAGE" << endl;
	cout << "\t ========================" << endl;
	cout << "\n\t Your current balance is: " << customer[user].balance << endl;
	cout << "\t You can withdraw upto: " << (int)customer[user].balance - acc_types[customer[user].acc_type].initial << endl;

	accept("\t Enter the withdraw amount: ", &cash, 50, (int)customer[user].balance - acc_types[customer[user].acc_type].initial);
	customer[user].transactions[customer[user].Index % 6].amount = -cash;
	customer[user].balance -= cash;
	customer[user].transactions[customer[user].Index % 6].name = "Withdraw";
	customer[user].Index++;

	customer[user].transactions[customer[user].Index].date = time(0);
	char *date_time = ctime(&customer[user].transactions[customer[user].Index].date);
	cout << "\n\t Withdraw made successfully!" << endl;
	cout << "\t Now your balance is: " << customer[user].balance << endl;
	cout << "\t Transaction time: " << date_time << endl;
	cout << "\t Press any key to continue: ";
	cin >> option;

	return 1;
}

/*int account_info_page()
{
	system("cls");
	string owner;
	bool ownerNotFound;
	accept("Enter the name of the person your are looking for: ", &owner, 20);

	for (int i = 0; i < 10; i++)
	{
		if (customer[i].name == owner)
		{
			ownerNotFound = false;
			cout << "\nACCOUNT INFORMATION PAGE" << endl;
			cout << setfill('=') << setw(70) << "=" << endl;
			cout << setfill(' ');
			cout << "Customer Name: " << customer[i].name << endl;
			cout << "Account Number: " << customer[i].acc_no << endl;
			cout << "Remaining Balance: " << customer[i].balance << endl;
			cout << "Account Type: " << acc_types[(customer[i].acc_type - 1)].name << endl
				 << endl;

			cout << "RECENT TRANSACTIIONS" << endl;
			if (!customer[user].Index)
			{
				cout << "No Transactions Yet :( " << endl;
			}
			else
			{
				cout << setw(10) << left << "No.";
				cout << setw(20) << left << "Amount";
				cout << setw(20) << left << "Type";
				cout << setw(20) << left << "Date" << endl;
				cout << setfill('-') << setw(70) << "-" << endl;
				cout << setfill(' ');

				for (int j = customer[user].Index - 1; j > -1; j--)
				{
					cout << setw(10) << left << customer[user].Index - j;
					cout << setw(20) << left << customer[i].transactions[j % 6].amount;
					cout << setw(20) << left << customer[i].transactions[j % 6].name;
					cout << customer[i].transactions[j % 6].date.day << "/";
					cout << customer[i].transactions[j % 6].date.month << "/";
					cout << customer[i].transactions[j % 6].date.year << endl;
				}
				break;
			}
		}
		ownerNotFound = true;
	}

	if (ownerNotFound)
		cout << "Sorry! There is no account by this name!" << endl;

	cout << setfill('=') << setw(70) << "=" << endl;
	cout << setfill(' ');

	cout << "Press any key to continue: ";
	cin >> owner;

	return 1;
}

int transfer_page()
{
	int recipient_index = 0;
	string recname;
	int cash;

	system("cls");
	cout << endl;
	accept("     Enter recepient name: ", &recname, 20);
	for (int i = 0; i < customer_counter; i++)
	{
		if (customer[i].name == recname)
			goto cash;
	}
cash:
	accept("     Amount of momey: ", &cash, 50, (int)customer[user].balance - acc_types[customer[user].acc_type].initial);
	customer[recipient_index].balance += cash;
	customer[user].balance -= cash;
	customer[user].transactions[customer[user].Index % 6].date = date;
	customer[user].transactions[customer[user].Index % 6].name = "Transfer";
	customer[user].transactions[customer[user].Index % 6].amount = -cash;
	customer[user].Index++;

	cout <<"     Enter any key to continue: ";
	cin >> option;

	return 1;
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
*/
