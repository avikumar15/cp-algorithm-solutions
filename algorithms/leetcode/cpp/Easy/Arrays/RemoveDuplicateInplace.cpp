// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int crnt = 1;
        int n = nums.size();
        
        if(n==0)
            return n;
        
        for(int i=1; i<n; i++) {
            if(nums[i]==nums[i-1]) {
                continue;
            }
            nums[crnt++] = nums[i];
        }
        
        return crnt;
    }
};

