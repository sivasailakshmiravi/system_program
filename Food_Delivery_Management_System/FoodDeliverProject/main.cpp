#include<iostream>
#include<unistd.h>
#include "Users.h"
#include "Menu.h"
#include "location.h"

int main()
{
   
	Users users;
	int loginOption=1;
	cout<<"Welcome to Online Food Ordering System"<<endl;
	cout<<"1. Login" << endl << "2. Sign Up "<<endl;
	cout<<"Select option: "<<endl;
	cin>>loginOption;
	switch(loginOption)
	{
		case 1:
			users.LoginWithRetrys();
			break;
		case 2:
			users.SignUp();
			users.LoginWithRetrys();
			break;
		default:
			cout<<"Invalid Option"<<endl;
			break;


	}
	if(users.LoginSuccess)
	{
		Location l;
		l.Location_transition();
		if(users.IsAdmin)
		{
			
			Menu m;
			m.AdminTransistion();
		
		}
		else
		{
			
		    Menu m;
		    m.UserTransistion();
		}
	}
	
	return 0;
	

}
