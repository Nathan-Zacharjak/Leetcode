class Solution {
public:
    vector<string> sortPeople(vector<string>& names, const vector<int>& heights) {
        int n = names.size();
        vector<int> sortedIndexes;
        for (int i = 0; i < n; i++) sortedIndexes.push_back(i);

        sort(sortedIndexes.begin(), sortedIndexes.end(), [&heights](const auto& i1, const auto& i2){
            return heights[i1] > heights[i2];
        });

        vector<string> sortedNames;
        for (const auto& i: sortedIndexes){
            sortedNames.push_back(names[i]);
        }

        return sortedNames;
    }
};