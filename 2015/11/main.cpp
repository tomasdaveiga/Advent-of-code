#include <iostream>
#include <string>

std::string nextPassword(std::string password){
    std::string result = std::move(password);

    bool hasStraight = false, hasForbidden = false, hasPairs = false;
    while(!hasStraight || hasForbidden || !hasPairs){
        hasStraight = false, hasForbidden = false, hasPairs = false;
        // Generate New password
        int i = (int)result.length()-1;
        while(result[i]=='z' && i>-1){
            result[i] = 'a';
            --i;
        }
        if(i>=0) result[i] += 1;

        // Check the three conditions
        // Check Straight
        for(int j = 0; j<result.length()-2; j++){
            if(result[j+2] == result[j+1]+1 && result[j+1] == result[j]+1){ hasStraight = true;}
        }

        // Check forbidden letters
        for (char j : result){
            if(j == 'i' || j == 'l' || j == 'o') hasForbidden = true;
        }

        // Check Duplicates
        int dup_counter = 0;
        for (int j = 0; j<result.length()-1; j++){
            if(result[j] == result[j+1]){
                dup_counter++;
                j++;
            }
        }
        if(dup_counter>1) hasPairs = true;
    }
    return result;
}

int main() {
	std::string curr_password = "hxbxwxba";
	std::cout << "Current password is: " << curr_password << ". Next one is: " << nextPassword(curr_password) << std::endl;
	std::cout << "And the next one is " << nextPassword(nextPassword(curr_password)) << std::endl;
	return 0;
}
