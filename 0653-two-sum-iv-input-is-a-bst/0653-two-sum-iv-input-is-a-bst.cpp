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
  
    void f(TreeNode* root,vector<int> &in){
        if(root==NULL){
            return;
        }
        f(root->left,in);
        in.push_back(root->val);
        f(root->right,in);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
          vector<int> in;
        f(root,in);
        int l=0,r=in.size()-1;
        
        while(l<r){
            if(in[l]+in[r]==k)return true;
            else if(in[l]+in[r] > k){
                r--;
            }else{
                l++;
            }
        }
        return false;
    }
};