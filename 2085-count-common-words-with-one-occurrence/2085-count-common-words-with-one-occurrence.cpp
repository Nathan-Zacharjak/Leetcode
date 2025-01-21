class Solution {
private:
    void checkWord(const int& i, const int& n, const vector<string>& words, unordered_map<string, bool>& hashmap){
        if (i >= n){
            return;
        }

        string word = words[i];
        if (hashmap.contains(word)){
            if (hashmap[word] == true){
                hashmap[word] = false;
            }
        } else {
            hashmap[word] = true;
        }
    }

public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, bool> hashmap1;
        unordered_map<string, bool> hashmap2;
        int n1 = words1.size();
        int n2 = words2.size();

        for (int i = 0; i < max(n1, n2); i++){
            checkWord(i, n1, words1, hashmap1);
            checkWord(i, n2, words2, hashmap2);
        }

        int result = 0;
        if (n1 < n2){
            for (const auto& [word, isUnique]: hashmap1){
                if (isUnique && hashmap2.contains(word) && hashmap2[word] == true){
                    result++;
                }
            }
        } else {
            for (const auto& [word, isUnique]: hashmap2){
                if (isUnique && hashmap1.contains(word) && hashmap1[word] == true){
                    result++;
                }
            }
        }

        return result;
    }
};