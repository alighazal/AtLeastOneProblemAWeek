/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*>
    allPossibleBST(int start, int end,
                   map<pair<int, int>, vector<TreeNode*>>& memo) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }

        if (memo.find(make_pair(start, end)) != memo.end()) {
            return memo[make_pair(start, end)];
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> l = allPossibleBST(start, i - 1, memo);
            vector<TreeNode*> r = allPossibleBST(i + 1, end, memo);
            for (auto left : l) {
                for (auto right : r) {
                    TreeNode* root = new TreeNode(i, left, right);
                    res.push_back(root);
                }
            }
        }

        memo[make_pair(start, end)] = res;
        return memo[make_pair(start, end)];
    }

    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> memo;
        return allPossibleBST(1, n, memo);
    }
};
