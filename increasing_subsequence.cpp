#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef vector<int> vi;
# define int long long

int solve(int i, int prev, int arr[], int n, vector<vector<int>> &dp) {
    if(i == n) return 0;
    if(dp[i][prev] != -1) return dp[i][prev];

    int notTake = solve(i+1, prev, arr, n, dp);
    int take = notTake;
    if(arr[i] > prev) take = solve(i+1, arr[i], arr, n, dp)+1;
    
    dp[i][prev] = max(take, notTake);
    return dp[i][prev];
}
int solveTab(int n, int arr[]) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    for(int i = 0;i<=n;i++) dp[n][i] = 0;

    for(int i = n-1;i>=0;i--) {
        for(int prev = i-1;prev>=-1;prev--) {
            int notTake = dp[i+1][prev+1];
            int take = notTake;
            if(prev == -1 or arr[i] > arr[prev]) take = dp[i+1][i+1]+1;
            dp[i][prev+1] = max(take, notTake);
        }
    }
    return dp[0][0];
}
int solveOpt(int n, int arr[]) {
    vector<int> vec;
    for(int i = 0;i<n;i++) {
        if(vec.size() == 0){
            vec.push_back(arr[i]); 
        }
        else {
            if(vec[vec.size()-1] < arr[i]) vec.push_back(arr[i]);
            else{
                int idx = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
                vec[idx] = arr[i];
            }
        }
    }
    return vec.size();
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++) cin>>arr[i];
    int max_e = 0;
    cout<<solveOpt(n, arr);
}