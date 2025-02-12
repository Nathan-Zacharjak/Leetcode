class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> wordCounts;
        string currentWord;
        int a = 'a';

        for (auto& c: paragraph){
            c = tolower(c);
            int ascii = c - a;

            if (ascii < 0 || ascii > 26){
                if (!currentWord.empty()){
                    wordCounts[currentWord]++;
                    currentWord.clear();
                }
            } else {
                currentWord += c;
            }
        }

        if (!currentWord.empty()){
            wordCounts[currentWord]++;
            currentWord.clear();
        }

        for (const auto& word: banned) wordCounts[word] = 0;

        int maxCount = 0;
        for (const auto& [word, count]: wordCounts){
            if (maxCount < count){
                maxCount = count;
                currentWord = word;
            }
        }

        return currentWord;
    }
};