class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sCount(26, 0);
        int a = 'a';

        for (int i = 0; i < s.size(); i++){
            sCount[s[i] - a]++;
            sCount[t[i] - a]--;
        }

        int charsLeft = 0;

        for (const auto& count: sCount){
            if (count > 0){
                charsLeft += count;
            }
        }

        return charsLeft;
    }
};