#include <iostream>
#include <map>
#include <fstream>
#include <vector>

std::vector<int> parseInput(std::string input){
    std::ifstream file;
    std::string line;
    std::vector<int> containers;
    file.open(input);

    if(file.peek() == std::ifstream::traits_type::eof()){
        std::cerr << "Input file is empty! Have you got the right file path?";
    }else{
        while(getline(file,line)){
            containers.push_back(std::stoi(line));
        }
    }
    return containers;
}

int main() {
    std::string input_path = "/home/tomas/Documents/Advent-of-code/2015/17/input.txt";
    std::vector<int> containers = parseInput(input_path);

    


    return 0;
}
