// https://leetcode.com/problems/insert-interval/
#include<bits/stdc++.h>

using namespace std;

bool comp(vector<int> a, vector<int> b) {
    if(a[0]<b[0])
        return true;
    if(a[0]==b[0] && a[1]<b[1])
        return true;
    return false;
}

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), comp);
        int s = 0;
        int n = intervals.size();
        
        // 1,2 3,5 4,8 8,10 12,16
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int sz=1;
        
        for(int i=1; i<n; i++) {
            vector<int> last = res[sz-1];
            if(intervals[i][0]>last[1]) {
                res.push_back(intervals[i]);
                sz++;
            } else {
                res[sz-1][1] = max(res[sz-1][1], intervals[i][1]);
            }
                
        }
        
        return res;
        
    }
};

