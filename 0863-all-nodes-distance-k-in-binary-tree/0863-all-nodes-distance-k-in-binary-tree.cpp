/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mp){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            
            if(p->left){
                mp[p->left]=p;
                q.push(p->left);
            }
            if(p->right){
                mp[p->right]=p;
                q.push(p->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        markParent(root,mp);
        queue<TreeNode* >q;
        q.push(target);
         unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        
        int curr_len =0;
        while(!q.empty()){
            int size = q.size();
            if(curr_len==k) break;
            
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                
                if(mp[curr] && !vis[mp[curr]]){
                    q.push(mp[curr]);
                    vis[mp[curr]]=true;
                }
            }
            curr_len++;
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
        
    }
};