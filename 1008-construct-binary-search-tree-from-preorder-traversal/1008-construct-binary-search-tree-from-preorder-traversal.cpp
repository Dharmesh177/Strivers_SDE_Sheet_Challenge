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
    TreeNode* f(vector<int> &preorder,vector<int> &inorder,int size,int preS,int preE, int inS,int inE,map<int,int> &mp){
         if(preS>=size || inS>inE){
          return NULL ;
    }
        int elem = mp[preorder[preS]];
        int nele=elem - inS;
        TreeNode* node = new TreeNode(preorder[preS]);
        node->left = f(preorder,inorder,size,preS+1,preS+nele,inS,elem-1,mp);
        node->right = f(preorder,inorder,size,preS+nele+1,preE,elem+1,inE,mp);
        return node;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        inorder = preorder;
        sort(inorder.begin(),inorder.end());
        
        map<int,int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        int preS=0,inS=0,preE=preorder.size()-1,inE=inorder.size()-1;
        return f(preorder,inorder,preorder.size(),preS,preE,inS,inE,mp);
    }
};