class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> sCount;
        for (const auto c: s) sCount[c]++;

        string uniqueChars;

        for (const auto& [c, count]: sCount){
            uniqueChars += c;
        }

        sort(uniqueChars.begin(), uniqueChars.end(), [&sCount](const auto& c1, const auto& c2){
            return sCount[c1] > sCount[c2];
        });

        string answer;

        for (const auto& c: uniqueChars){
            while (sCount[c] > 0){
                answer += c;
                sCount[c]--;
            }
        }

        return answer;
    }
};