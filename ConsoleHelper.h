#ifndef CAFETERY_CONSOLEHELPER_H
#define CAFETERY_CONSOLEHELPER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Parser.h"

using namespace std;

void ImportMenu (string path, vector<string>& types, vector<string>& names, vector<double>& prices) {
    ifstream menu;
    menu.open(path);
    string line;
    while(getline(menu, line)){
        types.push_back(Parser(line, '_'));
        names.push_back(Parser(line, '_'));
        prices.push_back(stoi(line));
    }
    menu.close();
}

void PrintMenu_ (string& type, string& name, double& price) {
    cout << type << " : " << name << " - " << price << endl;
}

void PrintMenu (vector<string>& types, vector<string>& names, vector<double>& prices) {
    for (int i = 0; i < names.size(); ++i) {
        PrintMenu_(types[i],names[i], prices[i]);
    }
}

string Input (string message) {
    string input;
    cout << message << " : ";
    getline(cin, input);
    return input;
}

void ShowActions() {
    cout << "---Что вы хотите сделать?---" << endl;
    cout << "1. Добавить заказ" << endl;
    cout << "0. Выход" << endl;
}



#endif //CAFETERY_CONSOLEHELPER_H
