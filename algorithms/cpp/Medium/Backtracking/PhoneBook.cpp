// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    void solve(string digits, int s, int l, vector<string>& res, string str, map<char,vector<char>> mp) {
        
        if(s == l) {
            res.push_back(str);
            return;
        }
        
        vector<char> vc = mp[digits[s]];
        int n = vc.size();
        
        for(int i=0; i<n; i++) {
            str[s] = vc[i];
            solve(digits, s+1, l, res, str, mp);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        map<char,vector<char>> mp;
        vector<string> res;

        int n = digits.size();
        
        if(n == 0)
            return res; 
        
        char ch = 'a';
        char num = '2';

        while(num<='9') {
            for(int i=0; i<3; i++)
                mp[num].push_back(ch++);
            if(num == '7' || num == '9')
                mp[num].push_back(ch++);
            
            num++;
        }
                
        string temp(digits.size(),' ');
        
        solve(digits, 0, n, res, temp, mp);
        
        return res;
        
    }
};
