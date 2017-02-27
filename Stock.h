#ifndef STOCK_H_
#define STOCK_H_


#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Stock
{
private:
	string itemdes, cat, subcat,month;  
	int itemid, qty,day,year;   
	float amount;


public:
	Stock();

	Stock(int,string,string,string,float,int,int,string,int);

	~Stock();

	int getitemid();
	void setitemid(int);

	string getitemdes();
	void setitemdes(string);

	string getCat();
	void setCat(string);

	string getSubCat();
	void setSubCat(string);

	float getAmount();
	void setAmount(float);

	int getQty();
	void setQty(int);

	int getDay();
	void setDay(int);

	string getMonth();
	void setMonth(string);

	int getYear();
	void setYear(int);

};
#endif

