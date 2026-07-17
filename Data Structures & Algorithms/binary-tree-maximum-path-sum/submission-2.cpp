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
    int maxx;
    int dfs(TreeNode* root) {
        if(root == NULL) return 0;

        int curSum = root->val;
        int sumLeft = dfs(root->left);
        int sumRight = dfs(root->right);

        if(sumLeft > 0) curSum+=sumLeft;
        if(sumRight > 0) curSum+=sumRight;

        maxx = max(maxx, curSum);
        return root->val + max(0, max(sumLeft, sumRight));
    }
    int maxPathSum(TreeNode* root) {
        maxx = INT_MIN;
        dfs(root);
        return maxx;
    }
};
