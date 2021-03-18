// https://leetcode.com/problems/set-matrix-zeroes/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int posx=-1;
        int posy=-1;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j]==0) {
                    posx=i;
                    posy=j;
                }
            }
        }
        
        if(posx==-1 && posy==-1)
            return;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j]==0) {
                    matrix[posx][j]=0;
                    matrix[i][posy]=0;
                }
            }
        }
        
        for(int j=0; j<m; j++) {
            if(j==posy)
                continue;
            if(matrix[posx][j]==0) {
                for(int i=0; i<n; i++)
                    matrix[i][j]=0;
            }
        }
        
        for(int i=0; i<n; i++) {
            if(i==posx)
                continue;
            if(matrix[i][posy]==0) {
                for(int j=0; j<m; j++)
                    matrix[i][j]=0;
            }
        }
        
        for(int i=0; i<n; i++)
            matrix[i][posy]=0;
        
        for(int j=0; j<m; j++)
            matrix[posx][j]=0;
        
    }
};
