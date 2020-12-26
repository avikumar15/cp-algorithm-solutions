// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int op=0, cl=0;
        int n = s.size();
        string temp = "";
        
        // "))(("
        // ((
        
        // ((())
        // ((())
        for(int i=0; i<n; i++) {
            if(s[i]=='(')
                op++;
            if(s[i]==')')
                cl++;
            if(op >= cl) {
                temp += s[i];
            } else {
                cl--;
            }
        }
        
        string res = "";
        int ex = op-cl;
        n = temp.size();
        
        cout<<temp<<" "<<ex<<endl;
        
        for(int i=n-1; i>=0; i--) {
            if(temp[i]=='(') {
                if(ex-->0) {  
                    
                } else {
                    res += temp[i];
                }
            } else {
                res += temp[i];
            }
            
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

