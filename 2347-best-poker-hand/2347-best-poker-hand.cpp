class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        vector<int> rankCount(14);
        vector<int> suitsCount(4);

        for (int i = 0; i < ranks.size(); i++){
            rankCount[ranks[i]]++;
            suitsCount[suits[i] - 'a']++;
        }

        for (const auto& count: suitsCount){
            if (count == 5){
                return "Flush";
            }
        }

        bool pair = false;

        for (const auto& count: rankCount){
            if (count >= 3){
                return "Three of a Kind";
            } else if (count == 2){
                pair = true;
            }
        }

        if (pair){
            return "Pair";
        }
        
        return "High Card";
    }
};