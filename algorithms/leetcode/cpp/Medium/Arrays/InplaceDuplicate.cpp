// https://leetcode.com/problems/find-the-duplicate-number/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        // [1,3,4,2,2]
        // -1 -3 -4 -2 
        for(int i=0; i<n; i++) {
            if(nums[abs(nums[i])-1]>0)
                nums[abs(nums[i])-1] = -1*(nums[abs(nums[i])-1]);
            else 
                ans = abs(nums[i]);
        }
        
        return ans;
    }
};
