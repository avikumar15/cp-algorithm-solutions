// https://leetcode.com/problems/find-all-anagrams-in-a-string/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<int> ans;
        
        if(n==0 || m==0 || m>n)
            return ans;
        
        int arr[n+1][26];
        int init[26];
        
        for(int i=0; i<26; i++)
            init[i]=0;
        
        for(int i=0; i<m; i++) {
            init[p[i]-'a']++;    
        }
        
        // cout<<"init is \n";
        // for(int i=0; i<26; i++)
        //     cout<<init[i]<<" ";
        // cout<<endl;
        
        for(int i=0; i<26; i++)
            arr[0][i]=0;
        
        arr[0][s[0]-'a']=1;
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<26; j++)
                arr[i][j]=arr[i-1][j];
            arr[i][s[i]-'a']++;
        }
        
//         cout<<"arr is \n";
        
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<26; j++) {
//                 cout<<arr[i][j]<<" ";
//             }    
//             cout<<endl;
//         }
        
        int fl=1;
        
        for(int i=0; i<26; i++) {
            if(arr[m-1][i] != init[i])
                fl=0;
        }
        
        if(fl==1)
            ans.push_back(0);
        
        for(int i=0; i<n-m; i++) {
            int diff[26];
            int f = 1;
            for(int j=0; j<26; j++){
                diff[j] = arr[i+m][j]-arr[i][j];
                if(diff[j] != init[j])
                    f=0;
            }
            if(f==1)
                ans.push_back(i+1);
        }
        
        return ans;
    }
};

