// https://leetcode.com/problems/generate-parentheses/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    void solve(string str, int s, int n, int opn, vector<string>& res) {
        if(opn > n/2)
            return;
        if(opn < s-opn)
            return;
        
        if(s == n) {
            res.push_back(str);
            return;
        }
        
        str[s] = '(';
        solve(str, s+1, n, opn+1, res);
        
        str[s] = ')';
        solve(str, s+1, n, opn, res);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        n = 2*n;
        string str(n,' ');
        
        solve(str, 0, n, 0, res);
        
        return res;
    }
};
