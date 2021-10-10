#include "Check.h"
void Check::printInfo() {

	cout << Purchase::getName() << endl;
	cout << "Цена за один товар - " << Purchase::getPrice() << endl;
	cout << "Количество товара - " << Purchase::getCount() << endl;
	cout << "Общая сумма - " <<Purchase::getAmount() << endl;

}

Check::Check(string name, int countOf, double price, double amountPrice) :Purchase(name, countOf, price, amountPrice) {}


