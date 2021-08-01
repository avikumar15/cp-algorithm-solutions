// https://leetcode.com/problems/search-a-2d-matrix/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    bool solve(vector<vector<int>>& matrix, int si, int ei, int m, int target) {
        int mi = (si+ei)/2;
        
        if(si>ei)
            return false;
        if(matrix[mi/m][mi%m]==target)
            return true;
        else if(matrix[mi/m][mi%m]>target)
            return solve(matrix, si, mi-1, m, target);
        else 
            return solve(matrix, mi+1, ei, m, target);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        return solve(matrix, 0, n*m-1, m, target);
    }
};