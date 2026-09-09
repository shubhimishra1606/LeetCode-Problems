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
    void merge(vector<int>& ans, vector<int>& v1, vector<int>& v2){
        int i=0, j=0, n1=v1.size(), n2=v2.size();
        while(i<n1 && j<n2){
            if(v1[i]<=v2[j]){
                ans.push_back(v1[i]);
                i++;
            }else{
                ans.push_back(v2[j]);
                j++;
            }
        }
        while(i<n1){
            ans.push_back(v1[i]);
            i++;
        }
        while(j<n2){
            ans.push_back(v2[j]);
            j++;
        }
    }
    void inorder(TreeNode* root, vector<int>& tree){
        if(root==nullptr) return;
        inorder(root->left,tree);
        tree.push_back(root->val);
        inorder(root->right,tree);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>tree1;
        vector<int>tree2;
        inorder(root1,tree1);
        inorder(root2,tree2);
        vector<int>ans;
        merge(ans,tree1,tree2);
        return ans;
    }
};