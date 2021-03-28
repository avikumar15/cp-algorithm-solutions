// https://leetcode.com/problems/permutations/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    void solve(vector<int> nums, int c, vector<vector<int>>& res, int n) {
    
        // 1 2 3
        if(c==n-1)
            res.push_back(nums);
        
        for(int i=c; i<n; i++) {
            swap(nums[c], nums[i]);
            solve(nums,c+1,res,n);
            swap(nums[c], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(nums,0,res,nums.size());
        return res;
    }
};

