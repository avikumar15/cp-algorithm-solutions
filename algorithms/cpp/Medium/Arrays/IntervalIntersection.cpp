// https://leetcode.com/problems/interval-list-intersections/
// MEDIUM

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        // A = [[0,2],[5,10],[13,23],[24,25]] 
        // B = [[1,5],[8,12],[15,24],[25,26]]
        
        int p1=0, p2=0;
        int n=A.size(), m=B.size();
        
        vector<vector<int>> res;
        
        while(p1<n && p2<m) {
            int l = max(A[p1][0], B[p2][0]);
            int h = min(A[p1][1], B[p2][1]);
            
            // 1,2
            
            if(h>=l) {
                vector<int> temp;
                temp.push_back(l);
                temp.push_back(h);
                
                res.push_back(temp);
            }
            
            if(A[p1][1]>B[p2][1]) {
                p2++;
            } else {
                p1++;
            }
            
        }
        
        return res;
        
        
    }
};

