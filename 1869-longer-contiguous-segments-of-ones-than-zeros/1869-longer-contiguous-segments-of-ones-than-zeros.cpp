class Solution {
public:
    bool checkZeroOnes(string s) {
        int length0 = 0;
        int length1 = 0;

        int max0 = 0;
        int max1 = 0;
        for (const auto& c : s){
            if (c == '0'){
                length0++;
                length1 = 0;
            }
            if (c == '1') {
                length1++;
                length0 = 0;
            }

            max0 = max(max0, length0);
            max1 = max(max1, length1);
        }

        return max1 > max0;
    }
};