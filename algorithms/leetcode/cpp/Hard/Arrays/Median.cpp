// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int findKth(int vec1[], int vec2[], int k, int n, int m) {        
        // consider n>m
        
        if(m>n) 
            return findKth(vec2, vec1, k, m, n);
        if(m==0){
            return vec1[k-1];}
        if(k==1)
            return min(vec1[0], vec2[0]);
        
        int i = min(n, k/2);
        int j = min(m, k/2);
        
        if(vec1[i-1]>vec2[j-1])
            return findKth(vec1, vec2+j, k-j, n, m-j);
        else 
            return findKth(vec1+i, vec2, k-i, n-i, m);    
    }
    
    double findMedianSortedArrays(vector<int>& vec1, vector<int>& vec2) {
        
        double md;
        
        int n = vec1.size();
        int m = vec2.size();
        
        if(n==0)
            return (vec2[(n+m-1)/2] + vec2[(n+m)/2])*1.0/2.0;
        if(m==0)
            return (vec1[(n+m-1)/2] + vec1[(n+m)/2])*1.0/2.0;
        
        int A[n], B[m];
        
        for(int i=0; i<n; i++)
            A[i] = vec1[i];
        for(int i=0; i<m; i++)
            B[i] = vec2[i];
                
        md = (findKth(A, B, (n+m+1)/2, n, m) + findKth(A, B, (n+m+2)/2, n, m))*1.0/2.0; 
        
        return md;
    }
};