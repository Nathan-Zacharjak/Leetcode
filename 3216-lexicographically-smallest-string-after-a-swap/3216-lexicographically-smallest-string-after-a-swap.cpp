class Solution {
public:
    string getSmallestString(string s) {
        int maxLoops = s.size() - 1;

        for (int i = 0; i < maxLoops; i++){
            int i1 = s[i] - '0';
            int i2 = s[i+1] - '0';

            if (i1 % 2 == i2 % 2 && i1 > i2){
                swap(s[i], s[i+1]);
                return s;
            }
        }

        return s;
    }
};