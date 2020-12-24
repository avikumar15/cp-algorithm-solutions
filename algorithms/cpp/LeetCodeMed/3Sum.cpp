// https://leetcode.com/problems/3sum/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        
        for(int i=0; i<n; i++) {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            
            int s = -nums[i];
            
            int l = i+1;
            int h = n-1;
            
            while(l<h) {
                if(nums[l] + nums[h] > s)
                    h--;
                else if(nums[l] + nums[h] < s)
                    l++;
                else {
                    vector<int> temp;
                    
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[h]);
                    
                    h--;
                    l++;
                    
                    if(res.size() != 0) {
                        int rr = res.size();
                        
                        if(temp[0] == res[rr-1][0] && temp[1] == res[rr-1][1]) {
                            continue;
                        }
                            
                    }
                    
                    res.push_back(temp);
                    
                }
                
            }
            
        }
        
        return res;
    }
};
