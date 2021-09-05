// BANK MANAGEMENT SYSTEM
// Group Members:
// 1. Michael Gashaw
// 2. Minase Driba
// 3. Minase Fikadu
// 4. Mohammed Yezid
// 5. Nathan Lijalem

#include <iostream>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <cctype>

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

struct Account
{
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

int customer_counter = 0, user = 0;
long int initial_acc_no = 1000123456789, *Index;
string option;

int login_page();
int create_new_account_page();
int deposit_page();
int withdraw_page();
int transfer_page();
int account_info_page();
int deactivate_page();

void accept(string message, int *value, int min, int max)
{
accept:
	cout << message;
	cin >> *value;
	if (!cin || *value > max || *value < min)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\tInvalid input! Try again." << endl;
		goto accept;
	}
}

void accept(string message, string *value, int len)
{
accept:
	cout << message;
	cin.ignore();
	getline(cin, *value);
	if ((*value).length() > len)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\tInvalid input! Try again." << endl;
		goto accept;
	}
}

int main()
{
	int option;
main_menu:
	system("clear");
	cout << endl;
	cout << setfill('=') << setw(44) << left << "\t\t" << endl;
	cout << setfill(' ');
	cout << "\t\t\t    WELCOME TO G2 BANK" << endl;
	cout << setfill('=') << setw(44) << left << "\t\t" << endl;
	cout << setfill(' ');
	cout << "\t\t\t     ::MAIN MENU::" << endl
		 << endl;
	cout << "\t\t1. LOG IN" << endl
		 << "\t\t2. CREATE NEW ACCOUNT" << endl
		 << "\t\t3. EXIT" << endl
		 << endl;
	accept("\t\tEnter option number(1-3): ", &option, 1, 3);

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
	system("clear");
	cout << endl;
	cout << setfill('=') << setw(31) << left << "     " << endl;
	cout << setfill(' ');
	cout << "\tACCOUNT HOMEPAGE" << endl
		 << endl
		 << "\tNAME: " << customer[user].name << endl
		 << "\tACCOUNT NUMBER: " << customer[user].acc_no << endl
		 << "\tBALANCE: " << customer[user].balance << endl;
	cout << setfill('=') << setw(30) << left << "     " << endl;
	cout << setfill(' ') << endl;

	cout << "\t1. DEPOSIT" << endl;
	cout << "\t2. WITHDRAW" << endl;
	cout << "\t3. TRANSFER" << endl;
	cout << "\t4. ACOUNT INFO" << endl;
	cout << "\t5. DEACTIVATE ACCOUNT" << endl;
	cout << "\t6. LOG OUT" << endl << endl;

	accept("\tEnter option number(1-6): ", &option, 1, 6);
	switch (option)
	{
	case 1:
		if (deposit_page())
			goto account_home;
	case 2:
		if (withdraw_page())
			goto account_home;
	case 3:
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
	case 6:
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
		cout << "\tNO ACCOUNT TO LOG IN!\n\tENTER 1 TO REGISTER: ";
		cin >> name;
		if (name == "1")
			return create_new_account_page();
		else
			return 1;
	}

	system("clear");
	cout << endl;
	login:
		accept("\tENTER USER NAME: ", &name, 20);

		for (int i = 0; i < customer_counter; ++i)
		{
			if (customer[i].name.compare(name) >= 0)
			{
				user = i;
			countChance:
				cout << "\tENTER PASSWORD: "; cin >> password;
				if (customer[user].password != password)
				{
					--chance;
					cout << "\tINCORRECT PASSWORD!" << endl;
					cout << "\t" << chance << " CHANCES LEFT." << endl;
					cout << "\tpassword you entered: " << password << endl;
					cout << "\tpassword of user is: " << customer[user].password << endl;

					if (!chance)
						break;
					goto countChance;
				}
				return 1;
			}
			cout << "\tNO ACCOUNT FOUND!\n\tENTER CORRECTLY!" << endl;
			goto login;
		}
	cout << "\n\t\tSORRY SHUTTING DOWN";
	return 0;
}

int create_new_account_page()
{
	string name;
	int age, phone;
	string city, sex;
	int acc_type;
	string password;
	int balance;

	system("clear");
	cout << endl;
	cout << "\t\t CREATE NEW ACCOUNT" << endl << endl;
	cout << setfill('=') << setw(50) << left << "         " << endl;
	cout << setfill(' ');
	cout << "\t\t PLEASE FILL THE FOLLOWING FORM." << endl;

	accept("\t Enter your name       |  ", &(customer[customer_counter].name), 30);
	accept("\t Enter your age        |  ", &(age), 0, 100);
	customer[customer_counter].age = age;
	accept("\t Enter your phone      |  +251", &(phone), 900000000, 999999999);
	accept("\t Enter your sex(f/m)   |  ", &(sex), 3);
	customer[customer_counter].sex = toupper(sex[0]);
	customer[customer_counter].phone = phone;
	accept("\t Enter your city       |  ", &(customer[customer_counter].city), 10);

	cout << endl;
	cout << "\tCHOOSE ACCOUT TYPE FROM THE FOLLOWING" << endl;
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

	accept("\tAccount type(1-4)     |  ", &acc_type, 1, 4);
	customer[customer_counter].acc_type = acc_type;
	accept("\tEnter initial amount  |  ", &balance, acc_types[customer[customer_counter].acc_type - 1].initial, 1000);
	customer[customer_counter].balance = balance;
	accept("\tSet a strong password |  ", &(customer[customer_counter].password), 50);

	customer[customer_counter].acc_no = initial_acc_no++;

	customer[user].transactions[customer[user].Index % 6].name = "Deposit";
	customer[user].transactions[customer[user].Index % 6].amount = balance;
	customer[user].transactions[customer[user].Index % 6].date = time(0);
	customer[user].Index++;

	user = customer_counter++;

	return 1;
}

int withdraw_page()
{
	int cash;
	system("clear");
	cout << "\tWITHDRAW PAGE" << endl;
	cout << "\t========================" << endl;
	cout << "\n\tYour current balance is: " << customer[user].balance << endl;
	cout << "\tYou can withdraw upto: " << (int)customer[user].balance - acc_types[customer[user].acc_type].initial << endl;

	accept("\tEnter the withdraw amount: ", &cash, 50, (int)customer[user].balance - acc_types[customer[user].acc_type].initial);
	customer[user].transactions[customer[user].Index % 6].amount = -cash;
	customer[user].balance -= cash;
	customer[user].transactions[customer[user].Index % 6].name = "Withdraw";
	customer[user].Index++;
	
	customer[user].transactions[customer[user].Index % 6].date = time(0);

	cout << "\n\tWithdraw made successfully!" << endl;
	cout << "\tNow your balance is: " << customer[user].balance << endl;
	cout << "\tTransaction time: " << ctime(&customer[user].transactions[customer[user].Index % 6].date) << endl;
	cout << "\tPress any key to continue: ";
	cin >> option;
	
	return 1;
}

int transfer_page()
{
	int recipient_Index = 0;
	string recname;
	int cash;
	system("clear");
	cout << endl;

accept:
	accept("\tEnter recepient account number:  1000", &recname, 20);
	for (int i = 0; i < customer_counter; i++)
	{
		if (customer[i].name == recname)
		{
			recipient_Index = i;
			goto cash;
		}
	}
	cout << "\tThere is no customer by this name!\n";
	cout << "\tplease enter correctly." << endl;
	goto accept;

cash:
	accept("\tAmount of momey: ", &cash, 50, (int)customer[user].balance - acc_types[customer[user].acc_type].initial);

	cout <<"\tEnter 1 to confirm transfer to " << customer[recipient_Index].name << " or another key to cancel: ";
	cin >> option;

	if (option == "1")
	{
		customer[recipient_Index].balance += cash;  //money is added to the recepients unique index from senders balance
		customer[user].balance -= cash;  //money is removed from senders balance
		customer[user].transactions[customer[user].Index % 6].date = time(0);
		customer[user].transactions[customer[user].Index % 6].name = "Transfer";
		customer[user].transactions[customer[user].Index % 6].amount = -cash;
		customer[user].balance -= cash;
		customer[user].Index++;

	}

	cout << "\n\tTransfered successfully!";
	cout << "\n\tTransaction time: " << ctime(&customer[user].transactions[customer[user].Index % 6].date);
	cout << "\n\tNow your balance is: " << customer[user].balance << endl;

	cout << "\tEnter any key to continue: ";
	cin >> option;

	return 1;
}

int account_info_page()
{
	system("clear");
	string owner;
	bool ownerNotFound;

	cout << "\t\t\tList of Customers\n\t";
	cout << setw(5) << left << "No";
	cout << setw(20) << left << "Name";
	cout << setw(5) << left << "Sex";
	cout << setw(20) << left << "Account No" << endl;
	cout << '\t' << setfill('-') << setw(50) << "-" << endl;
	cout << setfill(' ');

	for (int j = 0; j < customer_counter; j++)
	{
		cout << '\t';
		cout << setw(5) << j+1;
		cout << setw(20) << left << customer[j].name;
		cout << setw(5) << left << customer[j].sex;
		cout << setw(20) << left << customer[j].acc_no << endl;
		cout << '\t' << setfill('-') << setw(50) << "-" << endl;
		cout << setfill(' ');
	}

	accept("\tThe person you are looking for: ", &owner, 20);

	for (int i = 0; i < 10; i++)
	{
		if (customer[i].name.compare(owner) >= 0)
		{
			ownerNotFound = false;
			cout << "\n\tACCOUNT INFORMATION PAGE\n\t";
			cout << setfill('=') << setw(75) << "=" << endl;
			cout << setfill(' ');
			cout << "\tCustomer Name: " << customer[i].name << endl;
			cout << "\tAccount Number: " << customer[i].acc_no << endl;
			cout << "\tRemaining Balance: " << customer[i].balance << endl;
			cout << "\tAccount Type: " << acc_types[(customer[i].acc_type - 1)].name << endl << endl;

			cout << "\tRECENT TRANSACTIIONS" << endl;
			if (!customer[user].Index)
				cout << "\tNo Transactions Yet :( " << endl;
			else
			{
				cout << setw(10) << left << "\tNo.";
				cout << setw(20) << left << "Amount";
				cout << setw(20) << left << "Type";
				cout << setw(20) << left << "Date" << endl;
				cout << setfill(' ');

				cout << '\t' << setfill('-') << setw(75) << "-" << endl;
				cout << setfill(' ');

				for (int j = customer[user].Index - 1; j > -1; j--)
				{
					cout << '\t' << setw(10) << left << customer[user].Index - j;
					cout << setw(20) << left << customer[i].transactions[j % 6].amount;
					cout << setw(20) << left << customer[i].transactions[j % 6].name;
					cout << setw(25) << left << ctime(&customer[user].transactions[customer[user].Index % 6].date) << endl;
				}
			}
			break;
		}
		ownerNotFound = true;
	}

	if (ownerNotFound)
		cout << "\tSorry! There is no account by this name!" << endl;

	cout << '\t' << setfill('=') << setw(75) << "=" << endl;
	cout << setfill(' ');

	cout << "\tPress any key to continue: ";
	cin >> owner;

	return 1;
}

int deposit_page()
{
	system("clear");
	cout << endl;
	cout << "\tDEPOSIT PAGE" << endl;
	cout << "\t======================" << endl << endl;
	cout << "\tYour current balance is: " << customer[user].balance << endl;
	cout << "\tEnter the deposit amount: ";
	cin >> customer[user].transactions[customer[user].Index % 6].amount;

	customer[user].balance += customer[user].transactions[customer[user].Index % 6].amount;
	customer[user].transactions[customer[user].Index % 6].name = "Deposit";
	customer[user].Index++;

	customer[user].transactions[customer[user].Index % 6].date = time(0);

	cout << "\n\tDeposit made successfully!" << endl;
	cout << "\tNow your balance is: " << customer[user].balance << endl;
	cout << "\tTransaction time: " << ctime(&customer[user].transactions[customer[user].Index % 6].date) << endl;
	cout << "\tPress any key and enter to continue: ";
	cin >> option;

	return 1;
}

int deactivate_page()
{
	string decision;
	int newIndex = 0;
	accept("\tDo you really want to deactivate your account?(y/n) ", &decision, 3);
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
		customer[customer_counter-1] = {};
		customer_counter--;
		cout << "\tYou successfully deactivated your account." << endl;
		cout << "\tEnter any key to proceed to main menu: ";
		cin >> option;

		return 1;
	}
	else
	{
		cout << "\tOpeartion cancelled returning to Home" << endl;
		return 0;
	}			
}
