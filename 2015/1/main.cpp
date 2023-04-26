#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int finalFloor(const string& s){
    int floor = 0;
    for (char i : s){
        i=='(' ? floor+=1 : floor-=1;

        if(floor<0){
            std::cout << "basement at position: " << i+1 << std::endl;
        }
    }
    return floor;
}

int BasementIndex (const string& s){
    int floor = 0;
    int idx = 1;
    for (int i=0; i<s.length(); i++){
        s[i]=='(' ? floor+=1 : floor-=1;

        if(floor<0){
            idx = i+1;
            break;
        }
    }
    return idx;
}

int main() {
    ifstream input_file;
    input_file.open("/home/tomas/CLionProjects/Advent-of-code/2015/1/input.txt");
    string input_str;
    getline(input_file, input_str);
    std::cout << "Santa goes to floor " << BasementIndex(input_str) << std::endl;
    return 0;
}
