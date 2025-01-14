class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n){
        for (int i = 0; i < n; i++){
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    void Union(int node1, int node2){
        int root1 = Find(node1);
        int root2 = Find(node2);

        if (root1 == root2){
            return;
        }

        if (rank[root1] < rank[root2]){
            parent[root1] = parent[root2];
        } else {
            parent[root2] = parent[root1];

            if (rank[root1] == rank[root2]){
                rank[root1] += 1;
            }
        }
    }

    int Find(int node){
        if (parent[node] == node){
            return node;
        }

        parent[node] = parent[parent[node]];
        return Find(parent[node]);
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        UnionFind disjointSets(n + 1);

        for (const auto &edge : roads){
            disjointSets.Union(edge[0], edge[1]);
        }

        int node1Set = disjointSets.Find(1);

        int runningMin = -1;

        for (const auto &edge : roads){
            if (disjointSets.Find(edge[0]) == node1Set && (edge[2] < runningMin || runningMin == -1)){
                runningMin = edge[2];
            }
        }

        return runningMin;
    }
};