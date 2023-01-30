#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef vector<int> vi;
# define int long long

int solve(vector<vector<int>> dist, int n, int mask, int i) {
    if(mask == 0) return dist[i][0];
    int ans = 1e9;
    for(int j = 0;j<n;j++) {
        if(mask&(1<<j)) {
            int t = dist[i][j] + solve(dist, n, mask^(1<<j), j);
            ans = min(t, ans);
        }
    }
    return ans;
} 

int32_t main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<vector<int>> dist(n, vector<int> (n, 0));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) cin>>dist[i][j];
    }
    cout<<solve(dist, n, (1<<n)-1, 0);
}
/*
4
0 20 10 12
20 0 15 11
10 15 0 17
12 11 17 0

Ans : 48

5
0 12 10 19 8
12 0  3  7 2
10 3  0  6 20
19 7  6  0 4
8  2  20 4 0

Ans : 32

*/