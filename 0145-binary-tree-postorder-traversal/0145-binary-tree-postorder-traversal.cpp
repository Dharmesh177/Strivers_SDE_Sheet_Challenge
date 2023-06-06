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
    void post(TreeNode * curr, vector < int > & preOrder) {
  if (curr == NULL)
    return;

 
  post(curr -> left, preOrder);
  post(curr -> right, preOrder);
                
 preOrder.push_back(curr -> val);
}

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
         post(root,ans);
        return ans;
    }
};