class Solution {
// private:
//     void DFS(vector<int>& DFSResult, unordered_map<int, unordered_set<int>>& adjListOut, const int& currentNode){
//         while (!adjListOut[currentNode].empty()){
//             int nextNode = *(adjListOut[currentNode].begin());
//             adjListOut[currentNode].erase(nextNode);

//             DFS(DFSResult, adjListOut, nextNode);
//         }

//         DFSResult.push_back(currentNode);
//     }

public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // unordered_map<int, unordered_set<int>> adjListOut;
        // unordered_map<int, unordered_set<int>> adjListIn;
        unordered_map<int, deque<int>> adjList;
        unordered_map<int, int> inDegree, outDegree;

        for (const auto& pair: pairs){
            // adjListOut[pairs[i][0]].insert(pairs[i][1]);
            // adjListIn[pairs[i][1]].insert(pairs[i][0]);
            adjList[pair[0]].push_back(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }

        // bool outDegreeMatchesIn = true;
        int startNode = -1;

        for (const auto& [node, edges]: adjList){
            // if (adjListOut[node].size() == adjListIn[node].size() + 1){
            if (outDegree[node] == inDegree[node] + 1){
                // outDegreeMatchesIn = false;
                startNode = node;
                break;
            }
        }

        if (startNode == -1) startNode = pairs[0][0];

        vector<int> DFSResult;
        stack<int> nodeStack;
        nodeStack.push(startNode);

        while (!nodeStack.empty()){
            int node = nodeStack.top();

            if (!adjList[node].empty()){
                int nextNode = adjList[node].front();
                adjList[node].pop_front();
                nodeStack.push(nextNode);
            } else {
                DFSResult.push_back(nodeStack.top());
                nodeStack.pop();
            }
        }

        // DFS(DFSResult, adjListOut, nodeWithOneMoreOutToIn);
        reverse(DFSResult.begin(), DFSResult.end());

        // int lastNode = DFSResult[0];
        vector<vector<int>> answer;
        for (auto i = 1; i < DFSResult.size(); i++){
            // int node = DFSResult[i];
            answer.push_back({DFSResult[i - 1], DFSResult[i]});
            // lastNode = node;
        }

        return answer;
    }
};