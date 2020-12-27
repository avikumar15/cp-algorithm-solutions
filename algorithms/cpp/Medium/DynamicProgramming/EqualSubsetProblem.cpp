// https://leetcode.com/problems/partition-equal-subset-sum/submissions/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            sum += nums[i];    
        }
        
        if(sum%2==1)
            return false;
        
        sum /= 2;
        
        int dp[sum+1][n+1];
        
        // 1 5 11 5
        // sum = 11
        
        for(int i=0; i<n+1; i++)
            dp[0][i]=1;
        for(int i=1; i<sum+1; i++)
            dp[i][0]=0;
        
        for(int i=1; i<sum+1; i++) {
            for(int j=1; j<n+1; j++) {
                if(i<nums[j-1]) {
                    dp[i][j]=dp[i][j-1];
                } else {
                    if(dp[i][j-1]==1)
                        dp[i][j]=1;
                    else
                        dp[i][j] = dp[i-nums[j-1]][j-1];
                }
            }
        }
        
        return dp[sum][n];
    }
};

