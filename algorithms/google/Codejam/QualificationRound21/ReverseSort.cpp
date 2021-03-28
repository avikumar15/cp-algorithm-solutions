// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c

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

void solve() {
    cs++;
    int n;
    cin>>n;
    vector<int> vec(n,0);
    for(int i=0; i<n; i++)
        cin>>vec[i];
    int ans=0;

    // 3 5 2 4 1
    for(int i=0; i<n-1; i++) {
        int p=i;
        int mn=vec[i];

        for(int j=i+1; j<n; j++) {
            if(vec[j]<mn) {
                mn = vec[j];
                p = j;
            }
        }
        reverseList(vec, i, p);
        // cout<<p<<" "<<i<<" "<<p-i+1<<endl;
        ans += p-i+1;
    }
    printRes(ans);
}

int32_t main() {
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
