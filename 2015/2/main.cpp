#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int totalWrappingPaper(vector<vector<int>> input){
    int result = 0;
    for (auto & i : input){
        result +=3*i[0]*i[1] + 2*i[0]*i[2]+ 2*i[1]*i[2];
    }
    return result;
}

int totalRibbon (vector<vector<int>> input){
    int result = 0;
    for (auto & i : input){
        result += 2*i[0] + 2*i[1] + i[0]*i[1]*i[2];
    }

    return result;
}

int main() {

    // Read input:
    //  Input comes in txt file with each dimension separated by 'x'
    //      Organise input into 2D vector where each row is one present, and each column is a dimension (sorted by value).

    ifstream file;
    file.open("/home/tomas/CLionProjects/Advent-of-code/2015/2/input.txt");
    string line;
    vector<vector<int>> input;
    while(getline(file,line)){
        vector<int> line_vec;

        // Find the first X
        size_t x_pos = line.find('x');
        line_vec.push_back(stoi(line.substr(0, x_pos)));
        line.erase(0, x_pos+1);

        // Find the second X
        x_pos = line.find('x');
        line_vec.push_back(stoi(line.substr(0,x_pos)));
        line_vec.push_back(stoi(line.substr(x_pos+1)));

        // Sort from smallest to largest
        sort(line_vec.begin(), line_vec.end());
        input.push_back(line_vec);
    }
    std::cout << "Total amount of wrapping paper: " << totalWrappingPaper(input) << std::endl;
    std::cout << "Total amount of ribbon: " << totalRibbon(input) << std::endl;
    return 0;
}
