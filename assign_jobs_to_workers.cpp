#include <bits/stdc++.h>

using namespace std;


#define endl "\n"
typedef vector<int> vi;
# define int long long

int solve(int i, int n, vector<vector<int>> cost, int set){
    if(i == n) return 0;
    int ans = 1e9;
    for(int j = 0;j<n;j++) {
        if(set&(1<<j))
            ans = min(ans, cost[i][j] + solve(i+1, n, cost, set^(1<<j))); 
    }
    return ans;
}

int solveTab(int n, vector<vector<int>> cost) {
    vector<vector<int>> dp(n+1, vector<int> ((1<<n), 0));
    
    for(int i = n-1;i>=0;i--) {
        for(int set = 0;set<(1<<n);set++) {
            int ans = 1e9;
            for(int j = 0;j<n;j++) {
                if(set&(1<<j))
                    ans = min(ans, cost[i][j] + dp[i+1][set^(1<<j)]); 
            }
            dp[i][set] = ans;
        }
    }
    return dp[0][(1<<n)-1];
}

int32_t main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<vector<int>> cost(n, vector<int> (n));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) cin >> cost[i][j];
    }
    vector<vector<int>> dp(n+1, vector<int> ((1<<n), -1));
    cout<<solveTab(n, cost)<<endl;
}