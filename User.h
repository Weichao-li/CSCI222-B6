#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

class User
{
private:
	string username;
	string password;
	string accountType;
	int loginAttempts;
	bool isLocked;



public:
	User();
	User(string, string, string);
	~User();
	void Login(User );
	string getUsername();
	void setUsername(string);
	string getPassword();
	void setPassword(string);
	string getAccountType();
	void setAccountType(string);
	int getloginAttemps();
	bool getAccountStatus();
	void option1();
	void option2();
	void option3();
	void option4();
	void option5();
	void option6();
	void option7();
	void option8();
	void displayMenu();
};

