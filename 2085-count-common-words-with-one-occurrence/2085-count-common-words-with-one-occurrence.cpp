class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> freq1;
        unordered_map<string, int> freq2;
        for (const auto& word: words1){
            freq1[word]++;
        }
        for (const auto& word: words2){
            freq2[word]++;
        }
        int result = 0;
        for (const auto& [word, freq]: freq1){
            if (freq == 1 && freq2[word] == 1){
                result++;
            }
        }
        return result;
    }
};