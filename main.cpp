#include <iostream>
#include <windows.h>
#include "Product.h"
#include "Purchase.h"
#include "Check.h"

using namespace std;
void menu() {
    cout << "1. Вывести список товаров" << endl;
    cout << "2. Выбрать товары из списка для покупки и их количество" << endl;
    cout << "3. Вывести список покупок" << endl;
    cout << "4. Рассчитать НДС чека" << endl;
    cout << "0.Выход" << endl;
}

int errorProc(int minValue, int maxValue) {
    int place;
    while(1) {
        cin >> place;
        if (place < minValue || place > maxValue) {
            cout << "Некорректный ввод, введите еще раз -> ";
        }
        else
            return place;
    }

}


void printProd(vector<Product> &p) {

    for (int i = 0; i < p.size(); i++) {
        cout << i + 1 << " ";
        p[i].printList(); 
    }
    cout << endl;
        
}

void printCheck(vector<Purchase*>& check) {
    for (int i = 0; i < check.size(); i++) {
        cout << i + 1 << " ";
        check[i]->printInfo();

    }
}

void nds(vector<Purchase*> check) {
    for (int i = 0; i < check.size(); i++) {
        if (check[i]->getNDS() == false){
            check[i]->setAmount(check[i]->getAmount() * 1.2);
            check[i]->setNDS(true);
        } 
    }
    printCheck(check);
}

void chooseProd(vector<Product>& p, vector<Purchase*>& check) {
    printProd(p);
    int number;
    int countOf;
    cout << "Введите номер товара -> ";
    number = errorProc(1, INT32_MAX);
    cout << endl;
    cout << "Введите количество товара -> ";
    countOf = errorProc(1, INT32_MAX);
    cout << endl;
    Check* c = new Check(p[number - 1].getName(), countOf, p[number - 1].getPrice(), p[number - 1].getPrice() * countOf);
    check.push_back(c);
}

int main() {
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Здравствуй,пользователь. Начинаем работу." << endl;
    cout << endl;

    menu();
    int step = 0;
    int selection;
    vector<Product> p;
    p.push_back(Product("Смартфон", 91));
    p.push_back(Product("Ноутбук", 312.45));
    p.push_back(Product("Наушники", 23.5));
    p.push_back(Product("Беспроводные наушники", 59.99));
    p.push_back(Product("Робот-пылесос", 43));
    p.push_back(Product("Смарт-часы", 32.99));
    p.push_back(Product("Телевизор", 125.65));
    p.push_back(Product("Газонокосилка", 150));
    p.push_back(Product("Игровая приставка", 89.99));
    vector<Purchase*> check;
    int countOf;
    string name;
    double price = 0;
    Product a(name, price);

    while (!step) {
        cout << endl;
        cout << "Введите пункт меню-> ";
        selection = errorProc(0, 4);
        cout << endl;
        switch (selection)
        {
        case 0:
            exit(0);
            cout << "Выход из программы. До свидания,пользователь :)";
            break;

        case 1:
            printProd(p);
            break;

        case 2:
            chooseProd(p, check);
            break;

        case 3:
            cout << "Список выбранных покупок: " << endl;
            printCheck(check);
            break;

        case 4:
            cout << "Список покупок с расчетом НДС: " << endl;
            nds(check);
            break;
        }


    }
}