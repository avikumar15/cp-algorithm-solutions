// https://leetcode.com/problems/count-and-say/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    void nextSt(string& st) {
        string res = "";
        int n = st.size();
        int crnt = 1;
        
        for(int i=1; i<n; i++) {
            if(st[i]==st[i-1])
                crnt++;
            else {
                res += (to_string(crnt));
                res += st[i-1];
                crnt = 1;
            }
        }
        
        res += (to_string(crnt));
        
        res += st[n-1];
        crnt = 1;
                
        st = res;
    }
    
    string countAndSay(int n) {
        string st = "1";
        int f = 1;
        
        while(f<n) {
            f++;
            nextSt(st);
        }
        
        return st;
    }
};