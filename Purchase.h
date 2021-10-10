#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Purchase
{
private:
	string name;
	int countOf;
	double price;
	double amountPrice;
	bool isNDS;

public:
	Purchase(const Purchase&);
	Purchase(string name, int countOf, double price, double amountPrice);
	string getName();
	void setName(string name);
	double getPrice();
	void setPrice(double price);
	int getCount();
	void setCount(int countOf);
	double getAmount();
	void setAmount(double amountPrice);
	virtual void printInfo() = 0;
	void setNDS(bool ok);
	bool getNDS();
};

