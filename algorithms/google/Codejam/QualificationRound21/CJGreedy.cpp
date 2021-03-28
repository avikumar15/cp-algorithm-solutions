// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145

#include<bits/stdc++.h>
#define int long long

using namespace std;

int cs = 0;

void printRes(int num) {
    cout<<"Case #"<<cs<<": "<<num<<endl;
}

// 1 2 3 4 5 6
// l=1, r=2
// 1 3 2 4 5 6
// l=1, r=3
// 1 4 2 3 5 6
void reverseList(vector<int>& vec, int l, int r) {
    for(int i=l; i<=l+(r-l)/2; i++) {
        swap(vec[i], vec[r-(i-l)]);
    }
}

// 2 4 6 7 5 3 1
// 1 3 5 7 6 4 2
// 1 2 4 6 7 5 3
// 1 2 3 5 7 6 4
// 1 2 3 4 6 7 5
// 1 2 3 4 5 7 6
// 1 2 3 4 5 6 7

void solve() {
    cs++;

    int x, y;
    string str;

    cin>>x>>y>>str;

    int n = str.size();

    if(str[0]=='?') {
        string s1=str, s2=str;
        
        s1[0]='C';
        char last = 'C';

        for(int i=1; i<n; i++) {
            if(s1[i]=='?')
                s1[i]=last;
            last=s1[i];
        }
        
        int res1 = 0;
        for(int i=1; i<n; i++) {
            if(s1[i]=='C' && s1[i-1]=='J')
                res1 += y;
            else if(s1[i]=='J' && s1[i-1]=='C')
                res1 += x;
        }

        s2[0]='J';
        last = 'J';

        for(int i=1; i<n; i++) {
            if(s2[i]=='?')
                s2[i]=last;
            last=s2[i];
        }
        
        int res2 = 0;
        for(int i=1; i<n; i++) {
            if(s2[i]=='C' && s2[i-1]=='J')
                res2 += y;
            else if(s2[i]=='J' && s2[i-1]=='C')
                res2 += x;
        }

        printRes(min(res1, res2));

    } else {
        // CJ?CC?
        char last = str[0];
        for(int i=1; i<n; i++) {
            if(str[i]=='?')
                str[i]=last;
            last=str[i];
        }
        int res = 0;
        for(int i=1; i<n; i++) {
            if(str[i]=='C' && str[i-1]=='J')
                res += y;
            else if(str[i]=='J' && str[i-1]=='C')
                res += x;
        }
        printRes(res);
    }

}

int32_t main() {
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
