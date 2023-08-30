#include <iostream>
#include <string>
#include "md5.h"

using namespace std;

int minHashNumber(const string& input, const string startKey){
    string result = md5(input);
    int counter = 0;
    while(result.substr(0,startKey.length()) != startKey){
        string line = input + to_string(++counter);
        result = md5(line);
    }
    return counter;
}

int main() {
    std::cout << "Starting with 00000, the min number is " << minHashNumber("yzbqklnj","00000") << std::endl;
    std::cout << "Starting with 000000, the min number is " << minHashNumber("yzbqklnj","000000") << std::endl;
    return 0;
}
