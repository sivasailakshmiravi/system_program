#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "location.h"

using namespace std;

//Function to display available locations
void Location::display_location() {
    ifstream INFile("location.txt");
    string line;
    string location;
    
    
    while(! INFile.eof())
    {
        getline(INFile, line);
        stringstream(line) >> location;
        cout << line << endl;
    }
    INFile.close();
}

//function to verify entered location
bool Location::get_location(string user_location){
    user_location[0] = toupper(user_location[0]);
    ifstream INFile("location.txt");
    string to_find;
    bool exists = false;
    transform(user_location.begin(), user_location.end(), user_location.begin(), ::tolower);
    while (getline(INFile,to_find)) {
	    transform(to_find.begin(), to_find.end(), to_find.begin(), ::tolower);
	if(to_find == "- "+user_location)
	{
            exists = true;
            break;
        }
    }
    if (exists) {
      cout << "Displaying available Restaurants in " << user_location << endl; 
    }
    else{
        cout << "Please enter valid Location" << endl;
    }
 return exists;
}

//function to display the available Restaurants
void Location::restaurant_list(string appended_user_location) {
    ifstream INFile_hotel_list(appended_user_location);
    string hotel_list;
    string list_of_hotels;
    if (!INFile_hotel_list){
       // cout << "Please enter valid Location" << endl;
        return display_location();
    }
    while(! INFile_hotel_list.eof())
    {
        getline(INFile_hotel_list, hotel_list);
        stringstream(hotel_list) >> list_of_hotels;
        cout << hotel_list << endl;
    }
    INFile_hotel_list.close();
    
}

bool Location::get_restaurants(string appended_user_location) {
    
    ifstream INFile_hotel_list(appended_user_location);
    if (!INFile_hotel_list){
    //cout << "Please enter valid Location" << endl;
    return false;
    }
    else if(INFile_hotel_list){
    string restaurant_no;
    cout << endl << "Select your Hotel number: ";
    cin >> restaurant_no;
    int line_number = stoi(restaurant_no);
    int read_lines = 0;
    string line;
     
        
           while (getline(INFile_hotel_list, line)){
	    
            read_lines++;
            if(read_lines == line_number)
            {
                cout << line << endl;
                break;
            }
        }
        INFile_hotel_list.close();
        if (read_lines < line_number) {
            cout << "Invalid Entry" << endl;
            return false;
        }
     

    }
    return true;
}

int Location::Location_transition()
{
	while(true) 
	{
	   cout << "---We are availble in the following Locations--- "<<endl;
	   display_location();
	   string user_location;
    
    	   cout << "Enter Your Location: ";
           cin >> user_location;
    
           transform(user_location.begin(), user_location.end(), user_location.begin(), ::tolower);
   
   	if (get_location(user_location)){
    		string appended_user_location;
    		appended_user_location=user_location.append("_hotels.txt");
    
    		restaurant_list(appended_user_location); 
    		while(!get_restaurants(appended_user_location));
    		break;
   		}
	}     
    return 0;
}
