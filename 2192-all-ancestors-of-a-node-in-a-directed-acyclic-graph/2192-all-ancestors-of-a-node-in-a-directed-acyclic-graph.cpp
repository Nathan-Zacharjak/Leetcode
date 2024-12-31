class Solution {
private:
    void DFS(const int ancestor, const vector<vector<int>> &adjList, vector<vector<int>> &ancestors, const int currentNode){
        // Add the ancestor node, if the currently explored node isn't the ancestor itself
        if (currentNode != ancestor){
            ancestors.at(currentNode).push_back(ancestor);
        }

        // For each of the node's children,
        for (const auto &child : adjList.at(currentNode)){
            // If the current parent is not already explored,
            if (ancestors.at(child).empty() || ancestors.at(child).back() != ancestor){
                // DFS down the node's children
                DFS(ancestor, adjList, ancestors, child);
            }
        }
    };

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Create a parent vector of vectors for every node in the graph
        vector<vector<int>> adjList(n);
        for (const auto &edge : edges){
            int parent = edge.at(0);
            int child = edge.at(1);
            adjList.at(parent).push_back(child);
        }

        vector<vector<int>> ancestors(n);
        // For every node,
        for (int node = 0; node < n; node++){
            // DFS down the node
            DFS(node, adjList, ancestors, node);
        }

        // Return the ancestors array
        return ancestors;
    }
};