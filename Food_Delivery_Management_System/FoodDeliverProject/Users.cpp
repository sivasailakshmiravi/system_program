#include<iostream>
#include "Users.h"

#include<fstream>
#include<unistd.h>

using namespace std;


Users::Users()
{
	ifstream infile;
	infile.open("login.txt");
	int userNo=0;
	//cout<<"constructor called"<<endl;
	while(!infile.eof())
	{
	    User usr;
	    infile >>usr.UserName;
	    infile >>usr.Password;
	    int isadminflag=0;
	    infile>>isadminflag;
	    usr.IsAdmin= isadminflag>0 ? true:false;
	    users[userNo]=usr;
	    userNo++;
	    // cout<<usr.UserName<<endl;
	    // cout<<usr.Password<<endl;
	}
	infile.close();
	UsersCount=userNo;


}

bool Users::Login(string username,string password)
{
	bool isLogin=false;
	int userNo=0;
	for(userNo=0;userNo<UsersCount;userNo++)
	{
		if(users[userNo].UserName==username && users[userNo].Password == password)
		{
		 isLogin=true;
		 UserName=users[userNo].UserName;
		 IsAdmin= users[userNo].IsAdmin;
		 break;
		}

	}
	if(userNo==UsersCount)
		return false;
	return true;
}
void Users::SignUp()
{
	string username,password,address;
	string phonenumber;
        cout<<"Choose username"<<endl;
        cin>>username;
        cout<<"Choose password"<<endl;
        cin>>password;
	cout<<"Enter address"<<endl;
	cin>>address;
	cout<<"Enter phonenumber"<<endl;
	cin>>phonenumber;
	ofstream outfile;
        outfile.open("login.txt",ios::app);
	outfile<<"\n";
	outfile<<username;
	outfile<<"\t";
	outfile<<password;
	outfile<<"\t";
	outfile<<"0";
        outfile.close();
	User usr;
        usr.UserName=username;
        usr.Password=password;
	usr.IsAdmin=false;
	users[UsersCount]=usr;
        UsersCount++;
	cout<<"Sign Up successful"<<endl;
}

void Users::LoginWithRetrys()
{
	int retry=1;
        LoginSuccess=false;
        while(retry<=3){
        string username,password;
        cout<<"Please enter your login details"<<endl;
        cout<<"Enter Username"<<endl;
        cin>>username;
        cout<<"Enter password"<<endl;
        cin>>password;
        if(Login(username,password))
        {
                LoginSuccess=true;
                break;
        }
        cout<<"WARNING: Invalid password" << endl << "Please re-enter the password"<<endl;
        retry++;
        if(retry==4)
        {
                cout<<"Maximum retry limit reached" << endl << "Wait for 30 sec to retry"<<endl;
                sleep(30);
                retry=1;
        }
        }
        if(LoginSuccess)
        {
                if(IsAdmin)
          cout<<"Admin login successful with Username: "<<UserName<<endl;
                else
          cout<<"Login successful with Username: "<<UserName<<endl;

        }

}

