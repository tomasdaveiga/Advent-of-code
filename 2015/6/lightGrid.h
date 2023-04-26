//
// Created by tomas on 08/04/23.
//

#ifndef INC_6_LIGHTGRID_H
#define INC_6_LIGHTGRID_H

#include <vector>
#include <string>
#include <algorithm>

class lightGrid {
public:
    lightGrid(int length, int width);
    void instructions1(std::vector<int> coordinates, const std::string& action);
    void instructions2(std::vector<int> coordinates, const std::string& action);
    int numLightsOn();

private:
    std::vector<std::vector<int>> grid;
};


#endif //INC_6_LIGHTGRID_H
