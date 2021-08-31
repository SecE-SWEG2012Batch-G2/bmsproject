int create_new_account_page()
{
 int age, phone;
 string sex;
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
 sex:
 accept("\t Enter your sex(F/M)   |  ", &(sex), 1);
 if (sex != 'F' || sex != 'M' || sex != 'f' || sex != 'm')
 {
  cout << "\t Please enter only 'F' or 'M' << endl;
  goto sex;
 }
 customer[customer_counter].sex = (char)sex[0];
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
accType:
 accept("\t Account type(1-4)     |  ", &acc_type, 1, 4);
 if (age > 18 && acc_type == 3)
 {
  cout << "You have to be under 18 to use this type." << endl
   << "Please select another account type!";
  goto accType;
 }
 if (age > 5 && acc_type == 2)
 {
  cout << "You have to be under 5 to use this type." << endl
   << "Please select another account type!";
  goto accType;
 }
 customer[customer_counter].acc_type = acc_type;
 password:
 accept("\t Set a strong password |  ", &(customer[customer_counter].password), 16);
 if (password.length() < 6 || password.length() > 8)
 {
  cout << "Set you password between 6 and 8 characters." << endl;
  goto password;
 }
 customer[customer_counter].acc_no = initial_acc_no++;
 accept("\t Enter initial amount  |  ", &balance, acc_types[customer[customer_counter].acc_type - 1].initial, 1000);
 customer[customer_counter].balance = balance;

 customer[user].transactions[customer[user].Index % 6].name = "Deposit";
 customer[user].transactions[customer[user].Index % 6].date = time(0);
 customer[user].transactions[customer[user].Index % 6].amount = balance;
 customer[user].Index++;

 user = customer_counter++;
 cout << "\t Account has been successfully created!" << endl <<
      "\t Press any key to proceed to your account: ";
 
 return 1;
}
