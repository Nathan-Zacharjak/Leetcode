// #include <print>

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sCount(26, 0);
        for (const auto& c: s) sCount[c - 'a']++;

        int charsLeft = s.size();

        for (const auto& c: t){
            if (sCount[c - 'a'] > 0){
                sCount[c - 'a']--;
                charsLeft--;
            }
            // println("c: {}, sCount: {}, charsLeft: {}", c, sCount[c - 'a'], charsLeft);
        }

        return charsLeft;
    }
};