class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> results = {bitset<26>()};
        int maxChars = 0;

        for (const auto& str: arr){
            bitset<26> charBits;
            bool dupeStr = false;
            for (const auto& c: str){
                if (charBits[c - 'a'] == 1){
                    dupeStr = true;
                    break;
                }
                charBits.set(c - 'a');
            }
            if (dupeStr){
                continue;
            }

            for (int i = results.size() - 1; i >= 0; i--){
                if ((charBits & results[i]).any()){
                    continue;
                }
                bitset<26> nextCharBits = charBits | results[i];
                results.push_back(nextCharBits);
                maxChars = max(maxChars, (int)nextCharBits.count());
            }
        }

        return maxChars;
    }
};