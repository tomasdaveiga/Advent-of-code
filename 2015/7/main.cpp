#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>

class Circuit{
public:
    Circuit();
    void signal(const std::string& input, const std::string& target);
    void and_operator(const std::string& input1, const std::string& input2, const std::string& target);
    void or_operator(const std::string& input1, const std::string& input2, const std::string& target);
    void Rshift(const std::string& input, unsigned short int bitnums, const std::string& target);
    void Lshift(const std::string& input, unsigned short int bitnums, const std::string& target);
    void negation(const std::string& input, const std::string& target);
    unsigned short int getValue(const std::string& key);

    bool contains(const std::string& key);
    void setValue(const std::string& key, const int value);

private:
    std::map<std::string, unsigned short int> circuit;
};

Circuit::Circuit() = default;

void Circuit::signal(const std::string& input, const std::string& target) {
    unsigned short int i = circuit[input];
    if(std::isdigit(input[0])) i = std::stoi(input);

    circuit[target] = i;
}

void Circuit::and_operator(const std::string& input1, const std::string& input2, const std::string& target) {
    unsigned short int i1 = circuit[input1], i2 = circuit[input2];
    if(std::isdigit(input1[0])) i1 = std::stoi(input1);
    if(std::isdigit(input2[0])) i2 = std::stoi(input2);

    circuit[target] = (i1 & i2);
}

void Circuit::or_operator(const std::string &input1, const std::string &input2, const std::string &target) {
    unsigned short int i1 = circuit[input1], i2 = circuit[input2];
    if(std::isdigit(input1[0])) i1 = std::stoi(input1);
    if(std::isdigit(input2[0])) i2 = std::stoi(input2);

    circuit[target] = (i1 | i2);
}

void Circuit::Rshift(const std::string& input, unsigned short int bitnums, const std::string& target) {
    unsigned short int i = circuit[input];
    if(std::isdigit(input[0])) i = std::stoi(input);

    circuit[target] = i >> bitnums;
}

void Circuit::Lshift(const std::string& input, unsigned short int bitnums, const std::string& target) {
    unsigned short int i = circuit[input];
    if(std::isdigit(input[0])) i = std::stoi(input);

    circuit[target] = i << bitnums;
}

void Circuit::negation(const std::string& input, const std::string& target) {
    unsigned short int i = circuit[input];
    if(std::isdigit(input[0])) i = std::stoi(input);

    circuit[target] = ~i;
}

unsigned short int Circuit::getValue(const std::string& key) {
    return circuit[key];
}

bool Circuit::contains(const std::string& key) {
    return (circuit.find(key) != circuit.end());
}

void Circuit::setValue(const std::string &key, const int value) {
    circuit[key] = value;
}

int main() {

    std::ifstream file;
    file.open("/home/tomas/CLionProjects/Advent-of-code/2015/7/input.txt");

    std::vector<std::string> instructions;
    std::string instructions_line;
    while(getline(file, instructions_line)){
        instructions.push_back(instructions_line);
    }
    file.close();

    Circuit circuit;
    circuit.setValue("b",46065);
    int counter = 0;
    while(!instructions.empty()){
        std::size_t target_pos = instructions[counter].find("->");
        std::string target = instructions[counter].substr(target_pos+3);
        if(target == "b"){
            instructions.erase(instructions.begin()+counter);
            continue;
        }

        std::size_t and_pos = instructions[counter].find("AND");
        std::size_t or_pos = instructions[counter].find("OR");
        std::size_t lshift_pos = instructions[counter].find("LSHIFT");
        std::size_t rshift_pos = instructions[counter].find("RSHIFT");
        std::size_t not_pos = instructions[counter].find("NOT");

        if(and_pos!=std::string::npos){
            std::string input1 = instructions[counter].substr(0,and_pos-1);
            std::string input2 = instructions[counter].substr(and_pos+4, target_pos-and_pos-5);
            bool i1 = false, i2 = false;

            if(std::isdigit(input1[0]) || (isalpha(input1[0]) && circuit.contains(input1))) i1 = true;
            if(std::isdigit(input2[0]) || (isalpha(input2[0]) && circuit.contains(input2))) i2 = true;

            if(i1 && i2) {
                circuit.and_operator(input1, input2, target);
                instructions.erase(instructions.begin()+counter);
            }
        }else if(or_pos!=std::string::npos){
            std::string input1 = instructions[counter].substr(0,or_pos-1);
            std::string input2 = instructions[counter].substr(or_pos+3, target_pos-or_pos-4);
            bool i1 = false, i2 = false;

            if(std::isdigit(input1[0]) || (isalpha(input1[0]) && circuit.contains(input1))) i1 = true;
            if(std::isdigit(input2[0]) || (isalpha(input2[0]) && circuit.contains(input2))) i2 = true;

            if(i1 && i2) {
                circuit.or_operator(input1, input2, target);
                instructions.erase(instructions.begin()+counter);
            }
        }else if(lshift_pos!=std::string::npos){
            std::string input1 = instructions[counter].substr(0,lshift_pos-1);
            int bitsnum = stoi(instructions[counter].substr(lshift_pos+6, target_pos-lshift_pos-7));

            if(std::isdigit(input1[0]) || (isalpha(input1[0]) && circuit.contains(input1))) {
                circuit.Lshift(input1,bitsnum,target);
                instructions.erase(instructions.begin()+counter);
            }
        }else if(rshift_pos!=std::string::npos){
            std::string input1 = instructions[counter].substr(0,rshift_pos-1);
            int bitsnum = stoi(instructions[counter].substr(rshift_pos+6, target_pos-rshift_pos-7));

            if(std::isdigit(input1[0]) || (isalpha(input1[0]) && circuit.contains(input1))) {
                circuit.Rshift(input1,bitsnum,target);
                instructions.erase(instructions.begin()+counter);
            }
        }else if(not_pos!=std::string::npos){
            std::string input1 = instructions[counter].substr(not_pos+4,target_pos-not_pos-5);
            if(std::isdigit(input1[0]) || (isalpha(input1[0]) && circuit.contains(input1))) {
                circuit.negation(input1,target);
                instructions.erase(instructions.begin()+counter);
            }
        }else{
            std::string input1 = instructions[counter].substr(0,target_pos-1);
            if(std::isdigit(input1[0]) || (isalpha(input1[0]) && circuit.contains(input1))) {
                circuit.signal(input1, target);
                instructions.erase(instructions.begin()+counter);
            }
        }
        counter<instructions.size()-1?  counter++: counter = 0;
    }
    std::cout << "Wire a is " << circuit.getValue("a") << std::endl;

    return 0;
}