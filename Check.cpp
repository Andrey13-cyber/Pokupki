#include "Check.h"
void Check::printInfo() {

	cout << Purchase::getName() << endl;
	cout << Purchase::getPrice() << endl;
	cout << Purchase::getCount() << endl;
	cout << Purchase::getAmount() << endl;

}

Check::Check(string name, int countOf, double price, double amountPrice) :Purchase(name, countOf, price, amountPrice) {}


