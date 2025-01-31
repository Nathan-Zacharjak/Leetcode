class Solution {
public:
    bool canConstruct(string s, int k) {
        // A single character is a palindrome
        // An empty string is *not*

        // abbbccccc
        // cbcbcbcc
        // aaabbbccc
        // abcabcabc
        // aaabbb
        // abbba
        
        // Check there are as many characters as slots
        int n = s.size();
        if (n < k) return false;
        // Check the number of odd character counts are less than or equal to the number of slots
        vector<int> charCounts(26, 0);
        int a = 'a';
        for (const auto& c: s) charCounts[c - a]++;

        int oddCharCounts = 0;

        for (const auto& count: charCounts){
            if (count % 2 != 0){
                oddCharCounts++;
            }
        }

        return oddCharCounts <= k;

        // Fill each slot with 1 set of characters
        // if a slot had an odd number, mark it to not be filled with any other odd number characters
        // 
        // Fill each slot with even numbered characters until an odd numbered one is encountered
        // For every empty slot at the end, try to take as many even number characters to fill the rest 
    }
};