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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans ;
        if(root==NULL) {return ans;}
        queue<TreeNode*>qu;
        qu.push(root) ;
      
        while(!qu.empty()) {
           
            int x = qu.size() ;
            for(int i=0;i<x;i++) {
                TreeNode*temp = qu.front() ;
                qu.pop() ;

                if(temp->left!=NULL) {qu.push(temp->left) ;}
                if(temp->right!=NULL) {qu.push(temp->right) ;}

                if(i==x-1){
                    ans.push_back(temp->val) ;
                }
            }
        }
        return ans ;
    }
};
