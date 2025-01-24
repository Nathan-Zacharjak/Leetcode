class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sCount(26, 0);

        for (int i = 0; i < s.size(); i++){
            sCount[s[i] - 'a']++;
            sCount[t[i] - 'a']--;
        }

        int charsLeft = 0;

        for (int i = 0; i < sCount.size(); i++){
            if (sCount[i] > 0){
                charsLeft += sCount[i];
            }
        }

        return charsLeft;
    }
};