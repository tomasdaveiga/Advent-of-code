#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include<climits>
#include <chrono>

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
    file.close();

// Option 1: Starting at each city travel to the closest one without going back - more efficient O(N M^2 log M)
    std::vector<int>partA_distances;
    std::vector<int>partB_distances;
    for (const auto& i:cities){
        int max_distance = 0, min_distance = 0;

        // Part A
        std::map<std::pair<std::string, std::string>, int> partA_remaining_routes = routes;

        std::string partA_current_city = i;
        std::string partA_destination;
        while(!partA_remaining_routes.empty()) {
            int dist_to_dest = INT_MAX;
            for (auto &j: partA_remaining_routes) {
                if ((j.first.first == partA_current_city || j.first.second == partA_current_city) && j.second < dist_to_dest) {
                    dist_to_dest = j.second;
                    j.first.first == partA_current_city ? partA_destination = j.first.second : partA_destination = j.first.first;
                }
            }

            for (auto it = partA_remaining_routes.cbegin(); it != partA_remaining_routes.cend(); ){
                if (it->first.first == partA_current_city || it->first.second == partA_current_city) {
                    partA_remaining_routes.erase(it++);
                }else{
                    ++it;
                }
            }
            min_distance += dist_to_dest;
            partA_current_city = partA_destination;
        }
        partA_distances.push_back(min_distance);

        // Part B
        std::map<std::pair<std::string, std::string>, int> partB_remaining_routes = routes;
        std::string partB_current_city = i;
        std::string partB_destination;
        while(!partB_remaining_routes.empty()) {
            int dist_to_dest = INT_MIN;
            for (auto &j: partB_remaining_routes) {
                if ((j.first.first == partB_current_city || j.first.second == partB_current_city) && j.second > dist_to_dest) {
                    dist_to_dest = j.second;
                    j.first.first == partB_current_city ? partB_destination = j.first.second : partB_destination = j.first.first;
                }
            }
            for (auto it = partB_remaining_routes.cbegin(); it != partB_remaining_routes.cend(); ){
                if (it->first.first == partB_current_city || it->first.second == partB_current_city) {
                    partB_remaining_routes.erase(it++);
                }else{
                    ++it;
                }
            }
            max_distance += dist_to_dest;
            partB_current_city = partB_destination;
        }
        partB_distances.push_back(max_distance);
    }
    std::cout << "Part A: " << *min_element(partA_distances.begin(), partA_distances.end()) << std::endl;
    std::cout << "Part B: " << *max_element(partB_distances.begin(), partB_distances.end()) << std::endl;

// Option 2: Try all possible cases - less efficient O(N!)
    std::vector<std::string> cities_vec;
    cities_vec.reserve(cities.size());
    for (const auto& i:cities)
        cities_vec.push_back(i);

    int short_dist = INT_MAX;
    int long_dist = INT_MIN;

    do{
        int dist = 0;
        std::string current_city;
        for(const auto& c:cities_vec){
            if(!current_city.empty()){
                dist +=routes[{current_city,c}] + routes[{c,current_city}];
            }
            current_city = c;
        }
        if (dist<short_dist) short_dist = dist;
        if (dist>long_dist) long_dist = dist;
    } while(std::next_permutation(cities_vec.begin(), cities_vec.end()));
    std::cout << "Part A: " << short_dist << std::endl;
    std::cout << "Part B: " << long_dist << std::endl;

    return 0;
}
