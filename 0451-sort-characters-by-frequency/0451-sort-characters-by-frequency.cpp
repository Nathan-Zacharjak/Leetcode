class Solution {
public:
    string frequencySort(string s) {
        string answer;
        unordered_map<char, int> sCount;
        for (const auto c: s) sCount[c]++;

        vector<string> countToChars(s.size() + 1);

        for (const auto& [c, count]: sCount){
            countToChars[count].push_back(c);
        }

        for (int i = s.size(); i > 0; i--){
            for (const auto& c: countToChars[i]){
                for (int j = 0; j < i; j++){
                    answer += c;
                }
            }
        }

        return answer;
    }
};