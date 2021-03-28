// https://leetcode.com/problems/score-of-parentheses/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {

        int ans=0;
        int cnt=0;
        
        int n=S.size();
        
        for(int i=0; i<n-1; i++) {
            
            if(S[i]=='(') {
                if(S[i+1]==')') {
                    ans += pow(2, cnt);
                }
                cnt++;
                
            } else {
                cnt--;
            }
            
        }
        
        
        return ans;
        
    }
};
