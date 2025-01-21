class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> freq;

        for (const auto& word: words1){
            freq[word]++;
        }

        for (const auto& word: words2){
            if (freq.contains(word) && freq[word] < 2){
                freq[word]--;
            }
        }

        int result = 0;
        for (const auto& [word, count]: freq){
            if (count == 0){
                result++;
            }
        }
        return result;
    }
};