class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if (n < k) return false;

        vector<int> charCounts(26, 0);
        int a = 'a';
        for (const auto& c: s) charCounts[c - a]++;

        int oddCharCounts = 0;

        for (const auto& count: charCounts){
            if (count % 2 != 0){
                oddCharCounts++;
            }
        }

        return oddCharCounts <= k;
    }
};