class Solution {
public:
    string minimizeStringValue(string s) {
        // Make digit bank of chars (vector with char - 'a')
        vector<int> charCounts(26);
        // Make vector of ? indexes
        vector<int> markIndexes;

        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            if (c == '?'){
                markIndexes.push_back(i);
            } else {
                charCounts[c - 'a']++;
            }
        }

        string insertedChars;

        // Loop for every ? index
        for (const auto &index : markIndexes){
            // Find lowest cost char
            int minCount = charCounts[0];
            char lowestChar = 'a';

            for (int i = 1; i < 26; i++){
                // If tie, choose the smallest letter
                if (charCounts[i] < minCount){
                    minCount = charCounts[i];
                    lowestChar = 'a' + i;
                }
            }

            // Increment count for char by 1
            charCounts[lowestChar - 'a']++;

            insertedChars.push_back(lowestChar);
        }

        sort(insertedChars.begin(), insertedChars.end());

        for (int i = 0; i < markIndexes.size(); i++){
            s[markIndexes[i]] = insertedChars[i];
        }

        // return string
        return s;
    }
};