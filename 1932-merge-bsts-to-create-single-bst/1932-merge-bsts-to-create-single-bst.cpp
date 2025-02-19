/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // // Checks whether the left or right side of the tree is balanced
    // bool IsValidBST(TreeNode* root, const int& minLeft = INT_MIN, const int& maxRight = INT_MAX){
    //     // Traverse the root of the new tree, and make sure all nodes on that side of the tree are balanced
    //     // Once you hit a leaf node, mark it as balanced
    //     if (root == nullptr) return true;
    //     if (root->val <= minLeft || root->val >= maxRight) return false;

    //     // For left-side addition, DFS the tree
    //     bool leftBalanced = IsValidBST(root->left, minLeft, root->val);
    //     bool rightBalanced = IsValidBST(root->right, root->val, maxRight);

    //     // If the root is reached and passes the balance check, the tree is balanced
    //     return leftBalanced && rightBalanced;
    // }

    bool MakeTree(TreeNode* node, unordered_map<int, TreeNode*>& valToRoot, const int& minLeft = INT_MIN, const int& maxRight = INT_MAX){
        if (node == nullptr) return true;
        if (node->val <= minLeft || node->val >= maxRight) return false;

        // If we're at a leaf node, find a root node to add to our tree traversal!
        if (node->left == nullptr && node->right == nullptr && valToRoot.contains(node->val)){
            auto continueRoot = valToRoot[node->val];
            node->left = continueRoot->left;
            node->right = continueRoot->right;
            valToRoot.erase(node->val);
        }

        return MakeTree(node->left, valToRoot, minLeft, node->val) && MakeTree(node->right, valToRoot, node->val, maxRight);
    }

public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        // Make a map of root node value to root
        unordered_map<int, TreeNode*> valToRoot;
        unordered_map<int, int> valCounts;

        for (const auto& root: trees) {
            valToRoot[root->val] = root;

            valCounts[root->val]++;
            if (root->left != nullptr) valCounts[root->left->val]++;
            if (root->right != nullptr) valCounts[root->right->val]++;
        }

        for (const auto& root: trees){
            if (valCounts[root->val] == 1){
                valToRoot.erase(root->val);

                return MakeTree(root, valToRoot) && valToRoot.empty() ? root : nullptr;
            }
        }

        return nullptr;
    }
};