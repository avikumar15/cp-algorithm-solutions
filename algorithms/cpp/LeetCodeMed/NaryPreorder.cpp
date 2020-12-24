// https://leetcode.com/problems/n-ary-tree-preorder-traversal/submissions/
#include<bits/stdc++.h>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    
    void preorder(Node* root, vector<int>& res) {
        
        if(root==NULL)
            return;
        
        int n = root->children.size();
        res.push_back(root->val);
        
        if(n==0)
            return;
        
        
        for(int i=0; i<n; i++) 
            preorder(root->children[i], res);
        
    }
    
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};