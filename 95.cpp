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
    vector<TreeNode*> helper(int start, int end)
    {
        if(start>end)
        {
            vector<TreeNode*> empty;
            return empty; 
        }
        
        vector<TreeNode*> ans;
        
        for(int x = start; x <= end; ++x)
        {
            vector<TreeNode*> left_s = helper(start, x-1);
            vector<TreeNode*> right_s = helper(x+1, end);
            
            for(int i = 0; i < left_s.size(); ++i)
            {
                for(int j = 0; j < right_s.size(); ++j)
                {
                    TreeNode* root;
                    root->val = x;
                    root->left = left_s[i];
                    root->right = right_s[j];
                    
                    ans.push_back(root);
                }
            }
        }
        return ans;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};