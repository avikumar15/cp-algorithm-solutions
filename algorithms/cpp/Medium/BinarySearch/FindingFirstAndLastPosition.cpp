// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int findLeft(vector<int> nums, int l, int h, int t) {
        int mid = l+(h-l)/2;
        if(h<=l+1) {
            if(nums[l]==t)
                return l;
            if(nums[h]==t)
                return h;
            return -1;
        }
        if(t>nums[mid]) {
            l=mid;
        } else {
            h=mid;
        }
        return findLeft(nums,l,h,t);
    }
    
    int findRight(vector<int> nums, int l, int h, int t) {
        int mid = l+(h-l)/2;
        if(h<=l+1) {
            if(nums[h]==t)
                return h;
            if(nums[l]==t)
                return l;
            return -1;
        }
        if(t>=nums[mid]) {
            l=mid;
        } else {
            h=mid;
        }
        return findRight(nums,l,h,t);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0;
        int right=0;
        
        int n = nums.size();
        
        if(n==0)
            return vector<int> (2,-1);
        
        int l=0,h=n-1;
        
        left = findLeft(nums,l,h,target);
        right = findRight(nums,l,h,target);
        
        vector<int> res;
        res.push_back(left);
        res.push_back(right);
        
        return res;
    }
};

