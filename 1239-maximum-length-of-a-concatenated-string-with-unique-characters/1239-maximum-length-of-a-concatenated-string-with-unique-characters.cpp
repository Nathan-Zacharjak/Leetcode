#include <print>

class Solution {
private:
    bool hasDupe(const string& str1, const string& str2){
        vector<bool> charSet(26, false);

        for (const auto& c: str1){
            if (charSet[c - 'a']){
                return true;
            }
            charSet[c - 'a'] = true;
        }

        for (const auto & c: str2){
            if (charSet[c - 'a']){
                return true;
            }
        }

        return false;
    }

    unordered_map<string, int> memo;
    // int callCount = 0;

    int maxForStart(const int& next, string& stringSoFar, const int& n, const vector<string>& arr){
        if (next == n){
            return stringSoFar.size();
        }

        string memoID = to_string(next) + stringSoFar;

        if (memo.contains(memoID)){
            return memo[memoID];
        }
        // println("next: {}, stringSoFar: {}", next, stringSoFar);
        // callCount++;

        int maxSoFar = 0;

        for (int i = next; i < n; i++){
            string nextString = stringSoFar;
            if (!hasDupe(arr[i], stringSoFar)){
                nextString += arr[i];
            }

            int result = maxForStart(i + 1, nextString, n, arr);
            maxSoFar = result > maxSoFar ? result : maxSoFar;
        }

        memo[memoID] = maxSoFar;

        return maxSoFar;
    }

public:
    int maxLength(vector<string>& arr) {
        string stringSoFar;
        // int result = maxForStart(0, stringSoFar, arr.size(), arr);
        // println("Count: {}", callCount);
        return maxForStart(0, stringSoFar, arr.size(), arr);
    }
};