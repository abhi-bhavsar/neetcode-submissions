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
    int ans = -1 ;
public:
    void inorder_traversal(TreeNode*root,int& k) {
        if(root==NULL) {return ; }
        
        inorder_traversal(root->left,k) ;
        k-- ;
        if(k==0){
        ans= root->val;
        return;}

        inorder_traversal(root->right,k) ;
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder_traversal(root,k) ;
       return ans;
    }
};
