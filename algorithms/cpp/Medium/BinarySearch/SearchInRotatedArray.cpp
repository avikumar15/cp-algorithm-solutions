// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // 4 5 6 7 0 1 2
        int n=nums.size();
        // 0 6
        int l=0, h=n-1;
        int m;
        
        // 20 1 2 3 4 5 6
        // 0 5
        
        // 1 2 3 4 5 6 0
        // 0 5
        
        while(h>l+1) {
            m = (l+h)/2;
            if(nums[h]>nums[m]) {
                h = m;
            } else if(nums[h]<nums[m]) {
                l = m;
            } else {
                
            }
        }
        
        // 0 // 2 // 0
        int p = h;
        
        if(nums[h]>nums[l])
            p=l;
        
        cout<<p<<endl;
        l=0;
        h=p-1;
        int pos=-1;
        
        // 1 2 -3- 4 5 6 7 8
        while(h>l+1) {
            m = (l+h)/2;
            if(nums[m]>target) {
                h=m;
            } else if(nums[m]<target) {
                l=m;
            } else {
                pos = m;
                break;
            }
        }
        
        if(pos!=-1) 
            return pos;
        if(nums[l]==target)
            return l;
        if(h>=0 && nums[h]==target)
            return h;
        
        l=p;
        h=n-1;
        pos=-1;
        
        while(h>l+1) {
            m = (l+h)/2;
            if(nums[m]>target) {
                h=m;
            } else if(nums[m]<target) {
                l=m;
            } else {
                pos = m;
                break;
            }
        }
        
        if(pos!=-1) 
            return pos;
        if(nums[l]==target)
            return l;
        if(h>=0 && nums[h]==target)
            return h;
        return pos;
    }
};

