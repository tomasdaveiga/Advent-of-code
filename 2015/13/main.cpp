#include <iostream>
#include <fstream>
#include <map>
#include <set>

int happinessPoints(const std::set<std::string>& names, const std::map<std::pair<std::string,std::string>,int>& relationships){
    int totalPoints = 0;

    for (const auto& i:names){
        std::map<std::pair<std::string,std::string>,int> remainingRelationships = relationships;
        int seatingPoints = 0;
        std::string firstPerson = i;
        std::string currentPerson = firstPerson;
        while(!remainingRelationships.empty()){
            int couplePoints = 0;
            std::string nextPerson;
            for(auto j = remainingRelationships.begin(); j != remainingRelationships.end(); j++){
                int currentPoints = 0;
                if(j->first.first == currentPerson){
                    currentPoints = remainingRelationships.at({j->first.first, j->first.second}) + remainingRelationships.at({j->first.second, j->first.first});
                    if(currentPoints>=couplePoints){
                        couplePoints = currentPoints;
                        nextPerson = j->first.second;
                    }
                }
            }

            for(auto j = remainingRelationships.begin(); j != remainingRelationships.end();){
                if(j->first.first == currentPerson || j->first.second == currentPerson){
                    remainingRelationships.erase(j++);
                }else{
                    ++j;
                }
            }
            seatingPoints += couplePoints;
            currentPerson = nextPerson;
        }
        seatingPoints += relationships.at({firstPerson,currentPerson}) + relationships.at({currentPerson,firstPerson});
        if(seatingPoints>totalPoints) totalPoints = seatingPoints;
    }

    return totalPoints;
}

int main() {

    std::ifstream file;
    file.open("/home/tomas/CLionProjects/Advent-of-code/2015/13/input.txt");
    std::string line;

    std::map<std::pair<std::string, std::string>,int> relationships;
    std::set<std::string> names;

    while(getline(file, line)){
        std::size_t first_name = line.find(' ');
        std::size_t last_name = line.find("to ");
        line.erase(line.end()-1);
        std::pair<std::string, std::string> couple = std::make_pair(line.substr(0,first_name),line.substr(last_name+3));

        std::size_t gain = line.find("would ");
        std::size_t happiness = line.find("happiness");
        int val = 0;
        if(line.substr(gain+6,4) == "gain") val = std::stoi(line.substr(gain+11,happiness-gain-10));
        if(line.substr(gain+6,4) == "lose") val = -std::stoi(line.substr(gain+11,happiness-gain-10));

        relationships[couple] = val;

        names.insert(line.substr(0,first_name));
        names.insert(line.substr(last_name+3));
    }
    std::cout << "1st part: " << happinessPoints(names,relationships) << std::endl;

    // Add me to list
    for (const auto& i:names){
        relationships[{"Me",i}] = 0;
        relationships[{i,"Me"}] = 0;
    }
    names.insert("Me");

    std::cout << "2nd part: " <<  happinessPoints(names,relationships) << std::endl;
    return 0;
}
