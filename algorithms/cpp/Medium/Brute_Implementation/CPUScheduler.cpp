// https://leetcode.com/problems/task-scheduler/
#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2) {
    if(p1.first>p2.first)
        return true;
    return false;
}

class Solution {
public:
    
    bool isEnded(vector<pair<int,int>> vp) {
        for(int i=0; i<vp.size(); i++)
            if(vp[i].first != 0)
                return false;
        return true;
    }
    
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> chars(26,0);
        
        for(int i=0; i<tasks.size(); i++) {
            chars[tasks[i]-'A']++;
        }
        
        vector<pair<int,int>> vec;
        
        for(int i=0; i<26; i++) {
            if(chars[i]!=0)
                vec.push_back({chars[i],n});
        }
        
        int ans = 0;
        
        while(!isEnded(vec)) {
            sort(vec.begin(), vec.end(), comp);
            bool isFinal = false;
            int n2 = vec.size();
            for(int i=0; i<n2; i++) {
                if(!isFinal && vec[i].second >= n && vec[i].first>0) {
                    isFinal = true;
                    vec[i].second = 0;
                    vec[i].first--;
                } else {
                    vec[i].second++;
                }
            }
            ans++;
        }
        
        return ans;
    }
};

