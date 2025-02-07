class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;

        array<int, 26> s1Freq = {0};
        array<int, 26> s2Freq = {0};
        int differenceCount = 0;
        int n = s1.size();
        int a = 'a';

        for (int i = 0; i < n; i++){
            if (s1[i] != s2[i]){
                differenceCount++;
                if (differenceCount > 2) return false;
            }
            s1Freq[s1[i] - a]++;
            s2Freq[s2[i] - a]++;
        }

        return s1Freq == s2Freq;
    }
};