#include <iostream>
#include<string>
#include<cstdlib>// needed for exit()
#include<fstream> // essential for manipulating file stream objects
using namespace std;
void login();
void registr();
void forgot();

int main(){
int choice;
cout<<" ================= bank management system =============\n";
cout<<"============== LOGIN PAGE =========================\n";
cout<<"1.login\n";
cout<<"2.register\n";
cout<<"3.forget password \n";
cout<<"enter your choice\n";
cin>>choice;
if(!choice){
    cout<<"please! try to enter numbers 1-3.\n";
    exit(1)
    ;}
switch(choice)
   {
    case 1:
        login();
        break;
    case 2:
        registr();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout<<"Thanks for using our login page.\n";
        break;
    default:
        cout<<"wrong choice selected. \n";
        main();
   }

return 0;
}
void registr(){


 string reguser,regpass;
 system("cls");
 cout<<"Enter the username. :";
 cin>>reguser;
 cout<<"enter the password. :";
 cin>>regpass;
 ofstream reg("database.txt",ios::app);
 reg<<reguser<<' '<<regpass<<endl;
 system("cls");
 cout<<"registration is successfull.\n :";
 main();
}
void login(){
int cond;
string user,pass,u,p;
system("cls");
cout<<"enter the user name:";
cin>>user;
cout<<"Enter the password:";
cin>>pass;
ifstream input("database.txt");
while(input>>u>>p)
  {
    if(u==user && p== pass){
        cond=1;
    }
  }
input.close();
cout<<cond;
if(cond==1){
         cout<<"hello "<<user<<
       "\nwe're glad you are here.\n";
        cin.get();
        cin.get();
        main();
     }
   else{
    cout<<"sorry, login error.";
    cin.get();
    cin.get();
    main();
  }
}
void forgot(){
int cond;
string searchuser,su,sp;
system("cls");
cout<<"enter your remembered username :";
cin>>searchuser;
ifstream searchu("database.txt");
while(searchu>>su>>sp){
     if(su==searchuser){
        cond=1;
        break;
     }
  }
searchu.close();
    if(cond==1)
  {
    cout<<"your account has been found.\n";
    cout<<"your password is "<<sp;
    cin.get();
    cin.get();
    main();
  }
  else
    {
     cout<<"sorry, your account is found\n";
     cin.get();
     cin.get();
     main();
   }
}


