class Solution {
private:
    int Find(const int &node, vector<int> &parent){
        if (node == parent[node]){
            return node;
        }

        // Path compression
        return parent[node] = Find(parent[node], parent);
    }

    void Union(const int &from, const int &to, vector<int> &parent, vector<int> &size){
        int parentFrom = Find(from, parent);
        int parentTo = Find(to, parent);

        if (parentFrom != parentTo){
            if (size[parentFrom] > size[parentTo]){
                parent[parentTo] = parentFrom;
            } else if (size[parentFrom] < size[parentTo]){
                parent[parentFrom] = parentTo;
            } else {
                parent[parentTo] = parentFrom;
                size[parentFrom]++;
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Need n-1 connections to connect n computers, so if the size of the connections array is smaller than that, return -1
        if (connections.size() < n-1){
            return -1;
        }

        int backEdgeCount = 0;
       
        // Union-find parent and size vectors:
        // Initilise each element to be in its own set, and each set to have a size of 1
        vector<int> parent(n), size(n);

        for (int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }

        for (const auto &edge : connections){
            int from = edge[0];
            int to = edge[1];

            // For each connection, union every connection
            Union(from, to, parent, size);
        }

        // Count the number of unique values in parent to get the number of disjoint sets
        int disjointSetCount = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++){
            int setNum = Find(i, parent);

            if (!visited[setNum]){
                visited[setNum] = true;
                disjointSetCount++;
            }
        }

        // Return the number of disjoint sets -1
        return disjointSetCount -1;
    }
};