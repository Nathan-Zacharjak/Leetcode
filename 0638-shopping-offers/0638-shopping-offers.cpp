class Solution {
public:
    int shoppingOffers(const vector<int>& price, const vector<vector<int>>& specials, vector<int>& needs, const int& currentPrice = 0) {
        for (const auto& need: needs){
            if (need < 0){
                return -1;
            }
        }

        int minPrice = 0;
        int n = needs.size();
        for (int i = 0; i < n; i++){
            minPrice += price[i] * needs[i];
        }

        for (const auto& special: specials){
            int specialPrice = special.back();
            if (currentPrice + specialPrice >= minPrice) continue;

            for (int i = 0; i < needs.size(); i++){
                needs[i] -= special[i];
            }

            int result = shoppingOffers(price, specials, needs);
            if (result != -1){
                minPrice = min(minPrice, result + specialPrice);
            }

            for (int i = 0; i < needs.size(); i++){
                needs[i] += special[i];
            }
        }

        return minPrice;
    }
};