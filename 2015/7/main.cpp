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
    void carryInstructions(std::vector<std::string> instructions);
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

void Circuit::carryInstructions(std::vector<std::string> instructions){
    int counter = 0;
    std::vector<std::string> instructions_tmp = instructions;
    while(!instructions_tmp.empty()){
        std::size_t target_pos = instructions_tmp[counter].find("->");
        std::string target = instructions_tmp[counter].substr(target_pos+3);

        std::size_t and_pos = instructions_tmp[counter].find("AND");
        std::size_t or_pos = instructions_tmp[counter].find("OR");
        std::size_t lshift_pos = instructions_tmp[counter].find("LSHIFT");
        std::size_t rshift_pos = instructions_tmp[counter].find("RSHIFT");
        std::size_t not_pos = instructions_tmp[counter].find("NOT");

        if(and_pos!=std::string::npos){
            std::string input1 = instructions_tmp[counter].substr(0,and_pos-1);
            std::string input2 = instructions_tmp[counter].substr(and_pos+4, target_pos-and_pos-5);
            bool i1 = false, i2 = false;

            if(std::isdigit(input1[0]) || (isalpha(input1[0]) && this->contains(input1))) i1 = true;
            if(std::isdigit(input2[0]) || (isalpha(input2[0]) && this->contains(input2))) i2 = true;

            if(i1 && i2) {
                this->and_operator(input1, input2, target);
                instructions_tmp.erase(instructions_tmp.begin()+counter);
            }
        }else if(or_pos!=std::string::npos){
            std::string input1 = instructions_tmp[counter].substr(0,or_pos-1);
            std::string input2 = instructions_tmp[counter].substr(or_pos+3, target_pos-or_pos-4);
            bool i1 = false, i2 = false;

            if(std::isdigit(input1[0]) || (isalpha(input1[0]) && this->contains(input1))) i1 = true;
            if(std::isdigit(input2[0]) || (isalpha(input2[0]) && this->contains(input2))) i2 = true;

            if(i1 && i2) {
                this->or_operator(input1, input2, target);
                instructions_tmp.erase(instructions_tmp.begin()+counter);
            }
        }else if(lshift_pos!=std::string::npos){
            std::string input1 = instructions_tmp[counter].substr(0,lshift_pos-1);
            int bitsnum = stoi(instructions_tmp[counter].substr(lshift_pos+6, target_pos-lshift_pos-7));

            if(std::isdigit(input1[0]) || (isalpha(input1[0]) && this->contains(input1))) {
                this->Lshift(input1,bitsnum,target);
                instructions_tmp.erase(instructions_tmp.begin()+counter);
            }
        }else if(rshift_pos!=std::string::npos){
            std::string input1 = instructions_tmp[counter].substr(0,rshift_pos-1);
            int bitsnum = stoi(instructions_tmp[counter].substr(rshift_pos+6, target_pos-rshift_pos-7));

            if(std::isdigit(input1[0]) || (isalpha(input1[0]) && this->contains(input1))) {
                this->Rshift(input1,bitsnum,target);
                instructions_tmp.erase(instructions_tmp.begin()+counter);
            }
        }else if(not_pos!=std::string::npos){
            std::string input1 = instructions_tmp[counter].substr(not_pos+4,target_pos-not_pos-5);
            if(std::isdigit(input1[0]) || (isalpha(input1[0]) && this->contains(input1))) {
                this->negation(input1,target);
                instructions_tmp.erase(instructions_tmp.begin()+counter);
            }
        }else{
            std::string input1 = instructions_tmp[counter].substr(0,target_pos-1);
            if(std::isdigit(input1[0]) || (isalpha(input1[0]) && this->contains(input1))) {
                this->signal(input1, target);
                instructions_tmp.erase(instructions_tmp.begin()+counter);
            }
        }
        counter<instructions_tmp.size()-1?  counter++: counter = 0;
    }
}

int main() {

    std::ifstream file;
    file.open("/home/tomas/Documents/Advent-of-code/2015/7/input.txt");

    std::vector<std::string> instructions;
    std::string instructions_line;
    while(getline(file, instructions_line)){
        instructions.push_back(instructions_line);
    }
    file.close();

    Circuit circuit1;
    circuit1.carryInstructions(instructions);
    std::cout << "First: Wire a is " << circuit1.getValue("a") << std::endl;

    Circuit circuit2;
    circuit2.setValue("b",circuit1.getValue("a"));
    circuit2.carryInstructions(instructions);
    std::cout << "Second: Wire a is " << circuit2.getValue("a") << std::endl;

    return 0;
}