// https://leetcode.com/problems/merge-intervals/
#include<bits/stdc++.h>

using namespace std;

bool comp(vector<int> a, vector<int> b) {
        if(a[0]<b[0])
            return true;
        return false;
}

class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> res;
        int sz = 0;
        int n = intervals.size();
        
        for(int i=0; i<n; i++) {
            if(res.size() == 0) {
                res.push_back(intervals[i]);
                sz++;
            } else {
                vector<int> last = res[sz-1];
                if(last[1] >= intervals[i][0]) {
                    last[1] = max(last[1],intervals[i][1]);
                    res[sz-1] = last;
                } else {
                    res.push_back(intervals[i]);
                    sz++;
                }
            }
        }
        
        return res;
        
    }
};

