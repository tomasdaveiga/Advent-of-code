#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

bool isNice1(const string& input) {
    // Check vowels
    auto vowel_counter = count(input.begin(), input.end(),'a') + count(input.begin(),input.end(),'e') + count(input.begin(),input.end(),'i') + count(input.begin(),input.end(),'o') + count(input.begin(),input.end(),'u');

//    int vowel_counter = 0;
//    size_t found_A = input.find('a');
//    size_t found_E = input.find('e');
//    size_t found_I = input.find('i');
//    size_t found_O = input.find('o');
//    size_t found_U = input.find('u');
//
//    while (found_A != string::npos || found_E != string::npos || found_I != string::npos || found_O != string::npos ||
//           found_U != string::npos){
//        if (found_A != string::npos) {vowel_counter++;}
//        if (found_E != string::npos) {vowel_counter++;}
//        if (found_I != string::npos) {vowel_counter++;}
//        if (found_O != string::npos) {vowel_counter++;}
//        if (found_U != string::npos) {vowel_counter++;}
//
//        found_A = input.find('a',found_A+1);
//        found_E = input.find('e',found_E+1);
//        found_I = input.find('i',found_I+1);
//        found_O = input.find('o',found_O+1);
//        found_U = input.find('u',found_U+1);
//    }

    // Check double letters
    bool double_letter = false;
    for (int i = 0; i<input.length()-1; i++){
        if(input[i] == input[i+1]){
            double_letter = true;
            break;
        }
    }

    // Check forbidden string
//    bool forbiddenString = false;
//    for (int i = 0; i<input.length()-1; i++){
//        if(input[i]=='a' && input[i+1]=='b'){
//            forbiddenString = true;
//            break;
//        }
//        if(input[i]=='c' && input[i+1]=='d'){
//            forbiddenString = true;
//            break;
//        }
//        if(input[i]=='p' && input[i+1]=='q'){
//            forbiddenString = true;
//            break;
//        }
//        if(input[i]=='x' && input[i+1]=='y'){
//            forbiddenString = true;
//            break;
//        }
//    }
    bool forbiddenString = (input.find("ab") != string::npos || input.find("cd") != string::npos || input.find("pq") != string::npos || input.find("xy") != string::npos);

    // Check the three conditions
    return (vowel_counter>2 && double_letter && !forbiddenString);
}

bool isNice2(const string& input) {
    // Check pairs
    bool hasPair = false;
    for(int i = 0; i<input.length()-3; i++){
        string pair = input.substr(i,2);
        if(input.find(pair,i+2)!=string::npos){
            hasPair = true;
            break;
        }
    }

    // Check Repeats
    bool hasRepeat = false;
    for(int i=0; i<input.length()-2; i++){
        if(input[i]==input[i+2]){
            hasRepeat = true;
            break;
        }
    }

    // Check the two conditions
    return (hasPair && hasRepeat);
}



int main() {
    int niceStrings1 = 0, naughtyStrings1 = 0, niceStrings2 = 0, naughtyStrings2 = 0;
    string str;
    ifstream file;
    file.open("/home/tomas/CLionProjects/Advent-of-code/2015/5/input.txt");

    while(getline(file, str)){
        isNice1(str)? niceStrings1++: naughtyStrings1++;
        isNice2(str)? niceStrings2++: naughtyStrings2++;
    }
    std::cout << "1. There are " << niceStrings1 << " nice strings, and " << naughtyStrings1 << " naughty strings." << std::endl;
    std::cout << "2. There are " << niceStrings2 << " nice strings, and " << naughtyStrings2 << " naughty strings." << std::endl;
    return 0;
}
