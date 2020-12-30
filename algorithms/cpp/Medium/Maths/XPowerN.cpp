// https://leetcode.com/problems/powx-n/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    double calcPowerWithoutSign(double x, int n) {
        
        int sign = 1;
        if(n<0)
            sign = -1;
        n = abs(n);
        
        if(n==0)
            return 1;
        
        double halfPower = myPow(x,n/2);
        
        if(n%2==0) {
            if(sign==1)
                return halfPower*halfPower;
            else 
                return (1.0/(halfPower*halfPower));
        } else {
            if(sign==1)
                return halfPower*halfPower*x;
            else 
                return 1.0/(halfPower*halfPower*x);
        }
        
    }
    
    double myPow(double x, int n) {
        
        if(x>0 || (abs(n))%2==0)
            return calcPowerWithoutSign(x,n);
        return -calcPowerWithoutSign(abs(x),n);
    }
};

