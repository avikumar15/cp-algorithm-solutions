// https://leetcode.com/problems/roman-to-integer/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mmap;
        
        mmap['I'] = 1;
        mmap['V'] = 5;
        mmap['X'] = 10;
        mmap['L'] = 50;
        mmap['C'] = 100;
        mmap['D'] = 500;
        mmap['M'] = 1000;
        
        int n = s.size();
        
        int ans = 0;
        
        for(int i=0; i<n-1; i++) {
            
            char fir = s[i];
            char sec = s[i+1];
            
            if(mmap[fir] >= mmap[sec]) {
                ans += mmap[fir];
            } else {
                ans -= mmap[fir];
            }
        }
        
        ans += mmap[s[n-1]];
        
        return ans;
        
    }
};
