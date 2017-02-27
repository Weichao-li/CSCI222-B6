#ifndef USER_H_
#define USER_H_
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include "Stock.h"
using namespace std;

class User : public Stock
{
private:
	string username;
	string password;
	string accountType;
	string accStatus;
	int loginAttempts;
	bool isLocked;



public:
	User();
	User(string, string, string, string);
	~User();
	void Login(User );
	string getUsername();
	void setUsername(string);
	string getPassword();
	void setPassword(string);
	string getAccountType();
	void setAccountType(string);
	int getloginAttemps();
	string getAccountStatus();
	void setAccountStatus();
	void option1();
	void option2();
	void option3();
	void option4();
	void option5();
	void option6();
	void option7();
	void option8();
	void displayMenu();
	void displayMenuAdmin();
	void read();
	void AdminOption1();
	void AdminOption2();
	void AdminOption3();
	bool authenticate(const string &username, const string &password);
	friend bool operator==(User &user, string &accType)
	{
	return (user.getAccountType() == accType);
	}

};
#endif

