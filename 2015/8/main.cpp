#include <iostream>
#include <fstream>

int main() {
    std::ifstream file;
    file.open("/home/tomas/CLionProjects/Advent-of-code/2015/8/input.txt");

    std::string str_line;
    int str_code = 0, str_memory = 0, str_enconder = 0;
    while(getline(file, str_line)){
        int str_memory_line = (int)str_line.length(), str_memory_enconder = (int)str_line.length();
        str_code += (int)str_line.length();

        for (int i = 0; i<str_line.length(); i++){
            if(str_line[i] == ' ' || str_line[i] == '"') {str_memory_line -=1; str_memory_enconder+=1;}
            if(str_line[i] == '\\'){
                if(str_line[i+1] == 'x') str_memory_line -=3;
                else if(str_line[i+1] == '\\') {str_memory_line -=1; str_memory_enconder+=1; i++;}
                str_memory_enconder+=1;
            }
        }
        str_memory += str_memory_line;
        str_enconder += str_memory_enconder+2;
    }
    file.close();

    std::cout << "Part A: " << std::to_string(str_code-str_memory)<< std::endl;
    std::cout << "Part B: " << std::to_string(str_enconder - str_code) << std::endl;
    return 0;
}