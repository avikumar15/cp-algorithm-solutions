// https://leetcode.com/problems/rotate-image/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int s = 0;
        int n = matrix.size();
        
//         for(int i=0; i<n; i++) { 
//             for(int j=0; j<n; j++)
//                 cout<<matrix[i][j]<<" ";
//             cout<<endl;
//         }
        
//         cout<<endl;
        
        for(int i=s; i<n/2; i++) {
            for(int j=0; j<n-i-i-1; j++) {
                
                int f1= matrix[i][i+j];
                int f2= matrix[i+j][n-i-1];
                int f3= matrix[n-i-1][n-i-j-1];
                int f4= matrix[n-i-j-1][i];
                
                int t = f1;
                f1=f4;
                f4=f3;
                f3=f2;
                f2=t;
                
                // cout<<i<<" "<<i+j<<" & "<<i+j<<" "<<n-i-1<<" & "<<endl;
                // cout<<n-i-1<<" "<<n-i-j-1<<" & "<<n-i-j-1<<" "<<i<<endl;
                
                // cout<<endl;
                
                matrix[i][i+j] = f1;
                matrix[i+j][n-i-1] = f2;
                matrix[n-i-1][n-i-j-1] = f3;
                matrix[n-i-j-1][i] = f4;
            
            }
        }
        
        // for(int i=0; i<n; i++) { 
        //     for(int j=0; j<n; j++)
        //         cout<<matrix[i][j]<<" ";
        //     cout<<endl;
        // }
        
    }
};