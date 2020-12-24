// https://leetcode.com/problems/max-increase-to-keep-city-skyline/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int initSum = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> cMax(m,0);
        vector<int> rMax(n,0);
        
        for(int i=0; i<m; i++) {
            int mx = grid[0][i];
            for(int j=1; j<n; j++) {
                mx = max(mx,grid[j][i]);
            }
            cMax[i] = mx;
        }
        
        for(int i=0; i<n; i++) {
            int mx = grid[i][0];
            for(int j=1; j<m; j++) {
                mx = max(mx,grid[i][j]);
            }
            rMax[i] = mx;
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++)
                initSum += min(cMax[j], rMax[i])-grid[i][j];
        }
        
        return initSum;
        
    }
};