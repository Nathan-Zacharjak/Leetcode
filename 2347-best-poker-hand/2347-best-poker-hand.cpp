class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        vector<int> rankCount(14);
        vector<int> suitsCount(4);

        for (int i = 0; i < 5; i++){
            rankCount[ranks[i]]++;
            suitsCount[suits[i] - 'a']++;
        }

        for (int i = 0; i < 4; i++){
            if (suitsCount[i] == 5){
                return "Flush";
            }
        }

        bool pair = false;

        for (int i = 0; i < 14; i++){
            if (rankCount[i] >= 3){
                return "Three of a Kind";
            } else if (rankCount[i] == 2){
                pair = true;
            }
        }

        if (pair){
            return "Pair";
        } else {
            return "High Card";
        }
    }
};