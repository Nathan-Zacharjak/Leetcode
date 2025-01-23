// #include <print>

class Solution {
private:
    void AddSubstringIndexes(int left, const string& s, const int& stringSize, const int& wordSize, const int& wordsLength, const int& substringSize, const unordered_map<string, int>& wordCounts, vector<int>& answer){
        int wordsUsed = 0;
        unordered_map<string, int> wordUseCount;

        // println("Initial left: {}", left);

        for (int right = left; right <= stringSize - wordSize; right += wordSize){
            string word = s.substr(right, wordSize);

            if (!wordCounts.contains(word)){
                // Invalid word, need to completely reset window
                // println("Invalid word: l:{}, r:{}", left, right);
                left = right + wordSize;
                wordsUsed = 0;
                wordUseCount.clear();
            } else {
                wordUseCount[word]++;
                wordsUsed++;
                // println("Found word: {}, wordsUsed: {}", word, wordsUsed);

                // Excess word, clear previous words until no longer at excess
                while (wordUseCount[word] > wordCounts.at(word)){
                    string leftString = s.substr(left, wordSize);
                    wordUseCount[leftString]--;
                    wordsUsed--;
                    left += wordSize;
                    // println("Clearing word: {}, wordUseCount: {}, l:{}, wordsUsed: {}", leftString, wordUseCount[leftString], left, wordsUsed);
                }
            }

            if (wordsUsed == wordsLength){
                // println("Found substring: l:{}, r:{}", left, right);
                // We found a whole valid substring! Lets save it:
                answer.push_back(left);
                // Now we move the window over by 1 word
                string leftString = s.substr(left, wordSize);
                left += wordSize;
                wordsUsed--;
                wordUseCount[leftString]--;
                // println("New left: {}, new right: {}, leftString: {}, wordsUsed: {}, wordUseCount: {}", left, right, leftString, wordsUsed, wordUseCount[leftString]);
            }
        }
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> answer;
        int stringSize = s.size();
        int wordsLength = words.size();
        int wordSize = words[0].size();
        int substringSize = wordsLength * wordSize;

        unordered_map<string, int> wordCounts;
        for (const auto& word: words){
            wordCounts[word]++;
        }

        for (int i = 0; i < wordSize; i++){
            // println("i: {}, wordSize: {}", i, wordSize);
            AddSubstringIndexes(i, s, stringSize, wordSize, wordsLength, substringSize, wordCounts, answer);
            // println("i: {}, wordSize: {}", i, wordSize);
        }

        return answer;
    }
};