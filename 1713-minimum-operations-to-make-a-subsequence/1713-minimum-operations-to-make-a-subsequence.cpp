class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> valueToIndex;
        for (auto i = 0; i < target.size(); i++) valueToIndex[target[i]] = i;

        vector<int> lis;

        for (const auto& value: arr){
            if (!valueToIndex.contains(value)) continue;
            int index = valueToIndex[value];

            if (lis.empty() || lis.back() < index){
                lis.push_back(index);
                continue;
            }
            if (lis.back() == index || lis.front() == index) continue;

            int left = 0;
            int right = lis.size() - 1;
            int middle = -1;

            while (left < right){
                middle = (left + right)/2;

                if (lis[middle] < index){
                    left = middle + 1;
                } else {
                    right = middle;
                }
            }

            lis[left] = index;
        }

        return target.size() - lis.size();
    }
};