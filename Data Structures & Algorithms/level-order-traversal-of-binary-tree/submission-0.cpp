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
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> ans ;
        if(root==NULL) {return ans ;}
        queue<TreeNode*>qu;
        qu.push(root) ;
       
        while(!qu.empty()) {
            vector<int> vec ;
            int n = qu.size() ;
            for(int i=0;i<n;i++) {
                TreeNode*temp = qu.front() ;
                qu.pop() ;
                if(temp->left!=NULL) {qu.push(temp->left);}
                if(temp->right!=NULL) {qu.push(temp->right);}
                vec.push_back(temp->val) ;
            }
            ans.push_back(vec);
        }
        return ans ;
    }
};
