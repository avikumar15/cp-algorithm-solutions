// https://leetcode.com/problems/plus-one/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        reverse(digits.begin(),digits.end());
        int c = 1;
        int i = 0;
        while(i<n && c==1) {
            digits[i]++;
            digits[i] %= 10;
            if(digits[i]!=0)
                c=0;
            i++;
        }
        
        if(c==1)
            digits.push_back(1);
        
        reverse(digits.begin(),digits.end());
        
        return digits;
        
    }
};

