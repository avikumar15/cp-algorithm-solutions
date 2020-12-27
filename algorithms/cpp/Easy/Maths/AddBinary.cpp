// https://leetcode.com/problems/add-binary/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        int m = a.size();
        int n = b.size();
        int c = 0;
        
        string res="";
        
        int i=0, j=0;
                
        while(i<m && j<n) {
            int sum = a[i]+b[j]+c-'0'-'0';
            c = sum/2;
            res += (sum%2)+'0';
            i++;j++;
        }
        
        while(i<m) {
            int sum = a[i]-'0'+c;
            c = sum/2;
            res += sum%2+'0';
            i++;
        }
        
        while(j<n) {
            int sum = b[j]-'0'+c;
            c = sum/2;
            res += sum%2+'0';
            j++;
        }
            
        
        if(c==1)
            res += '1';
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

