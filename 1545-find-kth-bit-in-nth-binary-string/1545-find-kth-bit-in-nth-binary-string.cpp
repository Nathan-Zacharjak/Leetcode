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

public:
    char findKthBit(int n, int k) {
        string s = "0";

        for (int i = 1; i < n; i++){
            // string inverted = to_string(~stoi(s));

            string inverted = invert(s);
            reverse(inverted.begin(), inverted.end());
            s = s + "1" + inverted;
        }

        return s.at(k - 1);
    }
};