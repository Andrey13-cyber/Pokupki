#include <iostream>
#include <windows.h>
#include "Product.h"
#include "Purchase.h"
#include "Check.h"

using namespace std;
void menu() {
    cout << "1. ������� ������ �������" << endl;
    cout << "2. ������� ������ �� ������ ��� ������� � �� ����������" << endl;
    cout << "3. ������� ������ �������" << endl;
    cout << "0.�����" << endl;
}

void printProd(vector<Product> &p) {

    for (int i = 0; i < p.size(); i++) {
        cout << i + 1 << " ";
        p[i].printList();
        
    }
    cout << endl;
        
}
void chooseProd(vector<Product>& p, vector<Purchase*>& check) {
    printProd(p);
    int number;
    int countOf;
    cout << "������� ����� ������ -> ";
    cin >> number;
    cout << endl;
    cout << "������� ���������� ������ -> ";
    cin >> countOf;
    cout << endl;
    Check* c = new Check(p[number - 1].getName(), countOf, p[number - 1].getPrice(), p[number - 1].getPrice() * countOf);
    check.push_back(c);
}

int main() {
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "����������,������������. �������� ������." << endl;
    cout << endl;

    menu();
    int step = 0;
    int selection;
    vector<Product> p;
    p.push_back(Product("��������", 91));
    p.push_back(Product("�������", 312.45));
    p.push_back(Product("��������", 23.5));
    p.push_back(Product("������������ ��������", 59.99));
    p.push_back(Product("�����-�������", 43));
    p.push_back(Product("�����-����", 32.99));
    p.push_back(Product("���������", 125.65));
    p.push_back(Product("�������������", 150));
    p.push_back(Product("������� ���������", 89.99));
    vector<Purchase*> check;
    int countOf;
    string name;
    double price = 0;
    Product a(name, price);

    while (!step) {
        cout << endl;
        cout << "������� ����� ����-> ";
        

        cin >> selection;
        cout << endl;
        switch (selection)
        {
        case 0:
            exit(0);
            cout << "����� �� ���������. �� ��������,������������ :)";
            break;


        case 1:
            printProd(p);
            break;

        case 2:
            chooseProd(p, check);
            break;
        case 3:
            for (int i = 0; i < check.size(); i++) {
                cout << i + 1 << " ";
                check[i]->printInfo();

            }
            break;
        }


    }
}