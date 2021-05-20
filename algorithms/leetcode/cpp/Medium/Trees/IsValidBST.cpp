// https://leetcode.com/problems/validate-binary-search-tree/
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    int l = -1;
    bool f = true;
    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        
        bool leftMost = isValidBST(root->left);
        
        if(!leftMost)
            return false;
        
        if(f) {
            l = root->val;
            f = false;
        } else {
            if(l>=root->val)
                return false;
            l = root->val;
        }
        
        bool rightMost = isValidBST(root->right);
        
        return (leftMost&&rightMost);
        
    }
};
