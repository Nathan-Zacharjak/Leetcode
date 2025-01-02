#include <print>

class Solution {
private:
    bool isSameParity(char c1, char c2){
        int i1 = c1 - '0';
        int i2 = c2 - '0';
        bool c1Even = i1 % 2 == 0;
        bool c2Even = i2 % 2 == 0;
        
        println("c1: {}, c2: {}", c1, c2);
        println("i1: {}, i2: {}", i1, i2);
        println("c1Even : {}, c2Even: {}", c1Even, c2Even);

        if ((c1Even && c2Even) || (!c1Even && !c2Even)){
            return true;
        }

        return false;
    }

public:
    string getSmallestString(string s) {
        for (int i = 0; i < s.size() - 1; i++){
            char c1 = s.at(i);
            char c2 = s.at(i + 1);

            if (c1 > c2 && isSameParity(c1, c2)){
                s.at(i) = c2;
                s.at(i + 1) = c1;
                return s;
            }
        }

        return s;
    }
};