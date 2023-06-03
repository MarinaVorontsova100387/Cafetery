#ifndef CAFETERY_PARSER_H
#define CAFETERY_PARSER_H

#include <string>

using namespace std;

string Parser(string& str, char delimiter) {
    int pos = str.find(delimiter);
    string result = str.substr(0,pos);
    str = str.substr(pos + 1);
    return result;
}

#endif //CAFETERY_PARSER_H
