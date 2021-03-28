// https://leetcode.com/problems/valid-sudoku/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        
        for(int i=0; i<n; i++) {
            vector<int> arr(n,0);
            
            for(int j=0; j<n; j++) {
                if(board[i][j]=='.')
                    continue;
                
                if(arr[board[i][j]-'1']==1) {
                    return false;
                }
                arr[board[i][j]-'1']=1;
                
            }
            
        }
        cout<<"clear1\n";
        
        for(int j=0; j<n; j++) {
            vector<int> arr(n,0);
            
            for(int i=0; i<n; i++) {
                
                if(board[i][j]=='.')
                    continue;
                
                if(arr[board[i][j]-'1']==1) {
                    return false;
                }
                arr[board[i][j]-'1']=1;
                
            }
            
        }
        cout<<"clear2\n";
        
        for(int i=0; i<n; i++) {
            
            vector<int> arr(n, 0);
            
            // 3 3
            int boxVerStart = (i/3)*3;
            int boxHorStart = (i%3)*3;
            
            for(int j=0; j<n/3; j++) {
                
                for(int k=0; k<n/3; k++) {
                    
                    if(board[boxVerStart+j][boxHorStart+k]=='.')
                        continue;
                
                    if(arr[board[boxVerStart+j][boxHorStart+k]-'1']==1) {
                        return false;
                    }
                    arr[board[boxVerStart+j][boxHorStart+k]-'1']=1;
                
                }
                
            }
            
        }
        cout<<"clear3\n";
        
        return true;
        
        
    }
};

