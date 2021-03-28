// https://leetcode.com/problems/unique-paths/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int uniquePaths(int m, int n, int i, int j, vector<vector<int>>& dp) {
        if(i<0 || j<0 || i>m-1 || j>n-1)
            return 0;
        if(dp[i][j]!=-10)
            return dp[i][j];
        return dp[i][j]=uniquePaths(m,n,i+1,j,dp) + uniquePaths(m,n,i,j+1,dp);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-10));
        dp[m-1][n-1]=1;
        return uniquePaths(m,n,0,0,dp);
    }
};
