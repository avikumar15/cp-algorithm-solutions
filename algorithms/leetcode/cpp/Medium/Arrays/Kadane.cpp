// https://leetcode.com/problems/maximum-subarray/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int ans = nums[0];
        int finalAns = nums[0];
        
        for(int i=1; i<n; i++) {
            
            ans = max(ans,0);
            ans += nums[i];
            finalAns = max(ans, finalAns);
            
        }
        
        return finalAns;
    }
};
