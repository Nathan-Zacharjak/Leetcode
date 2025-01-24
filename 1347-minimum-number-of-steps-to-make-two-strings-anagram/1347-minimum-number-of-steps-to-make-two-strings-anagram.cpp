// #include <print>

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> sCount;
        for (const auto& c: s) sCount[c]++;

        int charsLeft = s.size();

        for (const auto& c: t){
            if (sCount.contains(c) && sCount[c] > 0){
                sCount[c]--;
                charsLeft--;
            }
            // println("c: {}, sCount: {}, charsLeft: {}", c, sCount[c], charsLeft);
        }

        return charsLeft;
    }
};