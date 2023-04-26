//
// Created by tomas on 08/04/23.
//

#include "lightGrid.h"

lightGrid::lightGrid(int length, int width) {
    std::vector<int> line(length,0);
    for (int i = 0; i<width; i++){
        grid.push_back(line);
    }
}

void lightGrid::instructions1(std::vector<int>coordinates, const std::string& action) {
    for(int i = coordinates[0]; i<=coordinates[2]; i++){
        for (int j = coordinates[1]; j<=coordinates[3]; j++){
            if(action == "on") grid[i][j] = 1;
            if(action == "off") grid[i][j] = 0;
            if(action == "toggle") grid[i][j] == 1 ? grid[i][j] = 0 : grid[i][j] = 1;
        }
    }
}

void lightGrid::instructions2(std::vector<int> coordinates, const std::string& action) {
    for(int i = coordinates[0]; i<=coordinates[2]; i++){
        for (int j = coordinates[1]; j<=coordinates[3]; j++){
            if(action == "on") grid[i][j] += 1;
            if(action == "off") if(grid[i][j]>0) grid[i][j]-= 1;
            if(action == "toggle") grid[i][j] += 2;
        }
    }
}

int lightGrid::numLightsOn(){
    int counter = 0;
    for(auto & i : grid){
        for(int j=0; j<=grid[0].size(); j++){
            counter +=i[j];
        }
    }
    return counter;
}
