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
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        bool foundX = false;
        bool foundY = false;

        while (!q.empty() && !foundX && !foundY){
            int layerSize = q.size();

            for (int i = 0; i < layerSize; i++){
                TreeNode* node = q.front();
                q.pop();

                if (node->left != nullptr && node->right != nullptr){
                    if (node->left->val == x && node->right->val == y){
                        return false;
                    } else if (node->right->val == x && node->left->val == y){
                        return false;
                    }
                }

                if (node->val == x){
                    foundX = true;
                } else if (node->val == y){
                    foundY = true;
                }

                if (foundX && foundY){
                    return true;
                }

                if (node->left != nullptr){
                    q.push(node->left);
                }
                if (node->right != nullptr){
                    q.push(node->right);
                }
            }
        }

        return false;
    }
};