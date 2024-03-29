#include <iostream>
#include <map>
#include <fstream>
#include <vector>

class Property{
public:
    Property();
    std::map<std::string,int> ingredient_values;
    void addIngredient(const std::string& ingredient, int value){
        ingredient_values[ingredient] = value;
    };
};

Property::Property() = default;


int highScore(std::vector<std::string> ingredients, std::vector<Property> list){
    int score;

    for 


    for(auto i:ingredients){
        
    }

    // Three ingredients
    // round 1
    // First - 100 ts
    // Second - 0 tsp
    // Third - 0 tsp    

    // round 2
    // First - 99 tsp
    // Second- 1 tsp
    // Third - 0 tsp

    // Round 3
    // First - 98 tsp
    // Second - 2 tsp
    // Third - 0 tsp

    // Round 4
    // First - 97 tsp
    // Second - 3 tsp
    // Third - 0 tsp

    // ...

    // Round 100
    // First - 1 tsp
    // Second - 99 tsp
    // Third - 0 tsp

    // Round 101
    // First - 0 tsp
    // Second - 100 tsp
    // Third - 0 tsp

    
    return score;
}


int main() {

    std::ifstream file;
    file.open("/home/tomas/Documents/Advent-of-code/2015/15/test.txt");
    std::string line;

    Property capacity, durability, flavor, texture, calories;

    std::vector<Property> list;
    std::vector<std::string> Ingredients;

    while(getline(file,line)){
        std::size_t ingredient_pos = line.find(':');
        std::size_t cap_pos = line.find("capacity");
        std::size_t dur_pos = line.find("durability");
        std::size_t fla_pos = line.find("flavor");
        std::size_t tex_pos = line.find("texture");
        std::size_t cal_pos = line.find("calories");

        std::string ingredient = line.substr(0,ingredient_pos);
        int cap = std::stoi(line.substr(cap_pos+9,dur_pos-cap_pos-11));
        int dur = std::stoi(line.substr(dur_pos+11,dur_pos-fla_pos-13));
        int fla = std::stoi(line.substr(fla_pos+7,fla_pos-tex_pos-9));
        int tex = std::stoi(line.substr(tex_pos+8,cal_pos-tex_pos-10));
        int cal = std::stoi(line.substr(cal_pos+9));

        capacity.addIngredient(ingredient, cap);
        durability.addIngredient(ingredient, dur);
        flavor.addIngredient(ingredient, fla);
        texture.addIngredient(ingredient, tex);
        calories.addIngredient(ingredient, cal);

        Ingredients.push_back(ingredient);
    }
    list.push_back(capacity);
    list.push_back(durability);
    list.push_back(flavor);
    list.push_back(texture);
    list.push_back(calories);
    std::cout << highScore(Ingredients, list) << std::endl;
    return 0;
}
