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
    void solve(TreeNode* root, int& sum, int& curr){
        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr){
            curr=curr*10+root->val;
            sum+=curr;
            curr/=10;
            return;
        }
        curr=curr*10+root->val;
        solve(root->left, sum, curr);
        solve(root->right, sum, curr);
        curr/=10;
    }
    int sumNumbers(TreeNode* root) {
        int sum=0, curr=0;
        solve(root,sum,curr);
        return sum;
    }
};