#include "Product.h"

Product::Product(const Product& a) {
	name = a.name;
	price = a.price;
}

Product::Product(string name, double price) {
	this->name = name;
	this->price = price;
}


void Product::setName(string name){
	this->name = name;
}

void Product::setPrice(double price) {
	this->price = price;
}

string Product::getName(){
	return name;
}

double Product::getPrice() {
	return price;
}
void Product::printList() {
	cout << Product::getName() << endl;
	cout << Product::getPrice() << endl;
}


