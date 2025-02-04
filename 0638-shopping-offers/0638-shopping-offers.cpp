// #include <print>

class Solution {
private:
    unordered_map<string, int> DPArray;

    int DPHelper(const vector<int>& price, const vector<vector<int>>& specials, vector<int> needs, const int& totalPrice, int currentPrice, const int& n){
        // println("\n\ncurrentPrice: {}", currentPrice);
        // println("needs:");
        // for (const auto& need: needs){
        //     print("{} ", need);
        // }
        // print("\n");

        string newKey;
        for (const auto& need: needs){
            newKey += to_string(need) + "#";
        }
        newKey += to_string(currentPrice);
        if (DPArray.contains(newKey)) return DPArray[newKey];

        bool allItemsBought = true;
        for (const auto& need: needs){
            if (need > 0){
                allItemsBought = false;
                break;
            }
        }
        if (allItemsBought) return currentPrice;

        int minPrice = currentPrice;
        int specialIndex = -1;

        for (const auto &special: specials){
            // print("\n");
            specialIndex++;

            int specialPrice = special[n];
            int normalPrice = 0;
            vector<int> newNeeds = needs;
            bool invalidPurchase = false;
            // println("specialPrice: {}, specialIndex: {}", specialPrice, specialIndex);

            for (int i = 0; i < n; i++){
                newNeeds[i] -= special[i];
                normalPrice += special[i] * price[i];
                // println("i: {}, specialAmount: {}, newNeeds: {}", i, special[i], newNeeds[i]);

                if (newNeeds[i] < 0){
                    invalidPurchase = true;
                    break;
                }
            }
            if (invalidPurchase) continue;

            int saving = normalPrice - specialPrice;
            int newPrice = currentPrice - saving;
            // println("saving: {}, newPrice: {}", saving, newPrice);

            // println("Calling after buying special {}", specialIndex);
            // println("newNeeds:");
            // for (const auto& need: newNeeds){
            //     print("{} ", need);
            // }
            // print("\n");
            int result = DPHelper(price, specials, newNeeds, totalPrice, newPrice, n);
            if (result < minPrice){
                minPrice = result;
            }
        }

        // println("Returning min price of: {}", minPrice);
        string key;
        for (const auto& need: needs){
            key += to_string(need) + "#";
        }
        key += to_string(currentPrice);
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

// #include <print>

// class Solution {
// public:
//     int shoppingOffers(vector<int>& price, vector<vector<int>>& specials, vector<int>& needs) {
//         int n = price.size();
//         int totalPrice = 0;

//         for (int i = 0; i < n; i++){
//             totalPrice += price[i] * needs[i];
//         }

//         priority_queue<pair<int, int>> savings;

//         for (int i = 0; i < specials.size(); i++){
//             vector<int> special = specials[i];
//             int specialCost = special[n];
//             int normalPrice = 0;
//             bool oneItemTooMuch = false;

//             for (int j = 0; j < n; j++){
//                 if (special[j] > needs[j]){
//                     oneItemTooMuch = true;
//                     break;
//                 }

//                 normalPrice += special[j] * price[j];
//             }
//             if (oneItemTooMuch || specialCost >= normalPrice) continue;

//             int saving = normalPrice - specialCost;
//             savings.push({saving, i});
//         }

//         while (!savings.empty()){
//             auto [saving, specialIndex] = savings.top();
//             savings.pop();
//             vector<int> special = specials[specialIndex];
            
//             println("saving: {}, specialIndex: {}", saving, specialIndex);
//             println("special:");
//             for (const auto& item: special){
//                 print("{} ", item);
//             }
//             print("\n");

//             bool oneItemTooMuch = false;

//             for (int i = 0; i < n; i++){
//                 if (special[i] > needs[i]){
//                     oneItemTooMuch = true;
//                     break;
//                 }
//             }
//             println("oneItemTooMuch: {}", oneItemTooMuch);
//             if (oneItemTooMuch) continue;

//             vector<int> newNeeds = needs;
//             int specialPurchaces = 0;
//             bool hasStock = true;

//             while (hasStock){
//                 vector<int> purchaceNeeds = newNeeds;

//                 for (int i = 0; i < n; i++){
//                     if (newNeeds[i] - special[i] < 0){
//                         hasStock = false;
//                         break;
//                     }
//                     purchaceNeeds[i] -= special[i];
//                 }
//                 if (hasStock){
//                     specialPurchaces++;
//                     newNeeds = purchaceNeeds;
//                 }
//             }

//             println("totalPrice: {}, saving: {}, specialPurchaces: {}", totalPrice, saving, specialPurchaces);
//             totalPrice -= saving * specialPurchaces;
//             needs = newNeeds;
//         }

//         return totalPrice;
//     }
// };