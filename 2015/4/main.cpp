#include <iostream>
#include <string>
#include "md5.h"

using namespace std;

int minHashNumber(const string& input){
    string result = md5(input);
    int counter = 0;
    while(result.substr(0,6) != "000000"){
        string line = input + to_string(++counter);
        result = md5(line);
    }
    return counter;
}

int main() {
    std::cout << "The min number is " << minHashNumber("bgvyzdsv") << std::endl;
    return 0;
}
