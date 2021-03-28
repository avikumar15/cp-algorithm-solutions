// https://leetcode.com/problems/clone-graph/
#include<bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    
    map<Node*, Node*> mp;
    
    Node* cloneGraph(Node* node) {
    
        if(node==NULL)
            return NULL;
        
        Node* newNode = new Node(node->val);
        
        mp[node] = newNode;
        
        int n = (node->neighbors).size();

        for(int i=0; i<n; i++) {
            if(mp.find((node->neighbors)[i]) == mp.end()) {
                (newNode->neighbors).push_back(cloneGraph((node->neighbors)[i]));
            } else {
                (newNode->neighbors).push_back(mp[(node->neighbors)[i]]);
            }
        }
        
        return newNode;
        
    }
};
