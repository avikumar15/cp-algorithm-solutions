// https://leetcode.com/problems/rotate-array/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        for(int i=0; i<n; i++) {
            nums.push_back(nums[i]);    
        }
        
        vector<int> res;
        
        // 2 3 4 5
        for(int i=n-k; i<2*n-k; i++) {
            res.push_back(nums[i]);
        }
        
        nums = res;
    }
};

