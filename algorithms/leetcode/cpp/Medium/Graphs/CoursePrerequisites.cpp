// https://leetcode.com/problems/course-schedule/
// MEDIUM

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    bool isLoop(vector<int> adj[], int s, vector<bool>& isVisited, vector<bool> recStack) {
        
        isVisited[s] = true;
        recStack[s] = true;
        
        int n = adj[s].size();
        
        for(int i=0; i<n; i++) {
            if(recStack[adj[s][i]])
                return true;
            
            if(!isVisited[adj[s][i]])
                if(isLoop(adj, adj[s][i], isVisited, recStack))
                    return true;
        }
        
        recStack[s] = false;
        return false;

    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[numCourses];
        int e = prerequisites.size();
        
        for(int i=0; i<e; i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);    
        }
        
        vector<bool> isVisited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        
        for(int i=0; i<numCourses; i++) {
            if(isVisited[i])
                continue;
            if(isLoop(adj, i, isVisited, recStack))
                return false;
        }
        
        return true;
        
    }
};

