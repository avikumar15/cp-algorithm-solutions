// https://leetcode.com/problems/k-closest-points-to-origin/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue <pair<int,pair<int,int>>, vector < pair<int,pair<int,int>> > , greater< pair<int,pair<int,int>> > > pq;
        int n = points.size();
        
        for(int i=0; i<n; i++) {
            int f = points[i][0];
            int s = points[i][1];
            
            pq.push({f*f+s*s,{f,s}});
        }
        
        vector<vector<int>> res;
        
        for(int i=0; i<K; i++) {
            pair<int,pair<int,int>> p;
            p = pq.top();
            pq.pop();
            
            vector<int> temp;
            
            temp.push_back(p.second.first);
            temp.push_back(p.second.second);
            
            res.push_back(temp);
        }
        
        return res;
        
    }
};

