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
    int  f(TreeNode* root, int k,int &cnt){
        if(root==NULL)return -1;
       int l =  f(root->left,k,cnt);
        if(l!=-1)return l;
        cnt++;
        if(cnt==k)return root->val;
        return f(root->right,k,cnt);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
       return f(root,k,cnt);
    }
};
