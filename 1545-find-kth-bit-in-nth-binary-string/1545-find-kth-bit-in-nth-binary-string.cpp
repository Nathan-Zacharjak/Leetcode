// #include <algorithm>
// #include <print>

class Solution {
private:
    string invert(string s){
        for (auto &c : s){
            if (c == '1'){
                c = '0';
            } else {
                c = '1';
            }
        }

        return s;
    };

    string BuildString(const string &lastString, const int &n){
        // println("Last String: {}, n:{}", lastString, n);

        if (n <= 0){
            return lastString;
        }

        string inverted = invert(lastString);
        reverse(inverted.begin(), inverted.end());

        return BuildString(lastString + "1" + inverted, n-1);
    };

public:
    char findKthBit(int n, int k) {
        string s = "0";

        s = BuildString(s, n-1);

        return s.at(k - 1);
    }
};