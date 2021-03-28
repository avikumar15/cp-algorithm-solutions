// https://leetcode.com/problems/spiral-matrix/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        int i=0, j=0;
        int cs=0;
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        while(i!=-1 && j!=-1 && i!=n && j!=m && matrix[i][j] != -200) {
            
            res.push_back(matrix[i][j]);
            matrix[i][j]=-200;
            
            switch((cs)%4) {
                case 0:
                    j++;
                    if(j==m || matrix[i][j]==-200) {
                        j--;
                        i++;
                        cs++;
                    }
                    break;
                case 1:
                    i++;
                    if(i==n || matrix[i][j]==-200) {
                        i--;
                        j--;
                        cs++;
                    }
                    break;
                case 2:
                    j--;
                    if(j==-1 || matrix[i][j]==-200) {
                        j++;
                        i--;
                        cs++;
                    }
                    break;
                case 3:
                    i--;
                    if(i==-1 || matrix[i][j]==-200) {
                        i++;
                        j++;
                        cs++;
                    }
                    break;
            }    
        }
        
        return res;
        
    }
};
