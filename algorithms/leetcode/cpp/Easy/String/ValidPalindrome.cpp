// https://leetcode.com/problems/valid-palindrome-ii/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        // abchaba
        
        int n = s.size();

        if(n<=2)
            return true;
        
        // abba
        // aba
        int init=0;
        bool ans1 = true;
        
        for(int i=0; i<ceil(n/2.0); i++) {
            if(s[i] != s[n-i-1+init]) {
                if(init==1) {
                    ans1 = false;
                    break;
                } else {
                    init = 1;
                }        
            }
        }
        
        reverse(s.begin(), s.end());
        
        init=0;
        bool ans2 = true;
        
        for(int i=0; i<ceil(n/2.0); i++) {
            if(s[i] != s[n-i-1+init]) {
                if(init==1) {
                    ans2 = false;
                    break;
                } else {
                    init = 1;
                }        
            }
        }
        
        
        return ans1||ans2;
        
    }
};

