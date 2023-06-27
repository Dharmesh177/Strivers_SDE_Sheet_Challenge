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
class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushAllL(TreeNode* root){
        if(root==NULL){
            return;
        }
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushAllL(root);
    }
    
    int next() {
        TreeNode* t= st.top();
        st.pop();
        TreeNode* tm = t->right;
         while(tm)
        {
            st.push(tm);
            tm = tm->left;
        }
        return t->val;
        
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

