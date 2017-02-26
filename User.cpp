#include "User.h"



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
	char ch;
	while (1)
	{

	
		cout << " Please enter your user name: ";
		cin >> userName;
		cout << " Please enter your user password: ";
		ch = _getch();
	
		while (ch != 13) {//character 13 is enter
			userPassword.push_back(ch);
			cout << '*';
			ch = _getch();
			
		}

		if (aUser.getAccountStatus() == false)
		{
			if (userName == aUser.username && userPassword == aUser.password)
			{
				cout << "\n\n Welcome to the Warehouse Management Tool!\n\n";
				aUser.loginAttempts = 0;
				displayMenu();
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
	cout << "  New Book\n";
	cout << " -----------\n";

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


int main()
{
	User aLoserJoel("joel", "hi", "Manager");
	aLoserJoel.Login(aLoserJoel);
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
			system("pause");
			exit(-1);//allowing the user to quit the program//
			break;
		default:
			cout << endl << "Incorrect Choice ! Please enter again!" << endl;//prompting user to key again if they key in values other than (1-5)
		}
	} while (loopFlag);
}

