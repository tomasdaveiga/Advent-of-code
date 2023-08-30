#include <iostream>
#include <map>
#include <fstream>
#include <vector>

std::vector<std::map<std::string, int> > parseInput(std::string input){
    std::ifstream file;
    std::string line;
    std::vector<std::map<std::string,int> > aunts;
    file.open("/Users/tomasveiga/Documents/Advent-of-code/2015/16/input.txt");

    if(file.peek() == std::ifstream::traits_type::eof()){
        std::cerr << "Input file is empty! Have you got the right file path?";
    }else{
        // Parsing the input
        while(getline(file,line)){
            std::map<std::string, int> current_aunt;
            // Get Sue's number
            std::size_t space_pos = line.find(' ');
            std::size_t colon_pos = line.find(':');
            int number = std::stoi(line.substr(space_pos+1,colon_pos-space_pos-1));
            current_aunt["Sue"] = number;

            line.erase(0, colon_pos+1);

            std::string keyword;
            std::size_t keyword_pos;

            // Get children number
            keyword = "children";
            keyword_pos = line.find(keyword);
            if (keyword_pos != std::string::npos){
                std::size_t comma_pos = line.find(',',keyword_pos);
                if (comma_pos != std::string::npos){
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2,comma_pos-keyword_pos-keyword.length()-2));
                }else{
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2));
                }
            }

            // Get cats number
            keyword = "cats";
            keyword_pos = line.find(keyword);
            if (keyword_pos != std::string::npos){
                std::size_t comma_pos = line.find(',',keyword_pos);
                if (comma_pos != std::string::npos){
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2,comma_pos-keyword_pos-keyword.length()-2));
                }else{
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2));
                }
            }

            // Get samoyeds number
            keyword = "samoyeds";
            keyword_pos = line.find(keyword);
            if (keyword_pos != std::string::npos){
                std::size_t comma_pos = line.find(',',keyword_pos);
                if (comma_pos != std::string::npos){
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2,comma_pos-keyword_pos-keyword.length()-2));
                }else{
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2));
                }
            }

            // Get pomeranians number
            keyword = "pomeranians";
            keyword_pos = line.find(keyword);
            if (keyword_pos != std::string::npos){
                std::size_t comma_pos = line.find(',',keyword_pos);
                if (comma_pos != std::string::npos){
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2,comma_pos-keyword_pos-keyword.length()-2));
                }else{
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2));
                }
            }

            // Get akitas number
            keyword = "akitas";
            keyword_pos = line.find(keyword);
            if (keyword_pos != std::string::npos){
                std::size_t comma_pos = line.find(',',keyword_pos);
                if (comma_pos != std::string::npos){
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2,comma_pos-keyword_pos-keyword.length()-2));
                }else{
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2));
                }
            }

            // Get vizslas number
            keyword = "vizlas";
            keyword_pos = line.find(keyword);
            if (keyword_pos != std::string::npos){
                std::size_t comma_pos = line.find(',',keyword_pos);
                if (comma_pos != std::string::npos){
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2,comma_pos-keyword_pos-keyword.length()-2));
                }else{
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2));
                }
            }

            // Get goldfish number
            keyword = "goldfish";
            keyword_pos = line.find(keyword);
            if (keyword_pos != std::string::npos){
                std::size_t comma_pos = line.find(',',keyword_pos);
                if (comma_pos != std::string::npos){
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2,comma_pos-keyword_pos-keyword.length()-2));
                }else{
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2));
                }
            }

            // Get trees number
            keyword = "trees";
            keyword_pos = line.find(keyword);
            if (keyword_pos != std::string::npos){
                std::size_t comma_pos = line.find(',',keyword_pos);
                if (comma_pos != std::string::npos){
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2,comma_pos-keyword_pos-keyword.length()-2));
                }else{
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2));
                }
            }

            // Get cars number
            keyword = "cars";
            keyword_pos = line.find(keyword);
            if (keyword_pos != std::string::npos){
                std::size_t comma_pos = line.find(',',keyword_pos);
                if (comma_pos != std::string::npos){
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2,comma_pos-keyword_pos-keyword.length()-2));
                }else{
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2));
                }
            }

            // Get perfumes number
            keyword = "perfumes";
            keyword_pos = line.find(keyword);
            if (keyword_pos != std::string::npos){
                std::size_t comma_pos = line.find(',',keyword_pos);
                if (comma_pos != std::string::npos){
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2,comma_pos-keyword_pos-keyword.length()-2));
                }else{
                    current_aunt[keyword] = std::stoi(line.substr(keyword_pos+keyword.length()+2));
                }
            }

            aunts.push_back(current_aunt);
        }
    }
    return aunts;
}

int main() {
    std::string input_path = "/home/tomas/Documents/Advent-of-code/2015/16/input.txt";
    std::vector<std::map<std::string,int> > aunts = parseInput(input_path);

    std::map<std::string,int> MFCSAM_result;
    MFCSAM_result["children"] = 3;
    MFCSAM_result["cats"] = 7;
    MFCSAM_result["samoyeds"] = 2;
    MFCSAM_result["pomeranians"] = 3;
    MFCSAM_result["akitas"] = 0;
    MFCSAM_result["vizslas"] = 0;
    MFCSAM_result["goldfish"] = 5;
    MFCSAM_result["trees"] = 3;
    MFCSAM_result["cars"] = 2;
    MFCSAM_result["perfumes"] = 1;

    // FIRST
    // For each MFCSAM result, remove any Sues that don't match the result, at the end you should only have the ones that match
    std::vector<std::map<std::string,int> > aunts_tmp = aunts;

    for (std::map<std::string,int>::iterator i = MFCSAM_result.begin(); i != MFCSAM_result.end(); i++){
        std::vector<std::map<std::string,int> >::iterator it = aunts_tmp.begin();
        int j = 0;
        while(it!=aunts_tmp.end()){
            if(aunts_tmp[j].find(i->first) != aunts_tmp[j].end() && aunts_tmp[j].find(i->first)->second != i->second){
                it = aunts_tmp.erase(it);
            }
            else{
                ++it;
                ++j;
            }
        }
    }
    std::cout << "Part 1: It's Aunt number " << aunts_tmp[0].find("Sue")->second << std::endl;

    // SECOND
    std::vector<std::map<std::string,int> > aunts_tmp2 = aunts;

    for (std::map<std::string,int>::iterator i = MFCSAM_result.begin(); i != MFCSAM_result.end(); i++){
        std::vector<std::map<std::string,int> >::iterator it = aunts_tmp2.begin();
        int j = 0;
        while(it!=aunts_tmp2.end()){
            if(i->first == "cats" || i->first == "trees"){
                if(aunts_tmp2[j].find(i->first) != aunts_tmp2[j].end() && aunts_tmp2[j].find(i->first)->second <= i->second){
                    it = aunts_tmp2.erase(it);
                }
                else{
                    ++it;
                    ++j;
                }
            }else if(i->first == "pomeranians" || i->first == "goldfish"){
                if(aunts_tmp2[j].find(i->first) != aunts_tmp2[j].end() && aunts_tmp2[j].find(i->first)->second >= i->second){
                    it = aunts_tmp2.erase(it);
                }
                else{
                    ++it;
                    ++j;
                }               
            }else{
                if(aunts_tmp2[j].find(i->first) != aunts_tmp2[j].end() && aunts_tmp2[j].find(i->first)->second != i->second){
                    it = aunts_tmp2.erase(it);
                }
                else{
                    ++it;
                    ++j;
                }
            }
        }
    }   

    std::cout << "Part 2: It's Aunt number " << aunts_tmp2[0].find("Sue")->second << std::endl;
    return 0;
}
