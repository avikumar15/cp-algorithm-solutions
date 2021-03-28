// https://leetcode.com/problems/top-k-frequent-elements/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            mp[nums[i]] = 0;    
        }
        
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;    
        }
        
        priority_queue<pair<int,int>> pq;
        
        for(auto i:mp) {
            pq.push({i.second, i.first});
        }
        
        vector<int> res;
        
        for(int i=0; i<k; i++) {
            pair<int,int> tp = pq.top();
            res.push_back(tp.second);
            pq.pop();
        }
        
        return res;
        
    }
};