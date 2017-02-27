#include "User.h"
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include "Stock.h"
vector <User> UserList;
vector <User> ManagerList;
vector <Stock> StockList;


User user;

User::User()
{
}


User::User(string user, string pass, string accType,string accStat)
{
	username = user;
	password = pass;
	accountType = accType;
	
	loginAttempts = 0;
	accStatus = accStat;


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

string User::getAccountStatus()
{
	return accStatus;
}




void User::Login(User aUser)
{
	string userName;
	string userPassword;
	char *password; // password string pointer
	while (1)
	{


		cout << " Please enter your user name: ";
		cin >> userName;
		password = getpass("Enter Password: "); // get a password

												//printf("%s\n",password); // this is just for conformation
												// that password stored successfully


			if (aUser.authenticate(userName,password) == true)
			{
				cout << "\n\n Welcome to the Warehouse Management Tool!\n\n";
	
				for (int i = 0; i <ManagerList.size(); i++)
				{
					if (ManagerList[i].getUsername() == userName)
					 {
						if (ManagerList[i].getAccountStatus() == "N")
						displayMenu();
						else
						if (ManagerList[i].getAccountStatus() == "Y")
						cout << "Account Locked! Program Terminating" << endl;
						exit (0);
					 }
					
				
					else if (UserList[i].getUsername() == userName)
					{
						displayMenuAdmin();
					}
				}
			}

			else
			{	
				for (int i=0;i < ManagerList.size(); i++)
				{
					if (ManagerList[i].getUsername() == userName)
					{
						cout << "\n Invalid login attempt. Please try again.\n" << '\n';
						ManagerList[i].loginAttempts++;
					
						if (ManagerList[i].loginAttempts == 3)
						{
							cout << " Too many login attempts! Your account will now be locked.\n\n";
							ManagerList[i].isLocked == true;
						}
					}
	
				}
				
			}

	}
	

	cout << " Thank you for logging in.\n";

}


void User::option1()
{
	string itemdes, cat, subcat,month;  
	int itemid, qty,day,year;   
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

     
     do
	{
	cout << "Date (dd): ";

	while(!(cin>>day) || (day < 0))
	{
		cin.clear();
 		cin.ignore(100,'\n');
		cout << "\nInvalid. Please try again!\n\n";
		cout << "Date (dd): ";
	}
			

	} while(day < 0);

  
	cout << "Date (mmm): ";
	cin>>month;
	month[0] = toupper(month[0]);


     do
	{
	cout << "Date (yy): ";

	while(!(cin>>year) || (year < 0))
	{
		cin.clear();
 		cin.ignore(100,'\n');
		cout << "\nInvalid. Please try again!\n\n";
		cout << "Date (yy): ";
	}
			

	} while(year < 0);




    cout << "\n\nSuccessfully added a New Stock!\n\n";
	cout << "Press any key to continue....";
	cin.ignore();
	cin.get();
	system("clear");
	
    ofstream myfile("database",  ios::out | ios::app);
    myfile.seekp( 0, ios_base::end );
    myfile << itemid<<":"<<itemdes<<":"<<cat<<":"<<subcat<<":"<<amount<<":"<<qty<<":"<<day<<"-"<<month<<"-"<<year<<endl;
    myfile.close();

}

void User::option2()
{

       fstream file;//creating txt file
       file.open("database",ios::in); 
       int temp2 = 0;
       cout << "Data In Reading File" << endl;
       while (file) {
              string temp;
              getline(file, temp);
              ++temp2;
       }

       cout << endl;
       string *data = new string[temp2];
       temp2 = 0;
       file.close();
       file.open("database", ios::in);
       while (file) {
              string temp;
              getline(file, temp);
              cout <<temp2+1<<"  "<< temp << endl;
              data[temp2] = temp;
              temp2++;
       }
	temp2--;
       file.close();

       //writing data on file
	string data2;
	cout << "\nEnter Data that you want to delete: ";
	cin >> data2;  
	cout<<endl;     
	getline(file, data2,':');
       file.open("database", ios::out);
       for (int i = 0; i < temp2; i++) {
              if (data[i] != data2) {
                     file << data[i] << endl;
              }
       }
       file.close();

       //printing just data
       file.open("database", ios::in);
       temp2 = 0;
       while (file) {
              string temp;
              getline(file, temp);
              cout << temp2 + 1 << "  " << temp << endl;
              temp2++;
       }
temp2--;
}

void User::option3()
{
}

void User::option4()
{
string itemdes, cat, subcat,month;
    int itemid, qty,day,year,id;
    float amount;
string filename = "database";

ifstream dafi(filename.c_str());

if (dafi)
{
string search;
string line;

cout << "Enter the search criteria: ";
cin >> search;
cout<< endl;

while (getline(dafi, line))
{
if (line.find(search) != std::string::npos)
{
cout << line << endl<<endl;;
}
}
}
else
{
cerr << "Cannot open file " << filename << endl;
return ;
}

return ;

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

void User::AdminOption1()
{
	string newManagerName;
	string newManagerPassword;
	string confirmPassword;
	string lock = "N";



	cout << "  Adding New Manager\n";
	cout << " --------------------\n";
    

  
    cout << "Manager Username: ";
    cin  >> newManagerName;
    do
   {
    cout << "Manager Password: ";
    cin  >> newManagerPassword;
    cout << "Please enter password again: ";
    cin  >> confirmPassword;
   }
   while(newManagerPassword != confirmPassword);


    cout << "\n\nSuccessfully added a New Manager!\n\n";
	cout << "Press any key to continue....";
	cin.ignore();
	cin.get();
	system("clear");
	
    ofstream myfile("user.txt",  ios::out | ios::app);
    myfile.seekp( 0, ios_base::end );
    myfile << "Manager" <<";"<<newManagerName<<";"<<newManagerPassword<<";"<<lock<<endl;
    User Manager(newManagerName, newManagerPassword, "Manager", lock);
    ManagerList.push_back(Manager);
    myfile.close();
}

void User::AdminOption2()
{
	cout <<"Deleting Manager.." << endl;
	cout <<"------------------" << endl;
for (int i =0; i < ManagerList.size(); i++)
{
cout << i << "\t" << ManagerList[i].getUsername() << endl;
}
	cout << "Please enter number to delete: ";
	int input;
	cin >> input;
	if (input > 0)
	{
		cout << "Successfully deleted " << ManagerList[input].getUsername() << endl;
		ManagerList.erase(ManagerList.begin(), ManagerList.begin() + input);
		
		ofstream myfile("temp.txt",  ios::out);
		myfile.seekp( 0, ios_base::end );
	
		for(int j=0;j<ManagerList.size();j++)
		{
			myfile << "Manager" << ";" << ManagerList[j].getUsername()<< ";" << ManagerList[j].getPassword()<< ";" << "N" << endl;
		}
		   
	}
	if (input == 0)
	{
	cout << "Successfully deleted " << ManagerList[input].getUsername() << endl;
	ManagerList.erase(ManagerList.begin());
	
			ofstream myfile("temp.txt",  ios::out);
		myfile.seekp( 0, ios_base::end );
	
		for(int j=0;j<ManagerList.size();j++)
		{
			myfile << "Manager" << ";" << ManagerList[j].getUsername()<< ";" << ManagerList[j].getPassword()<< ";" << "N" << endl;
		}
	}
	
	
	
		
	
}

void User::AdminOption3()
{
	cout <<"Unlock Manager.." << endl;
	cout <<"------------------" << endl;
for (int k =0; k < ManagerList.size(); k++)
{
	if (ManagerList[k].getAccountStatus() == "Y")
	cout << k << "\t" << ManagerList[k].getUsername() << endl;
}
	cout << "Please enter number to unlock: ";
	int input;
	cin >> input;
	string unlock = "N";
	


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
	int loopFlag = 1;
	int choice;
	do
	{
		//main menu where the program displays all the optionS//
		cout << "    Warehouse Management Tool" << endl;
		cout << " -------------------------------" << endl;
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
			user.AdminOption1();
			break;
		case 2:
			user.AdminOption2();
			break;
		case 3:
			user.AdminOption3();
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



bool User::authenticate(const string &username, const string &password) {
    ifstream file("user.txt");
    string facctype,fusername, fpassword;
    string fislock;
	
	
    while (file) {
	getline(file, facctype, ';');
	if (facctype == "Admin")
	{
        getline(file, fusername, ';');
	getline(file, fpassword, ';');
	getline(file, fislock);
	User auser(fusername, fpassword, "Admin", fislock);
	UserList.push_back(auser);
	} 
   	else if (facctype == "Manager")
	{
	getline(file, fusername, ';');
	getline(file, fpassword, ';');
	getline(file, fislock);
	User Manager(fusername, fpassword, "Manager", fislock);
	ManagerList.push_back(Manager);
	}

    }
	for (int i=0; i<ManagerList.size(); i++)
	{
		if (ManagerList[i].getUsername() == username && ManagerList[i].getPassword() == password)
		{

            		return true;
		}

	}

	for (int i=0; i<UserList.size(); i++)
	{
				if (UserList[i].getUsername() == username && UserList[i].getPassword() == password)
		{

            		return true;
		}

	}
	return false;
}

void setAccountStatus(string a)
{
	
}

int main()
{

	user.Login(user);
}
