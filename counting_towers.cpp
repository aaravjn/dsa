#include <bits/stdc++.h>

using namespace std;


#define endl "\n"
typedef vector<int> vi;
# define int long long
const int MOD = 1e9+7;
int32_t main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int>> dp(1e6+1, {0, 0}); // {a, b}
    dp[1] = {1, 1};
    for(int i = 2; i <= 1e6;i++) {
        dp[i][0] = (2*dp[i-1][0] % MOD + dp[i-1][1] % MOD) % MOD;
        dp[i][1] = (4*dp[i-1][1] % MOD + dp[i-1][0] % MOD) % MOD;
    }
    int T;
    cin>>T;
    while(T--){
        int n;cin>>n;
        cout<<(dp[n][0] + dp[n][1]) % MOD <<endl;
    }
}