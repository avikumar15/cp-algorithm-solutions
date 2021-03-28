// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)
            return 0;
        
        map<char,int> lst;
        int ptr = -1;
        int ans = 1;
        
        for(int i=0; i<n; i++) {
            char ch = s[i];
            
            if(i != n-1 && lst.find(ch) == lst.end()){
                lst[ch] = i;
                ans = max(ans, i-ptr);
                continue;
            }
            
            if(lst.find(ch) == lst.end())
                lst[ch] = -1;
            
            ans = max(ans, i-max(ptr, lst[ch]));
            ptr = max(ptr, lst[ch]);
            lst[ch] = i;
            
        }
        
        return ans;
        
    }
};
