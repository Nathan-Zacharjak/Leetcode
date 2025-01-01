#include <print>

class Solution {
private:
    int charToInt(char c){
        return c - 97;
    }

public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Throw all characters in the allowed string into a hash table array
        array<bool, 26> allowedChars;
        for (const auto & c : allowed){
            println("Char: {}, Index: {}", c, charToInt(c));
            allowedChars.at(charToInt(c)) = true;
        }

        // Create a solution count integer
        int wordCount = 0;

        // Linearly loop through all words in the words array
        for (const auto &word : words){
            bool allowedWord = true;
            // Linearly loop through all characters in each word
            for (const auto &c : word){
                // If the current character is not in the hash table,
                if (!allowedChars.at(charToInt(c))) {
                    // Break out of the loop that prevents incrementing the solution counter
                    allowedWord = false;
                    break;
                }
            }
            if (allowedWord){
                wordCount++;
            }
        }
        
        // Return the solution count
        return wordCount;
    }
};