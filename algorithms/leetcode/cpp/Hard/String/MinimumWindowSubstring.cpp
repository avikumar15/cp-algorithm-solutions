// https://leetcode.com/problems/minimum-window-substring/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        
        int m = s.size();
        int n = t.size();
        
        if(t=="")
            return s;
        
        // s = "ADOBECODEBANC", t = "ABC"
        map<char,int> reqd;
        map<char,int> pst;
        
        for(int i=0; i<n; i++) {
            reqd[t[i]]++;
        }
        
        int left=0;
        int right=0;
        int len = INT_MAX;
        int firstInd = 0;
        
        // ab
        // a
        
        bool proceed=false;
        
        for(int i=0; i<=m && left<=right;) {
            
            if(!proceed) {
                pst[s[i]]++;
            }
            
            proceed = true;
            for(auto p:reqd) {
                if(p.second>pst[p.first]) {
                    proceed=false;
                    break;
                }
            }        
            
            if(proceed) {
                if(len>(right-left+1)) {
                    len=right-left+1;
                    firstInd=left;
                }
                
                pst[s[left]]--;
                left++;
            } else {
                if(i==m)
                    break;
                i++;
                right++;
            }
            
        }
        
        if(len==INT_MAX)
            return "";
        else 
            return s.substr(firstInd, len);
        
    }
};

