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
    int dfs( TreeNode* node, int old_sum  ){
        if (!node){
            return 0;
        }
        old_sum = old_sum * 10 + node->val;

        if (!node->right && !node->left) {
            return old_sum;
        }else{
            return dfs(node->right, old_sum) + dfs(node->left, old_sum);
        }
    }


    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
