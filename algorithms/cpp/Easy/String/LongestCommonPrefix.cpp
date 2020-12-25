// https://leetcode.com/problems/longest-common-prefix/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        
        if(n == 0)
            return ans;
        
        int smSize = strs[0].size();
        
        for(int i=1; i<n; i++) 
            smSize = min(smSize, (int) strs[i].size());
        
        for(int i=0; i<smSize; i++) {
            char crnt = strs[0][i];
            bool flag = true;
            
            for(int j=1; j<n; j++) {
                if(crnt != strs[j][i]) 
                    flag = false;
            }
            
            if(!flag)
                break;
            else 
                ans += crnt;
            
        }
        
        return ans;
        
    }
};
