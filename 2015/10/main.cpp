#include <iostream>
#include <string>
#include <utility>

std::string look_and_say(std::string sequence, int times){
    std::string result = std::move(sequence);
    for (int i=0; i<times; i++){
        std::string temp_result;
        char prev = result[0];
        int counter = 1;
        for (int j=1; j<result.length(); j++) {
            if (result[j] == prev) {
                counter++;
            } else {
                temp_result += std::to_string(counter) + result[j - 1];
                counter = 1;
                prev = result[j];
            }
        }
        temp_result += std::to_string(counter) + result[result.length()-1];
        result.clear();
        result = temp_result;
    }
    return result;
}


int main() {
    std::cout << look_and_say("1113122113", 50).length() << std::endl;
    return 0;
}
