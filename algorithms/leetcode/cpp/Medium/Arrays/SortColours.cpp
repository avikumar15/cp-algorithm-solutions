// https://leetcode.com/problems/sort-colors/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int r=0, w=0, b=0;
        for(int i=0; i<n; i++) {
            if(nums[i]==0)
                r++;
            else if(nums[i]==1)
                w++;
            else 
                b++;
        }
        for(int i=0; i<n; i++) {
            if(i<r) 
                nums[i] = 0;
            else if(i<(r+w))
                nums[i] = 1;
            else 
                nums[i] = 2;
        }
    }
};