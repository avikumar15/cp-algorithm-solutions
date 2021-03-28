// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d12d7

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
    int n=5;
    cin>>n;
    vector<int> vec(n,0);
    int c=cs;
    cin>>c;

    for(int i=0; i<n; i++)
        vec[i]=i+1;

    if(c<n-1 || c>(n*(n+1)/2 -1))
        cout<<"Case #"<<cs<<": IMPOSSIBLE\n";
    else if(c==n-1) {
        cout<<"Case #"<<cs<<": ";
        for(int i=0; i<n; i++)
            cout<<vec[i]<<" ";
        cout<<"\n";
    } else {
        // n=5 c=8
        int nd = n-1;
        int s = n-1;
        int sl = 0;
        c -= n-1;
        int cnt = 0;

        while(c>=1) {
            c -= nd;

            cnt++;

            reverseList(vec, sl, s);
            nd--;
            
            if(cnt%2==1)
                s--;
            else
                sl++;

        }

        if(cnt%2==1) {
            s++;
            reverseList(vec, sl, s);
            int len = s-sl+c;
            reverseList(vec, s-len, s);
        } else {
            sl--;
            reverseList(vec, sl, s);
            int len = s-sl+c;
            reverseList(vec, sl, sl+len);
        }

        cout<<"Case #"<<cs<<": ";
        for(int i=0; i<n; i++)
            cout<<vec[i]<<" ";
        cout<<"\n";

    }

}

int32_t main() {
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
