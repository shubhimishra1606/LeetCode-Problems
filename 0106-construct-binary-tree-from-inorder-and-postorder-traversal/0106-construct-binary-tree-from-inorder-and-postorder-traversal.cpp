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
    TreeNode* buildTreeHelper(vector<int>& inorder,vector<int>& postorder, int inorders, int inordere, int postorders, int postordere, unordered_map<int,int>&idx){
        if(inorders>inordere || postorders>postordere){
            return nullptr;
        }
        int rootVal=postorder[postordere];
        TreeNode* root=new TreeNode(rootVal);
        int inorderRoot=idx[rootVal];
        int leftSub=inorderRoot-inorders;
        root->left=buildTreeHelper(inorder,postorder,inorders,inorderRoot-1,postorders,postorders+leftSub-1,idx);
        root->right=buildTreeHelper(inorder,postorder,inorderRoot+1,inordere,postorders+leftSub,postordere-1,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>idx;
        for(int i=0; i<inorder.size(); i++){
            idx[inorder[i]]=i;
        }
        return buildTreeHelper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,idx);
    }
};