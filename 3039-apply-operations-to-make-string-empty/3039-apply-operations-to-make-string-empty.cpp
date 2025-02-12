class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> charCounts(26, 0);
        vector<int> lastPosition(26, -1);
        int n = s.size();
        int a = 'a';
        int maxCount = 0;

        for (auto i = 0; i < n; i++) {
            charCounts[s[i] - a]++;
            lastPosition[s[i] - a] = i;
            maxCount = max(maxCount, charCounts[s[i] - a]);
        }

        string answer;
        for (auto i = 0; i < 26; i++){
            if (charCounts[i] == maxCount){
                answer += (char)(i + a);
            }
        }

        sort(answer.begin(), answer.end(), [&](const char& c1, const char& c2){
            return lastPosition[c1 - a] < lastPosition[c2 - a];
        });

        return answer;
    }
};