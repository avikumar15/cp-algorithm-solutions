// https://leetcode.com/problems/product-of-array-except-self/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> pref(n,0);
        vector<int> suff(n,0);
        
        pref[0] = nums[0];
        
        for(int i=1; i<n; i++) {
            pref[i] = pref[i-1]*nums[i];
        }
        
        suff[n-1] = nums[n-1];
        
        for(int i=n-2; i>=0; i--) {
            suff[i] = suff[i+1]*nums[i];
        }
        
        vector<int> ans(n,0);
        ans[0] = suff[1];
        
        for(int i=1; i<n-1; i++)
            ans[i] = pref[i-1]*suff[i+1];
        
        ans[n-1] = pref[n-2];
        
        return ans;
        
    }
};

