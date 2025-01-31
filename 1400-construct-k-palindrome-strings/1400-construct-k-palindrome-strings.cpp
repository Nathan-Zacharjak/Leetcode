class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;

        bitset<26> isCharOdd;
        int a = 'a';
        for (const auto& c: s) isCharOdd.flip(c - a);
        
        return isCharOdd.count() <= k;
    }
};