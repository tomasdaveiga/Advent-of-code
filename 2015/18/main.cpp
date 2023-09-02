#include <iostream>
#include <fstream>
#include <vector>

class lightGrid{
public:
    lightGrid(std::vector<std::vector<bool>> initState, int initLightsOn, int initLightsOff);
    void updateState();
    void updateStateCorners();
    int getNumLightsOn(){return numLightsOn;};

private:
    std::vector<std::vector<bool>> grid;
    int numLightsOn;
    int numLightsOff;
};

lightGrid::lightGrid(std::vector<std::vector<bool>> initState, int initLightsOn, int initLightsOff){
    grid = initState;
    numLightsOn = initLightsOn;
    numLightsOff = initLightsOff;
}

void lightGrid::updateState(){
    std::vector<std::vector<bool>> newState;
    int newLightsOn = 0, newLightsOff = 0;
    for (size_t i = 0; i<grid.size(); i++){
        std::vector<bool> newLine;
        for (size_t j = 0; j<grid[i].size(); j++){
            int onNeighbours = 0;
            if(i>0){
                if(grid[i-1][j]){onNeighbours++;}
                if(j>0){
                    if(grid[i-1][j-1]){onNeighbours++;}
                }
                if(j<grid[i].size()-1){
                    if(grid[i-1][j+1]){onNeighbours++;}
                }
            }
            if(i<grid.size()-1){
                if(grid[i+1][j]){onNeighbours++;}
                if(j>0){
                    if(grid[i+1][j-1]){onNeighbours++;}
                }
                if(j<grid[i].size()-1){
                    if(grid[i+1][j+1]){onNeighbours++;}
                }
            }
            if(j>0){
                if(grid[i][j-1]){onNeighbours++;}
            }
            if(j<grid[i].size()-1){
                if(grid[i][j+1]){onNeighbours++;}
            }

            if((grid[i][j] && (onNeighbours == 2 || onNeighbours == 3)) || (!grid[i][j] && onNeighbours == 3)){
                newLine.push_back(true);
                newLightsOn++;
            }else{
                newLine.push_back(false);
                newLightsOff++;
            }
        }
        newState.push_back(newLine);
    }
    grid = newState;
    numLightsOff = newLightsOff;
    numLightsOn = newLightsOn;
}

void lightGrid::updateStateCorners(){
    std::vector<std::vector<bool>> newState;
    int newLightsOn = 0, newLightsOff = 0;
    for (size_t i = 0; i<grid.size(); i++){
        std::vector<bool> newLine;
        for (size_t j = 0; j<grid[i].size(); j++){
            int onNeighbours = 0;
            if(i>0){
                if(grid[i-1][j]){onNeighbours++;}
                if(j>0){
                    if(grid[i-1][j-1]){onNeighbours++;}
                }
                if(j<grid[i].size()-1){
                    if(grid[i-1][j+1]){onNeighbours++;}
                }
            }
            if(i<grid.size()-1){
                if(grid[i+1][j]){onNeighbours++;}
                if(j>0){
                    if(grid[i+1][j-1]){onNeighbours++;}
                }
                if(j<grid[i].size()-1){
                    if(grid[i+1][j+1]){onNeighbours++;}
                }
            }
            if(j>0){
                if(grid[i][j-1]){onNeighbours++;}
            }
            if(j<grid[i].size()-1){
                if(grid[i][j+1]){onNeighbours++;}
            }

            if((i==0 && j == 0) || (i==0 && j == grid[i].size()-1) || (i==grid.size()-1 && j == 0) || (i==grid.size()-1 && j==grid[i].size()-1)){
                newLine.push_back(true);
                newLightsOn++;
            }
            else if((grid[i][j] && (onNeighbours == 2 || onNeighbours == 3)) || (!grid[i][j] && onNeighbours == 3)){
                newLine.push_back(true);
                newLightsOn++;
            }else{
                newLine.push_back(false);
                newLightsOff++;
            }
        }
        newState.push_back(newLine);
    }
    grid = newState;
    numLightsOff = newLightsOff;
    numLightsOn = newLightsOn;    
}

int main (){

    std::string line;
    std::ifstream file;
    file.open("/home/tomas/Documents/Advent-of-code/2015/18/input.txt");

    std::vector<std::vector<bool>> initState_A, initState_B;
    int initLightsOn_A = 0, initLightsOff_A = 0;
    int initLightsOn_B = 0, initLightsOff_B = 0;
    if(file.peek() == std::ifstream::traits_type::eof()){
        std::cerr << "Input file is empty! Have you got the right file path?";
    }else{
        //Part A
        while(getline(file, line)){
            // Parse the instructions
            std::vector<bool> currLine;
            for (auto i:line){
                if(i == '#'){
                    currLine.push_back(true);
                    initLightsOn_A++;

                }else{
                    currLine.push_back(false);
                    initLightsOff_A++;
                }
            }
            initState_A.push_back(currLine);
        } 

        // Part B
        initState_B = initState_A;
        initState_B[0][0] = true;
        initState_B[0][initState_B[0].size() - 1] = true;
        initState_B[initState_B.size() - 1][0] = true;
        initState_B[initState_B.size() - 1][initState_B[0].size() - 1] = true;
        
    }   
    lightGrid grid_A(initState_A, initLightsOn_A, initLightsOff_A);
    lightGrid grid_B(initState_B, initLightsOn_B, initLightsOff_B); // lightsOn and Off need to be updated given the corners.
    // Part A
    for (int i = 0; i<100; i++){grid_A.updateState();}

    // Part B
    for (int i = 0; i<100; i++){grid_B.updateStateCorners();}
    std::cout << "Part A, lights on: " << grid_A.getNumLightsOn() << std::endl;
    std::cout << "Part B, lights on: " << grid_B.getNumLightsOn() << std::endl;
    return 0;
}

