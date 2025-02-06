class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int, string>> nameQueue;
        for (auto i = 0; i < heights.size(); i++){
            nameQueue.push({heights[i], names[i]});
        }

        vector<string> sortedNames;
        while (!nameQueue.empty()){
            sortedNames.push_back(nameQueue.top().second);
            nameQueue.pop();
        }

        return sortedNames;
    }
};