// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

#include <bits/stdc++.h>

using namespace std;

void topo(vector<int> adj[], int crnt, vector<int>& isVisited, stack<int>& st) {
    if(isVisited[crnt]==1)
        return;
    
    isVisited[crnt]=1;
    int n = adj[crnt].size();
    
    for(int i=0; i<n; i++) {
        topo(adj, adj[crnt][i], isVisited, st);
    }
    
    st.push(crnt);
}

// User function Template for C++

/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
*/

string findOrder(string dict[], int N, int K) {
    vector<int> adj[26];
    int n = N;
    int k = K;
    int mx=0;
    map<char,int> mp;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<dict[i].size(); j++) 
            mp[dict[i][j]]=1;
    }
    
    for(int i=0; i<n-1; i++) {
        int mn = min(dict[i].size(), dict[i+1].size());
        for(int p=0; p<mn; p++) {
            if(dict[i][p] != dict[i+1][p]) {
                adj[dict[i][p]-'a'].push_back(dict[i+1][p]-'a');
                break;
            }
            else {
                continue;
            }
        }
    }
    
    stack<int> st;
    vector<int> isVisited(26,0);
    
    for(int i=0; i<26; i++) {
        if(!isVisited[i])
            topo(adj, i, isVisited, st);
    }
    
    string res="";
    
    while(!st.empty()) {
        if(mp.find(st.top()+'a') != mp.end())
            res += st.top()+'a';
        st.pop();
    }
    
    //cout<<res<<endl;
    
    return res;
    
}

