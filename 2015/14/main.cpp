#include <iostream>
#include <fstream>
#include <map>
#include <tuple>
#include <bits/stdc++.h>

int winningReindeer(const std::map<std::string,std::tuple<int,int,int>>& reindeer,int time, const std::string& score){
    std::map<std::string, std::pair<int,int>> ranking;
    int max_score = INT_MIN;
    for (int i = 1; i<=time; i++){
        for(auto j:reindeer){
            int stage_time = std::get<1>(j.second);
            bool fly = true;
            while(i>stage_time){
                if(fly){
                    stage_time += std::get<2>(j.second);
                    fly = false;
                }else{
                    stage_time += std::get<1>(j.second);
                    fly = true;
                }
            }
            if(fly){
                std::pair<int, int> currRank = std::make_pair(ranking[j.first].first +=std::get<0>(j.second), ranking[j.first].second);
                ranking[j.first] = currRank;
            }
        }
        int max_distance = INT_MIN;
        std::vector<std::string> lead_reindeer;
        for (const auto& j:ranking) {
            if (ranking[j.first].first> max_distance){
                max_distance = ranking[j.first].first;
                lead_reindeer.clear();
                lead_reindeer.push_back(j.first);
            }else if(ranking[j.first].first == max_distance){
                lead_reindeer.push_back(j.first);
            }
        }
        for (const auto& j:lead_reindeer){
            ranking[j] = {ranking[j].first,ranking[j].second +=1};
        }

    }

    for (const auto& i:ranking) {
        if (score == "distance" && i.second.first > max_score){
            max_score = i.second.first;
        }else if(score == "points" && i.second.second > max_score){
            max_score = i.second.second;
        }
    }
    return max_score;
}

int main() {
    std::ifstream file;
    file.open("/home/tomas/CLionProjects/Advent-of-code/2015/14/input.txt");
    std::string line;

    std::map<std::string,std::tuple<int,int,int>> reindeer;

    while(getline(file,line)){
        std::size_t can_pos = line.find(" can");
        std::size_t fly = line.find("fly ");
        std::size_t km = line.find(" km/s");
        std::size_t duration_pos = line.find(" seconds,");
        std::size_t rest_pos = line.find("rest for ");
        std::size_t rest_sec = line.find(" seconds.");

        std::string name = line.substr(0,can_pos);
        int speed = std::stoi(line.substr(fly+4,km-fly-4));
        int duration = std::stoi(line.substr(km+10,duration_pos-km-10));
        int rest = std::stoi(line.substr(rest_pos+9,rest_sec-rest_pos-9));

        reindeer[name] = {speed,duration,rest};
    }

    std::cout << "Distance of winning reindeer: " << winningReindeer(reindeer,2503, "distance") << std::endl;
    std::cout << "Points of winning reindeer: " << winningReindeer(reindeer,2503, "points") << std::endl;
    return 0;
}
