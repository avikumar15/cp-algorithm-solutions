// https://leetcode.com/problems/zigzag-conversion/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        
        if(numRows == 1)
            return s;
        
        string res = "";
        
        for(int i=0; i<n; i += (2*numRows-2)) {
            res += s[i];
        }
        
        for(int i=1; i<numRows-1; i++) {
            
            int j = i;
            int inc = 2*(numRows-i-1);
            
            while(j<n) {
                res += s[j];
                j += inc;
                inc = (2*numRows -2 -inc)%(2*numRows -2);
            }
            
        }
        
        for(int i=numRows-1; i<n; i += (2*numRows-2)) {
            res += s[i];
        }
        
        return res;
        
    }
};