#include "Function.h"
#include <iostream>
#include <sstream>

using namespace std;

float inputFloat(float& f) {
    string temp;
    while (true) {
        cin >> temp;
        if (isFloat(temp)) {
            if (stof(temp) < 0 || stof(temp) > 100000) {
                throw (-1);
                continue;
            }
            break;
        }
        else {
            cin.get();
            throw (-2);
            break;
        }
    }
    return f = stof(temp);
}

bool isFloat(const std::string& input) {
    std::istringstream stream(input);
    float f;
    if (!(stream >> f)) {
        return false;
    }
    return stream.eof();
}
