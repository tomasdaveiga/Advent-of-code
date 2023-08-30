#include <iostream>
#include <fstream>
#include "jsoncpp-master/dist/json/json.h"

void checkJSONsum(Json::Value root, int &sum, bool careRed){
    // Check the type of Value
    bool hasRed = false;
    if(root.isObject()){
        if(careRed) {
            for (const auto &i: root.getMemberNames()) {
                if ((i == "red" || root[i] == "red")) {
                    hasRed = true;
                    break;
                }
            }
        }
        if(!hasRed){
            for(const auto& i: root.getMemberNames()) {
                checkJSONsum(root[i], sum, careRed);
            }
        }
    }
    if(root.isArray()){
        for (const auto& i:root){
            if(i.isNumeric()){sum+= i.asInt();}
            else{checkJSONsum(i, sum, careRed);}
        }

    }
    if(root.isNumeric()) sum+= root.asInt();
}

int main() {
    std::ifstream file;
    file.open("/home/tomas/Documents/Advent-of-code/2015/12/input.txt");
    std::string line;

    Json::Reader reader;
    Json::Value root;
    int sumA = 0;
    int sumB = 0;

    while(getline(file,line)){
        bool parseSucess = reader.parse(line, root, false);
        if (parseSucess){
            checkJSONsum(root, sumA, false);
            checkJSONsum(root, sumB, true);
         }
    }
    std::cout << "A Sum is " << sumA << std::endl;
    std::cout << "B Sum is " << sumB << std::endl;
    return 0;
}
