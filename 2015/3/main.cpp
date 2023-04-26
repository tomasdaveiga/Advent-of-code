#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int numHouses(const string& input){
    multimap<int, int> grid;
    pair<int, int> currentCell{0,0};
    bool newCell = true;
    grid.insert(currentCell);
    int result = 1;

    for (char i : input){
        if(i == '<'){ currentCell.second -=1;}
        else if(i == '>'){ currentCell.second +=1;}
        else if(i == 'v'){ currentCell.first -=1;}
        else if(i == '^'){ currentCell.first +=1;}

        for (auto & itr : grid){
            if(itr.first == currentCell.first && itr.second == currentCell.second) {
                newCell = false;
                break;
            }
        }
        if(newCell){
            grid.insert(currentCell);
            result +=1;
        }else {
            newCell = true;
        }
    }
    return result;
}

int roboSanta(string input){
    multimap<int, int> grid;
    pair<int, int> currentCellSanta{0,0};
    pair<int, int> currentCellRoboSanta{0,0};
    bool newCell = true;
    grid.insert(currentCellSanta);
    int result = 1;

    for (int i=0; i<input.length(); i++){
        if(input[i] == '<'){ i%2 == 0 ? currentCellSanta.second -=1 : currentCellRoboSanta.second -=1;}
        else if(input[i] == '>'){ i%2 == 0 ? currentCellSanta.second +=1 : currentCellRoboSanta.second +=1;}
        else if(input[i] == 'v'){ i%2 == 0 ? currentCellSanta.first -=1 : currentCellRoboSanta.first -=1;}
        else if(input[i] == '^'){ i%2 == 0 ? currentCellSanta.first +=1 : currentCellRoboSanta.first +=1;}

        for (auto & itr : grid){
            if((i%2 == 0 && itr.first == currentCellSanta.first && itr.second == currentCellSanta.second) || (i%2 != 0 && itr.first == currentCellRoboSanta.first && itr.second == currentCellRoboSanta.second)) {
                newCell = false;
                break;
            }
        }
        if(newCell){
            i%2 == 0 ? grid.insert(currentCellSanta) : grid.insert(currentCellRoboSanta);
            result +=1;
        }else {
            newCell = true;
        }
    }
    return result;
}


int main() {
    ifstream input_file;
    input_file.open("/home/tomas/CLionProjects/Advent-of-code/2015/3/input.txt");
    string input_str;
    getline(input_file, input_str);

    std::cout << "Number of houses with at least one present is " << numHouses(input_str) << std::endl;
    std::cout << "Number of houses with at least one present from Santa and RoboSanta is " << roboSanta(input_str) << std::endl;

    return 0;
}
