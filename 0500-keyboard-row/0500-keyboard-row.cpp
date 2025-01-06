#include <print>

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row1Chars = {'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> row2Chars = {'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> row3Chars = {'z','x','c','v','b','n','m'};

        vector<string> answer;
        bool row1 = true;
        bool row2 = true;
        bool row3 = true;

        for (const auto &word : words){
            for (const auto &c : word){
                char lowerC = tolower(c);
                cout << c << endl;
                println("1: {}, 2: {}, 3: {}", row1, row2, row3);

                if (!row1Chars.contains(lowerC)){
                    row1 = false;
                }
                if (!row2Chars.contains(lowerC)){
                    row2 = false;
                }
                if (!row3Chars.contains(lowerC)){
                    row3 = false;
                }

                println("1: {}, 2: {}, 3: {}", row1, row2, row3);

                if (!row1 && !row2 && !row3){
                    break;
                }
            }

            if (row1 || row2 || row3){
                answer.push_back(word);
            }

            row1 = true;
            row2 = true;
            row3 = true;
        }

        return answer;
    }
};