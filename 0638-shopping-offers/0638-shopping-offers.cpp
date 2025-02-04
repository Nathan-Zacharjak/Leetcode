class Solution {
private:
    int directPurchace(const vector<int>& price, const vector<int>& needs){
        int totalPrice = 0;
        for (int i = 0; i < price.size(); i++){
            totalPrice += price[i] * needs[i];
        }
        return totalPrice;
    }
public:
    int shoppingOffers(const vector<int>& price, const vector<vector<int>>& specials, const vector<int>& needs, const int& lastSpecialIndex = 0) {
        int minPrice = directPurchace(price, needs);

        vector<int> newNeeds;
        for (int i = lastSpecialIndex; i < specials.size(); i++){
            newNeeds.clear();
            vector<int> special = specials[i];

            for (int i = 0; i < needs.size(); i++){
                if (needs[i] < special[i]){
                    newNeeds.clear();
                    break;
                }
                newNeeds.push_back(needs[i] - special[i]);
            }

            if (!newNeeds.empty()){
                minPrice = min(minPrice, shoppingOffers(price, specials, newNeeds, i) + special[special.size() - 1]);
            }
        }

        return minPrice;
    }
};