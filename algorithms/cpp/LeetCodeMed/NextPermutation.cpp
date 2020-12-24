// https://leetcode.com/problems/next-permutation/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 2) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        int i = n-2;
        
        for( ; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                break;
            }
        }
        
        if(i == -1) { // && nums[0] > nums[1]) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        int j = i+2;
        int mn = nums[i+1];
        int pos = i+1;
        
        for( ;j<n; j++) {
            if(nums[j] > nums[i]) {
                if(mn>nums[j]) {
                    mn = nums[j];
                    pos = j;
                }
            }
        }
        
        swap(nums[pos], nums[i]);
        
        sort(nums.begin()+i+1, nums.end());
        
    }
};
