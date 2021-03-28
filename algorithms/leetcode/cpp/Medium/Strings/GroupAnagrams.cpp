// https://leetcode.com/problems/group-anagrams/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        int n = strs.size();
        
        for(int i=0; i<n; i++) {
            string s = strs[i];
            sort(s.begin(),s.end());
            
            mp[s].push_back(strs[i]);
        }
        
        vector<vector<string>> res;
        
        for(auto it:mp) {
            res.push_back(it.second);
        }
        
        return res;
        
    }
};