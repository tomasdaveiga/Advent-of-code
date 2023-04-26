#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "lightGrid.h"

int main() {

    lightGrid grid(1000,1000);

    std::string input;
    std::ifstream file;
    file.open("/home/tomas/CLionProjects/Advent-of-code/2015/6/input.txt");

    while(getline(file, input)){
        // Parse the instructions
        long spaces = std::count(input.begin(), input.end(),' ');
        std::string action;
        if(spaces == 3){
            action = "toggle";
            input.erase(input.begin(), input.begin()+7);
        }else{
            if(input.find("off")==std::string::npos){
                action = "on";
                input.erase(input.begin(), input.begin()+8);
            }else{
                action = "off";
                input.erase(input.begin(), input.begin()+9);
            }
        }
        std::vector<int> coordinates;
        std::size_t comma = input.find(',');
        std::size_t space = input.find(' ');
        coordinates.push_back(std::stoi(input.substr(0,comma)));
        coordinates.push_back(std::stoi(input.substr(comma+1,space-1-comma)));
        input.erase(0,space+9);

        comma = input.find(',');
        coordinates.push_back(std::stoi(input.substr(0,comma)));
        coordinates.push_back(std::stoi(input.substr(comma+1, input.length()-comma-1)));

        grid.instructions1(coordinates, action);
//        grid.instructions2(coordinates, action);
    }
    std::cout << "Lights on: " << grid.numLightsOn() << std::endl;
    return 0;
}
