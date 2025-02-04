class Solution {
private:
    unordered_map<string, int> DPArray;

    int DPHelper(const vector<int>& price, const vector<vector<int>>& specials, vector<int> needs, const int& totalPrice, int currentPrice, const int& n){
        bool allItemsBought = true;
        for (const auto& need: needs){
            if (need > 0){
                allItemsBought = false;
                break;
            }
        }
        if (allItemsBought) return currentPrice;

        string key;
        for (const auto& need: needs){
            key += to_string(need) + "#";
        }
        
        key += to_string(currentPrice);
        if (DPArray.contains(key)) return DPArray[key];

        int minPrice = currentPrice;

        for (const auto &special: specials){
            int specialPrice = special[n];
            int normalPrice = 0;
            bool invalidPurchase = false;
            vector<int> newNeeds = needs;

            for (int i = 0; i < n; i++){
                newNeeds[i] -= special[i];
                normalPrice += special[i] * price[i];

                if (newNeeds[i] < 0){
                    invalidPurchase = true;
                    break;
                }
            }
            if (invalidPurchase) continue;

            int saving = normalPrice - specialPrice;
            int newPrice = currentPrice - saving;
            
            int result = DPHelper(price, specials, newNeeds, totalPrice, newPrice, n);
            if (result < minPrice){
                minPrice = result;
            }
        }

        DPArray[key] = minPrice;
        return minPrice;
    }

public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& specials, vector<int>& needs) {
        int n = price.size();
        int totalPrice = 0;

        for (int i = 0; i < n; i++){
            totalPrice += price[i] * needs[i];
        }

        return DPHelper(price, specials, needs, totalPrice, totalPrice, n);
    }
};