#include "Purchase.h"

Purchase::Purchase(const Purchase&b) {
	name = b.name;
	price = b.price;
	amountPrice = b.amountPrice;
	countOf = b.countOf;
	isNDS = b.isNDS;
}

Purchase::Purchase(string name, int countOf, double price, double amountPrice) {
	this->name = name;
	this->price = price;
	this->amountPrice = amountPrice;
	this->countOf = countOf;
	this->isNDS = false;
}

void Purchase::setName(string name) {
	this->name = name;
}

void Purchase::setPrice(double price) {
	this->price = price;
}

void Purchase::setAmount(double amountPrice) {
	this->amountPrice = amountPrice;
}

void Purchase::setCount(int count) {
	this->countOf = countOf;
}

string Purchase::getName() {
	return name;
}

double Purchase::getPrice() {
	return price;
}

double Purchase::getAmount() {
	return amountPrice;
}

int Purchase::getCount() {
	return countOf;
}

void Purchase::setNDS(bool ok) {
	this->isNDS = ok;
}

bool Purchase::getNDS() {
	return isNDS;
}

