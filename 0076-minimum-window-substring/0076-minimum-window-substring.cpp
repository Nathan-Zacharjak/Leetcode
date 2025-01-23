class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> fm(128, 0);
        for (const auto& c: t) fm[c]++;

        int left = 0;
        int right = 0;
        int missingChars = t.size();
        int minLeft = 0;
        int sSize = s.size();
        int minSize = sSize + 1;

        while (right < sSize){
            // If we haven't already fully withdrawn all of this character from the bank, and it exists in the bank in the first place,
            // then we can mark off another missing character found from t
            if (fm[s[right]] > 0) missingChars--;
            // If char already has been fully taken from the bank, this will be made up for with negative numbers
            fm[s[right]]--;
            right++;

            // If current window has made it so there are no chars left to find, it is valid!
            // We can now start incrementing the left pointer
            while (missingChars == 0){
                // First we need to add the current result, if it is smaller than the last
                if (right - left < minSize){
                    minLeft = left;
                    minSize = right - left;
                }

                // Add a count to the frequency map for the character we're about to leave, since we will need another of this character later
                fm[s[left]]++;

                // Next, since the bank will have very negative values for invalid chars, the bank count for the left char should only be
                // positive if it was a valid char
                if (fm[s[left]] > 0) missingChars++;
                
                // Finally, we can increment the left pointer
                left++;
            }
        }

        return minSize == sSize + 1 ? "" : s.substr(minLeft, minSize);
    }
};