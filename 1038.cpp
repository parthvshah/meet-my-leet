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
#define pb push_back
class Solution {
public:
    vector<int> res;

    map<int, int> newVal;
    void inOrder(TreeNode* root, bool set){
        if(root->left) inOrder(root->left, set);
        if(set)
            root->val = newVal[root->val];
        else
            res.pb(root->val);
        if(root->right) inOrder(root->right, set);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        inOrder(root, false);
        
        
        int cSum = res.back();
        newVal.insert({cSum, cSum});
        for(int i = res.size()-2; i>=0; i--)
        {
            newVal.insert({res[i], res[i]+cSum});
            cSum+=res[i];
        }
        
        inOrder(root, true);
        
        return root;
    }
};