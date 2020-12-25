// https://leetcode.com/problems/evaluate-division/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    void dfs(map<string,vector<pair<string,double>>> adj, map<string,double>& soTheMap, string st, double crnt) {
        
        if(soTheMap[st]!=(double)(-1.0))
            return;
        
        vector<pair<string,double>> temp = adj[st];
        soTheMap[st] = crnt;
        int n = temp.size();
        
        for(int i=0; i<n; i++) {
            //soTheMap[temp[i].first] = crnt*temp[i].second;
            dfs(adj,soTheMap,temp[i].first,crnt*temp[i].second);
        }
        
        
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size();
        vector<vector<string>> q = queries;
        
        map<string,vector<pair<string,double>>> adj;
        
        for(int i=0; i<n; i++) {
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],(double)(1/values[i])});
        }
        
        vector<double> result;
        
        for(int i=0; i<q.size(); i++) {
            
            if(adj.find(q[i][0])==adj.end() || adj.find(q[i][1])==adj.end()) {
                result.push_back((double)(-1.0));
                continue;
            }
            
            if(q[i][0]==q[i][1]){
                result.push_back((double)1.0);
                continue;
            }

            map<string,double> soTheMap;
            
            for(auto ii: adj) {
                soTheMap[ii.first]=(double)(-1.0);
                
                vector<pair<string,double>> temp = ii.second;
                
                for(int j=0; j<temp.size(); j++)
                    soTheMap[temp[j].first]=(double)(-1.0);
                
            }
            
            dfs(adj,soTheMap,q[i][0],(double)(1.0));
            
            result.push_back(soTheMap[q[i][1]]);
            
        }
        
        return result;
        
    }
};

int main() {

}
