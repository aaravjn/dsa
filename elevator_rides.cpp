#include <bits/stdc++.h>

using namespace std;


#define endl "\n"
typedef vector<int> vi;
# define int long long

pair<int, int> solve(int n, int set, int arr[], int x, vector<pair<int, int>> &dp) {
    if(set == 0) return {1, 0};
    
    if(dp[set].first != -1) return dp[set];

    pair<int, int> ans = {n+1, 0};
    for(int i = 0;i < n;i++) {
        if(set&(1<<i)) {
            pair<int, int> t = solve(n, set^(1<<i), arr, x, dp);
            if(t.second + arr[i] <= x) {
                t.second += arr[i];
            }
            else {
                t.first++;
                t.second = arr[i];
            }
            ans = min(ans, t);
        }
    }
    dp[set] = ans;
    return ans;
}


int32_t main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, n;
    cin>>n>>x;
    int arr[n];
    for(int i = 0;i<n;i++) cin>>arr[i];

    vector<pair<int, int>> dp((1<<n), {-1, -1});

    cout<<solve(n, (1<<n)-1, arr, x, dp).first<<endl;

}