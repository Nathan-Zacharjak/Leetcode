class Solution {
private:
    int charToInt(char c){
        return c - 'a';
    }

public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Throw all characters in the allowed string into a bit mask array
        int bitMask = 0;

        for (const auto & c : allowed){
            bitMask = bitMask | 1 << charToInt(c);
        }

        // Create a solution count integer
        int wordCount = words.size();

        // Linearly loop through all words in the words array
        for (const auto &word : words){
            // Linearly loop through all characters in each word
            for (const auto &c : word){
                // If the current character is not in the bit mask,
                if ((bitMask >> charToInt(c) & 1) == 0) {
                    // Break out of the loop that prevents incrementing the solution counter
                    wordCount--;
                    break;
                }
            }
        }

        // Return the solution count
        return wordCount;
    }
};