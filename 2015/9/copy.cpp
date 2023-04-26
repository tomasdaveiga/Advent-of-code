#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

int main() {
// Stores all routes in a std::map and all cities in a std::set
    std::map<std::pair<std::string, std::string>, int> routes;
    std::set<std::string> cities;

    std::ifstream file;
    file.open("/home/tomas/CLionProjects/Advent-of-code/2015/9/input.txt");
    std::string line;

    while(getline(file, line)){
        std::istringstream ss(line);
        std::string from, to, tmp;
        int distance;
        ss >> from >> tmp >> to >> tmp >> distance;

        std::pair<std::string, std::string> cities_route = std::make_pair(from, to);
        routes[cities_route] = distance;

        cities.insert(from);
        cities.insert(to);
    }

// Do the different combinations: starting at each city travel to the closest one without going back
    std::vector<int>partA_distances;
    std::vector<int>partB_distances;

    for (const auto& i:cities){
        int max_distance = 0, min_distance = 0;

        std::map<std::pair<std::string, std::string>, int> remaining_routes_partA = routes, remaining_routes_partB = routes;
        std::set<std::string> remaining_cities_partA = cities, remaining_cities_partB = cities;

        // Part A
        std::string current_city_partA = i;
        std::string destination_partA;
        while(!remaining_routes_partA.empty() && !remaining_cities_partA.empty()) {
            int dist_to_dest = 0;
            for (auto &j: remaining_routes_partA) {
                if(dist_to_dest == 0) dist_to_dest = j.second;
                if ((j.first.first == current_city_partA || j.first.second == current_city_partA) && j.second < dist_to_dest) {
                    dist_to_dest = j.second;
                    j.first.first == current_city_partA ? destination_partA = j.first.second : destination_partA = j.first.first;
                }
            }
            remaining_cities_partA.erase(current_city_partA);
            for (auto it = remaining_routes_partA.cbegin(); it != remaining_routes_partA.cend(); ){
                if (it->first.first == current_city_partA || it->first.second == current_city_partA) {
                    remaining_routes_partA.erase(it++);
                }else{
                    ++it;
                }
            }
            min_distance += dist_to_dest;
            current_city_partA = destination_partA;

        }

        // Part B
        std::string current_city_partB = i;
        std::string destination_partB;
        while(!remaining_routes_partB.empty() && !remaining_cities_partB.empty()) {
            int dist_to_dest = 0;
            for (auto &j: remaining_routes_partB) {
                if ((j.first.first == current_city_partB || j.first.second == current_city_partB) && j.second > dist_to_dest) {
                    dist_to_dest = j.second;
                    j.first.first == current_city_partB ? destination_partB = j.first.second : destination_partB = j.first.first;
                }
            }
            remaining_cities_partB.erase(current_city_partB);
            for (auto it = remaining_routes_partB.cbegin(); it != remaining_routes_partB.cend(); ){
                if (it->first.first == current_city_partB || it->first.second == current_city_partB) {
                    remaining_routes_partB.erase(it++);
                }else{
                    ++it;
                }
            }
            max_distance += dist_to_dest;
            current_city_partB = destination_partB;

        }

        partA_distances.push_back(min_distance);
        partB_distances.push_back(max_distance);
    }
    file.close();

    std::cout << "PartA: " << *min_element(partA_distances.begin(), partA_distances.end()) << std::endl;
    std::cout << "PartB: " << *max_element(partB_distances.begin(), partB_distances.end()) << std::endl;
    return 0;
}
