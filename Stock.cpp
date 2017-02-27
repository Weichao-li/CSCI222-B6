#include "User.h"
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>
#include "Stock.h"

Stock::Stock()
{
}


Stock::Stock(int id ,string des,string cate,string subcate,float amt,int quant,int dd,string mm,int yy)
{
	itemid =id;
	itemdes = des;
	cat = cate;
	subcat = subcate;
	amount = amt;
	qty = quant;
	day = dd;
	month = mm;
	year = yy;
	

}

Stock::~Stock()
{
}



int Stock::getitemid()
{
	return itemid;
}

void Stock::setitemid(int id)
{
	itemid = id;
}

string Stock::getitemdes()
{
	return itemdes;
}

void Stock::setitemdes(string des)
{
	itemdes = des;
}
string Stock::getCat()
{
	return cat;
}

void Stock::setCat(string cate)
{
	cat = cate;
}
string Stock::getSubCat()
{
	return subcat;
}

void Stock::setSubCat(string subcate)
{
	subcat = subcate;
}
float Stock::getAmount()
{
	return amount;
}

void Stock::setAmount(float amt)
{
	amount = amt;
}
int Stock::getQty()
{
	return qty;
}

void Stock::setQty(int quant)
{
	qty = quant;
}
int Stock::getDay()
{
	return day;
}

void Stock::setDay(int dd)
{
	day = dd;
}
string Stock::getMonth()
{
	return month;
}

void Stock::setMonth(string mm)
{
	month = mm;
}
int Stock::getYear()
{
	return year;
}

void Stock::setYear(int yy)
{
	year = yy;
}
