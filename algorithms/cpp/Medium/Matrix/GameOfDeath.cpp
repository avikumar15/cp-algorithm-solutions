// https://leetcode.com/problems/game-of-life/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> res(n, vector<int>(m, 0));
        
        int dirY[] = {-1,0,1,1,1,0,-1,-1};
        int dirX[] = {1,1,1,0,-1,-1,-1,0};
        int cnt = 8;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                int z = 0, o = 0;
                
                for(int c=0; c<cnt; c++) {
                    
                    int X = i + dirX[c];
                    int Y = j + dirY[c];
                    
                    if(X<n && X>=0 && Y<m && Y>=0) {
                        if(board[X][Y]==0)
                            z++;
                        else 
                            o++;
                    }
                    
                }
                
                if(board[i][j]==0) {
                    if(o==3)
                        res[i][j]=1;
                    else 
                        res[i][j]=0;
                } else {
                    if(o<2)
                        res[i][j]=0;
                    else if(o<=3)
                        res[i][j]=1;
                    else
                        res[i][j]=0;
                }
                
                
            }
        }
        
        board = res;
    }
};
