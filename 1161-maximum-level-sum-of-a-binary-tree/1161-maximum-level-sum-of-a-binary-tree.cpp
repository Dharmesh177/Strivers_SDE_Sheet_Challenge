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
    int leveled(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int ans,maxi=INT_MIN;
        int curr=0;
        while(!q.empty()){
            int size = q.size();
            int sum =0;
            
            for(int i=0; i<size; i++){
             TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            curr++;
            if(sum > maxi){
                ans=curr;
                maxi=max(maxi,sum);
            }
        }
        return ans;
    }
    int maxLevelSum(TreeNode* root) {
        return leveled(root);
    }
};