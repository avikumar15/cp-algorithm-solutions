// https://leetcode.com/problems/shortest-bridge/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    void dfs(vector<vector<int>>& A, queue<pair<int,int>>& q, pair<int,int> p, int n, int m) {
        int i=p.first;
        int j=p.second;
        
        if(i<0 || j<0)
            return;
        if(i>=n || j>=m)
            return;
        if(A[i][j]==0)
            return;
        if(A[i][j]==10)
            return;
        
        A[i][j]=10;
        q.push({i,j});
        
        dfs(A,q,{i+1,j},n,m);
        dfs(A,q,{i-1,j},n,m);
        dfs(A,q,{i,j+1},n,m);
        dfs(A,q,{i,j-1},n,m);
        
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        
        bool found=false;
        queue<pair<int,int>> q;
        
        for(int i=0; i<n && !found; i++) {
            for(int j=0; j<m; j++) {
                if(A[i][j]==1) {
                    pair<int,int> p = {i,j};
                    dfs(A,q,p,n,m);
                    found=true;
                    break;
                }        
            }
        }
        
        int level=0;
        found=false;
        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        
        while(!q.empty()) {
            
            
            queue<pair<int,int>> q2;
            while(!q.empty()) {
                pair<int,int> ft = q.front();
                int i = ft.first;
                int j = ft.second;
                q.pop();
                
                for(int p=0; p<4; p++) {
                    if(i+dirs[p][0]<n && j+dirs[p][1]<m && i+dirs[p][0]>=0 && j+dirs[p][1]>=0) {
                        if(A[i+dirs[p][0]][j+dirs[p][1]]==0) {
                            A[i+dirs[p][0]][j+dirs[p][1]]=10;
                            q2.push({i+dirs[p][0],j+dirs[p][1]});
                        } else if(A[i+dirs[p][0]][j+dirs[p][1]]==1) {
                            found=true;
                            break;
                        }
                    }
                }
            }
            
            if(found)
                break;
            q=q2;
            level++;
            
        }
        
        return level;
        
    }
};

