#include "User.h"
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>


User::User()
{
}


User::User(string user, string pass, string accType)
{
	username = user;
	password = pass;
	accountType = accType;
	loginAttempts = 0;
	isLocked = false;

}
User::~User()
{
}



string User::getUsername()
{
	return username;
}

void User::setUsername(string user)
{
	username = user;
}

string User::getPassword()
{
	return password;
}

void User::setPassword(string pass)
{
	password = pass;
}
string User::getAccountType()
{
	return accountType;
}

void User::setAccountType(string accType)
{
	accountType = accType;
}
int User::getloginAttemps()
{
	return loginAttempts;
}

bool User::getAccountStatus()
{
	return isLocked;
}




void User::Login(User aUser)
{
	string userName;
	string userPassword;
	char *password; // password string pointer
	while (1)
	{

		cout << "\n\n     Welcome to the Warehouse Management Tool!\n";
		cout << "  ----------------------------------------------";
		cout << " \n  Please enter your user name: ";
		cin >> userName;		 
    		password = getpass("  Please enter your password: "); // get a password
		cout <<endl<<endl;

   		//printf("%s\n",password); // this is just for conformation
   	                          // that password stored successfully

		if (aUser.getAccountStatus() == false)
		{
			if (userName == aUser.username && password == aUser.password)
			{
				
				aUser.loginAttempts = 0;
				
				if (aUser.accountType == "Manager")
				{
				displayMenu();
				}
				else
				{
				displayMenuAdmin();
				}
			}

			else
			{
				cout << "\n Invalid login attempt. Please try again.\n" << '\n';
				aUser.loginAttempts++;
				if (aUser.loginAttempts == 3)
				{
					cout << " Too many login attempts! Your account will now be locked.\n\n";
					aUser.isLocked = true;
				}
			}


		}
	}

		
	cout << " Thank you for logging in.\n";

}


void User::option1()
{
	
	//apstring name, dummy;
	string itemdes, cat, subcat;  
	int itemid, qty;   
	float amount;



	cout << "  Addition of New Stock\n";
	cout << " --------------------\n";
    

	do
	{
	cout << "Item ID: ";

	while(!(cin>>itemid) || (itemid < 0))
	{
		cin.clear();
 		cin.ignore(100,'\n');
		cout << "\nInvalid. Please try again!\n\n";
		cout << "Item ID: ";
	}
			

	} while(itemid < 0);

  
    cout << "Item Description: ";
    cin  >> itemdes;
	itemdes[0] = toupper(itemdes[0]);
    cout << "Item's Category: ";
    cin  >> cat;
	cat[0] = toupper(cat[0]);
    cout << "Item's Sub-Category: ";
    cin  >> subcat;
	subcat[0] = toupper(subcat[0]);

   
	
    do
	{
	cout << "Amount of Item (per unit): ";

	while(!(cin>>amount) || (amount < 0))
	{
		cin.clear();
		cin.ignore(100,'\n');
		cout << "\nInvalid. Please try again!\n\n";
		cout << "Amount of Item (per unit): ";
	}
			

	} while(amount < 0);


	
    do
	{
	cout << "Quantity of Item: ";

	while(!(cin>>qty) || (qty < 0))
	{
		cin.clear();
		cin.ignore(100,'\n');
		cout << "\nInvalid. Please try again!\n\n";
		cout << "Quantity of Item: ";
	}
			

	} while(qty < 0);


    cout << "\n\nSuccessfully added a New Stock!\n\n";
	cout << "Press any key to continue....";
	cin.ignore();
	cin.get();
	system("clear");
	
    ofstream myfile("database",  ios::out | ios::app);
    myfile.seekp( 0, ios_base::end );
    myfile << itemid<<":"<<itemdes<<":"<<cat<<":"<<subcat<<":"<<amount<<":"<<qty<<endl;
    myfile.close();

   

}

void User::option2()
{
}

void User::option3()
{
}

void User::option4()
{
}

void User::option5()
{
}

void User::option6()
{
}

void User::option7()
{
}

void User::option8()
{
}




void User::displayMenu()
{
	User user;
	int loopFlag = 1;
	int choice;
	do
	{
		//main menu where the program displays all the optionS//
		cout << "    Warehouse Management Tool" << endl;
		cout << " -------------------------------" << endl;
		cout << " 1) Add New Stock" << endl;
		cout << " 2) Remove Stock" << endl;
		cout << " 3) Edit Stock Item" << endl;
		cout << " 4) Search Stock Item" << endl;
		cout << " 5) Daily Stock Summary Report" << endl;
		cout << " 6) Weekly Stock Summary Report" << endl;
		cout << " 7) Montly Stock Summary Report" << endl;
		cout << " 8) Yearly Stock Summary Report" << endl;
		cout << " 9) Quit" << endl << endl;;
		cout << " Please enter your choice : ";

		cin >> choice; //user inputs the option he wishes to use//
		cout << endl;
		switch (choice)
		{
		case 1:
			user.option1();
			break;
		case 2:
			user.option2();
			break;
		case 3:
			user.option3();
			break;
		case 4:
			user.option4();
			break;
		case 5:
			user.option5();
			break;
		case 6:
			user.option6();
			break;
		case 7:
			user.option7();
			break;
		case 8:
			user.option8();
			break;
		case 9:
			cout << "Thank you for using Warehouse Management Tool!\n\n";
			
			exit(-1);
			break;
		default:
			cout << endl << "Incorrect Choice ! Please enter again!" << endl;//prompting user to key again if they key in values other than (1-5)
		}
	} while (loopFlag);
}



void User::displayMenuAdmin()
{
	User user;
	int loopFlag = 1;
	int choice;
	do
	{
		//main menu where the program displays all the optionS//
		cout << "    Warehouse Management Tool(Admin)" << endl;
		cout << " --------------------------------------" << endl;
		cout << " 1) Add User" << endl;
		cout << " 2) Remove User" << endl;
		cout << " 3) Unlock User" << endl;
		cout << " 4) Quit" << endl << endl;;
		cout << " Please enter your choice : ";

		cin >> choice; //user inputs the option he wishes to use//
		cout << endl;
		switch (choice)
		{
		case 1:
			user.option1();
			break;
		case 2:
			user.option2();
			break;
		case 3:
			user.option3();
			break;
		case 4:
			cout << "Thank you for using Warehouse Management Tool!\n\n";
			
			exit(-1);
			break;
		default:
			cout << endl << "Incorrect Choice ! Please enter again!" << endl;//prompting user to key again if they key in values other than (1-5)
		}
	} while (loopFlag);
}




/*void User::read() 
{
    std::ifstream file("authdata.txt");
    std::string fusername, fpassword, facctype;
 while (file) {
        std::getline(file, fusername, ';'); 
        std::getline(file, fpassword, ';'); 
	 std::getline(file, facctype);  
    }

}
*/
int main()
{
	//User.read();
	User aLoserJoel("joel", "hi", "Manager");
	aLoserJoel.Login(aLoserJoel);
}
