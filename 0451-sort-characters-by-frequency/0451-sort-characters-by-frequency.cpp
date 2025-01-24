class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> sCount;        
        for (const auto c: s) sCount[c]++;
        sort(s.begin(), s.end(), [&sCount](const auto& c1, const auto& c2){
            return sCount[c1] > sCount[c2] || (sCount[c1] == sCount[c2] && c1 < c2);
        });
        return s;
    }
};