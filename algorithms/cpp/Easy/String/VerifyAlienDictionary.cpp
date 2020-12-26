// https://leetcode.com/problems/verifying-an-alien-dictionary/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    bool isCorrect(string w1, string w2, map<char,int> pr) {
        int n = min(w1.size(),w2.size());
        
        for(int i=0; i<n; i++) {
            if(pr[w1[i]]<pr[w2[i]]) {
                return true;
            } else if(pr[w1[i]]>pr[w2[i]]) {
                return false;
            } else {
                continue;
            }
        }
        
        return (w1.size()<=w2.size());
        
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        int sz=order.size();
        int n=words.size();
        
        map<char,int> mp;
        
        for(int i=0; i<sz; i++) {
            mp[order[i]]=i;        
        }
        
        for(int i=0; i<n-1; i++) {
            if(!isCorrect(words[i],words[i+1],mp))
                return false;
        }
        return true;
    }
};

