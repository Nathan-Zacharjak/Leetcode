class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> wordCounts;
        string currentWord;

        for (auto& c: paragraph){
            c = tolower(c);
            if (c - 'a' < 0 || c - 'a' > 26){
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

        unordered_set<string> bannedWords;
        for (const auto& word: banned) bannedWords.insert(word);

        int maxCount = 0;
        for (const auto& [word, count]: wordCounts){
            if (maxCount < count && !bannedWords.contains(word)){
                maxCount = count;
                currentWord = word;
            }
        }

        return currentWord;
    }
};