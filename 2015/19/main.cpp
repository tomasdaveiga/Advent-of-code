#include <iostream>
#include <fstream>
#include <unordered_map>

std::unordered_multimap<std::string, std::string> parseInput(std::string file_path, std::string& medicine){
    std::ifstream file;
    std::string line;
    std::unordered_multimap<std::string, std::string> replacements;
    file.open(file_path);

    if(file.peek() == std::ifstream::traits_type::eof()){
        std::cerr << "Input file is empty! Have you got the right file path?";
    }else{
        while(getline(file,line)){
            std::size_t arrow_pos = line.find(" => ");
            if (arrow_pos != std::string::npos){
                std::string key = line.substr(0, arrow_pos);
                std::string value = line.substr(arrow_pos+4);
                replacements.insert({key,value});
            }else{
                if (!line.empty()){
                    medicine = line;
                }
            }
        }
    }
    return replacements;
}


int main (){

    std::string input_path = "/home/tomas/Documents/Advent-of-code/2015/19/input.txt";
    std::string medicine;
    std::unordered_multimap<std::string, std::string> replacements = parseInput(input_path, medicine);

    // Next, we need to go one by one on the map, and see how many replacements you can make, store them 
    // in a vector for example. Then check every time we make a replacement if it's already in the vector
    // if it isn't, add it. If it is, don't add. In the end return length of vector.

    // Algorithm: grab first element of map, then do medicine.find( ), do medicine.replace()?, add result to
    // vector, then do medicine.find() but from the previous position onwards, do medicine.replace(), check if it's
    // different to the one already in the vector, if it is, add it, otherwise carry on

    return 0;
}

