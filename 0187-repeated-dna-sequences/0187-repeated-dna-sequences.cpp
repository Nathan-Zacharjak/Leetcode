class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> answer;
        if (s.size() < 10) return answer;
        string ogString = s;

        for (auto& c: s){
            switch(c){
                case 'A': c = 0; break;
                case 'C': c = 1; break;
                case 'G': c = 2; break;
                case 'T': c = 3; break;
            }
        }

        bitset<20> bitmask;
        unordered_map<bitset<20>, bool> seenBitmasks;

        for (auto i = 0; i < s.size(); i++){
            // 2 * 10 = 20
            // 11 = 3 in binary, max size label
            // So represent each letter as a 2-bit number, and move over the bits by 2
            // for each iteration to simulate a sliding window
            // as the leftmost bits will be deleted, and 00 will be added to the end
            // allowing us to OR with the bitmask and add the rightmost character in!

            bitmask <<= 2;
            bitmask |= (int)s[i];

            if (i < 9) continue;

            if (seenBitmasks.contains(bitmask)){
                if (seenBitmasks[bitmask] == false){
                    seenBitmasks[bitmask] = true;
                    answer.push_back(ogString.substr(i - 9, 10));
                }
            } else {
                seenBitmasks[bitmask] = false;
            }
        }

        return answer;
    }
};