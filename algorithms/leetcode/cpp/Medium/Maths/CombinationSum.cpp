// https://leetcode.com/problems/combination-sum/submissions/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    void solve(vector<vector<int>>& ans, vector<int> candidates, int target, int n, vector<int> crnt) {
        if(n<=0 || target<0)
            return;
        if(target==0) {
            ans.push_back(crnt);
            return;
        }
        
        solve(ans, candidates, target, n-1, crnt);
        crnt.push_back(candidates[n-1]);
        solve(ans, candidates, target-candidates[n-1], n, crnt);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> crnt;
        
        int n = candidates.size();
        
        sort(candidates.begin(),candidates.end());
        
        solve(ans, candidates, target, n, crnt);
        
        return ans;
    }
};

