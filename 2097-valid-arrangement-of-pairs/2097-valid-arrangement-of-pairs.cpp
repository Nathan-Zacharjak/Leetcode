class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, deque<int>> adjList;
        unordered_map<int, int> inDegree, outDegree;

        for (const auto& pair: pairs){
            adjList[pair[0]].push_back(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }

        int startNode = pairs[0][0];

        for (const auto& [node, edges]: adjList){
            if (outDegree[node] == inDegree[node] + 1){
                startNode = node;
                break;
            }
        }

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
                DFSResult.push_back(node);
                nodeStack.pop();
            }
        }

        vector<vector<int>> answer;
        for (auto i = DFSResult.size() - 1; i > 0; i--){
            answer.push_back({DFSResult[i], DFSResult[i - 1]});
        }

        return answer;
    }
};