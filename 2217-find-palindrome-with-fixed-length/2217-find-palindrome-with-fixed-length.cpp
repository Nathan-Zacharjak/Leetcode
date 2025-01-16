class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> answer;
        bool isOdd = intLength % 2 != 0;
        int mirrorSize = intLength / 2;
        if (isOdd){
            mirrorSize += 1;
        }

        string maxQueryString(mirrorSize, '9');
        long long maxQuery = stoll(maxQueryString);

        for (const auto &query : queries){
            long long mirrorNum = pow(10, mirrorSize - 1) + query - 1;
            string mirrorString = to_string(mirrorNum);

            if (mirrorNum > maxQuery){
                answer.push_back(-1);
                continue;
            }

            string mirrorString2 = mirrorString;
            if (isOdd){
                mirrorString2.pop_back();
            }

            reverse(mirrorString2.begin(), mirrorString2.end());
            mirrorString += mirrorString2;

            answer.push_back(stoll(mirrorString));
        }

        return answer;
    }
};