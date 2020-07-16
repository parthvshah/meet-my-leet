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
    TreeNode* makeRoot(string S) {
        int value = 0;
        int i = 0;
        int place = 1;
        
        while(S[i]!='-')
        {
            value += (S[i] - '0')*place;
            place *= 10;
            i++;
        }
        TreeNode* root = new TreeNode(value);
        return root;
    }
    
    TreeNode* recoverFromPreorder(string S) {
        TreeNode *root = makeRoot(S);
        
        // value, level
        map<int, int> tree;
        int value = 0;
        int place = 1;
        bool inDashes = false;
        
        for(int i=S.size()-1; i>=0; i--)
        {
            if(S[i]=='-')
            {
                inDashes = true;
               
                if(tree.count(value) != 0)
                    tree[value] += 1;
                else
                {
                    tree.insert(make_pair(value, 1));
                    place = 1;
                }
            }
            else
            {
                if(inDashes)
                {
                    value = 0;
                    inDashes = false;
                }
                value += (S[i] - '0')*place;
                place*=10;
            }
        }
        
        vector<pair<int, int>> sTree;
        
        
        for(auto elem:tree) 
            sTree.pb(elem);
        
        sort(sTree.begin(), sTree.end(),
             [](auto &left, auto &right) {
                return left.second < right.second;
        });
        
        int curLevel = 1;
        TreeNode *curNode = root;
        
        for(int i=0; i<sTree.size(); ++i)
        {
            cout<<sTree[i].first<<" "<<sTree[i].second<<endl;
            
        }
            
        
        return root;
    }
};