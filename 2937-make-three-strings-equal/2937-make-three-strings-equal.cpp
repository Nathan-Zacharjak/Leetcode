class Solution {
public:
    int findMinimumOperations(const string &s1, const string &s2, const string &s3) {
        if (s1[0] != s2[0] || s1[0] != s3[0]){
            return -1;
        }

        int minSize = min(s1.size(), min(s2.size(), s3.size()));
        int index = 1;

        while (index < minSize && s1[index] == s2[index] && s1[index] == s3[index]){
            index++;
        }

        return s1.size() + s2.size() + s3.size() -index*3;
    }
};