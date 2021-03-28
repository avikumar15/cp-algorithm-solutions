// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), 
};

class Solution {
public:
    
    void inorder(TreeNode* root, int& k, int& ans) {
        if(root==NULL)
            return;
        if(k<0)
            return;
        
        inorder(root->left,k,ans);
        
        k--;
        if(k==0) {
            ans = root->val;
        }
        
        inorder(root->right,k,ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        inorder(root,k,ans);
        return ans;
    }
};

