class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> answer;
        int mirrorSize = (intLength + 1) / 2;
        bool isOdd = intLength % 2 == 1;
        long long min = pow(10, mirrorSize - 1);
        long long max = pow(10, mirrorSize) - 1;

        for (const auto &query : queries){
            if (query > 9 * min){
                answer.push_back(-1);
                continue;
            }

            string mirrorString = to_string(min + query - 1);
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