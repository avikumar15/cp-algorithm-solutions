// https://leetcode.com/problems/3sum-closest/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int mn = abs(target - nums[0] - nums[1] - nums[2]);
        int ans = nums[0] + nums[1] + nums[2];
        
        for(int i=0; i<n; i++) {
            
            int s = target - nums[i];
            
            int l = i+1;
            int h = n-1;
            
            while(l<h) {
                if(mn > abs(s - nums[l] - nums[h])) {
                    mn = abs(s - nums[l] - nums[h]);
                    ans = nums[l] + nums[h] + nums[i];
                }
                
                if(s > nums[l] + nums[h]) {
                    l++;
                } else if(s < nums[l] + nums[h]) {
                    h--;
                } else {
                    break;    
                }
                
            }
            
        }
        
        return ans;
        
    }
};
