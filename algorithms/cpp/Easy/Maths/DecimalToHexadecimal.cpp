// https://leetcode.com/problems/convert-a-number-to-hexadecimal/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    map<int,char> mp;
    
    string solve(int num) {
        string ans="";
    
        // 16
        // ans = 01
        while(num>0) {
                ans += mp[num%16];
                num /= 16;
            }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string toHex(int num) {
        
        mp[0]='0';
        mp[1]='1';
        mp[2]='2';
        mp[3]='3';
        mp[4]='4';
        mp[5]='5';
        mp[6]='6';
        mp[7]='7';
        mp[8]='8';
        mp[9]='9';
        mp[10]='a';
        mp[11]='b';
        mp[12]='c';
        mp[13]='d';
        mp[14]='e';
        mp[15]='f';
        
        string ans="";
        
        if(num>0) {
            ans = solve(num);
        } else if(num==0) {
            return "0";
        } else {
            u_int n = num;
            while(n>0) {
                ans += mp[n%16];
                n /= 16;
            }
            reverse(ans.begin(), ans.end());
        }
        
        return ans;
    }
};
