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
    TreeNode* TraverseTree(TreeNode* node, unordered_set<int> &dVals, vector<TreeNode*> &roots){
        if (!node){
            return nullptr;
        }

        node->left = TraverseTree(node->left, dVals, roots);
        node->right = TraverseTree(node->right, dVals, roots);

        if (dVals.contains(node->val)){
            if (node->left){
                roots.push_back(node->left);
            }

            if (node->right){
                roots.push_back(node->right);
            }

            delete node;
            return nullptr;
        }

        return node;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> dVals(to_delete.begin(), to_delete.end());
        vector<TreeNode*> roots;

        root = TraverseTree(root, dVals, roots);

        if (root){
            roots.push_back(root);
        }

        return roots;
    }
};