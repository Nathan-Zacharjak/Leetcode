// #include <print>

class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int size){
        rank = vector<int>(size);
        for (int i = 0; i < size; i++){
            parent.push_back(i);
        }
    }

    int Find(const int& num){
        if (num == parent[num]) return num;
        parent[num] = parent[parent[num]];
        return Find(parent[num]);
    }

    void Union(const int& i1, const int& i2){
        int s1 = Find(i1);
        int s2 = Find(i2);

        if (s1 != s2){
            int r1 = rank[s1];
            int r2 = rank[s2];

            if (r1 > r2){
                parent[s2] = s1;
            } else if (r1 < r2){
                parent[s1] = s2;
            } else {
                parent[s1] = s2;
                rank[s2]++;
            }
        }
    }

};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        // Go through allowedSwaps and find all "swap sets"
        // The disjoint sets of indexes in source that can freely move numbers between themselves
        int n = source.size();
        // println("n: {}", n);

        DSU swapSets(n);

        // Loop through all allowedSwaps,
        for (const auto& swapIndexes: allowedSwaps){
            // Union each pair of start end end indexes
            swapSets.Union(swapIndexes[0], swapIndexes[1]);
        }

        unordered_map<int, unordered_set<int>> setLabelSets;

        for (int i = 0; i < n; i++){
            // For every index in source, call find(i)
            int setLabel = swapSets.Find(i);
            // Find the set label's set in the map, and add the index to that set
            setLabelSets[setLabel].insert(i);
        }

        int distance = 0;

        // For each of these swap sets, find the number of values that are different from the corresponding indexes in target
        for (const auto& [setLabel, swapSet]: setLabelSets){
            // println("Set label: {}", setLabel);

            // Create a temp new set contaning the values in target from these indicies
            unordered_map<int, int> targetValueCounts;
            for (const auto& index: swapSet){
                // targetValues.insert(target[index]);
                targetValueCounts[target[index]]++;
                // print("{} ", index);
            }
            // print("\n");

            // println("Target value counts:");
            // for (const auto& [value, count]: targetValueCounts){
            //     println("value: {}, count: {}", value, count);
            // }

            // Loop through each index in the swap set,
            for (const auto& index: swapSet){
                // If the current value in source is not in the target set, add 1 to the running sum
                if (targetValueCounts.contains(source[index]) && targetValueCounts[source[index]] > 0){
                    targetValueCounts[source[index]]--;
                } else {
                    distance++;
                }
            }
        }

        // Return the running sum
        return distance;
    }
};

// #include <print>

// class Solution {
// private:
//     int DPHelper(vector<int> source, const vector<int>& target, const vector<vector<int>>& allowedSwaps, int& dist, const int& lastSwap){ 
//         for (const auto& num: source){
//             print("{} ", num);
//         }
//         println("dist: {}, lastSwap: {}", dist, lastSwap);

//         if (dist == 0){
//             return 0;
//         }

//         int minDist = dist;

//         // for each swap in swap,
//         for (int i = 0; i < allowedSwaps.size(); i++){
//             // except for the last swap,
//             if (i == lastSwap) continue;
//             // perform the swap,
//             int swapIndex1 = allowedSwaps[i][0];
//             int swapIndex2 = allowedSwaps[i][1];

//             // check if the swap imporves the hamming distance just by comparing the 2 indexes
//             int swapChange = 0;
//             if (source[swapIndex1] == source[swapIndex2]){
//                 swapChange = 0;
//             } else {
//                 if (source[swapIndex2] == target[swapIndex1]){
//                     swapChange++;
//                 }
//                 if (source[swapIndex1] == target[swapIndex2]){
//                     swapChange++;
//                 }
//             }

//             // if it does, call the function after the swap
//             if (swapChange > 0){
//                 int newDist = dist - swapChange;
//                 swap(source[swapIndex1], source[swapIndex2]);
//                 minDist = min(minDist, DPHelper(source, target, allowedSwaps, newDist, i));
//                 swap(source[swapIndex1], source[swapIndex2]);
//             }
//         }

//         // If no allowed swaps improve the hamming distance, return the current running min
//         return minDist;
//     }

// public:
//     int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
//         // Take initial hamming distance
//         int min = 0;
//         for (int i = 0; i < source.size(); i++){
//             // update running min
//             if (source[i] != target[i]){
//                 min++;
//             }
//         }

//         return DPHelper(source, target, allowedSwaps, min, -1);
//     }
// };