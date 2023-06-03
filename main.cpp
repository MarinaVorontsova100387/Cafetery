#include <iostream>
#include <string>
#include <vector>

#include "ConsoleHelper.h"

using namespace std;

enum ProductType {Pizza, Drink};

struct Product {
    ProductType type;
    string name;
    double price;

    Product(ProductType type, const string &name, double price) : type(type), name(name), price(price) {}

};

struct Item {
    Product *product;
    int amount;

};

struct Order {
    vector<Item*> items;

    string Input (string message) {
        string input;
        cout << message << " : ";
        getline(cin, input);
        return input;
    }

    void AddProduct (Product* product, int amount) {
        auto* item = new Item();
        item->product = product;
        item->amount = amount;
        items.push_back(item);
    }
};






int main() {
    system("chcp 65001");

    vector<string> types;
    vector<string> names;
    vector<double> prices;

    string path = "C:\\Programming\\Cafetery\\Menu.txt";

    cout << endl;
    cout << "Добро пожаловать!" << endl;

    cout << endl;
    cout << "Ознакомьтесь с нашим меню : " << endl;
    cout << endl;

    ImportMenu(path, types,names, prices);
    PrintMenu(types,names, prices);

    cout << endl;

    Product* product;
    int amount;
    auto* order = new Order();
    bool exit = false;
    do {
        ShowActions();
        string input = Input("Укажите номер вашего действия");
        if (input =="1") {
            order->AddProduct(product,amount);
            cout << endl;
        } else if (input == "0") {
            exit = true;
        } else {
            cout << "Вы указали неправильный номер. Повторите ввод";
        }
    } while (!exit);










    return 0;
}
