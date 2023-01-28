#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

bool solve(int arr[], int n, vector<bool> &dp, int i, int sum, int target, vector<vector<int>> &dp2) {
    if(i == n) {
        if(sum == target) return 1;
        dp[sum] = 1;
        return 0;
    }
    if(dp2[i][sum] != -1) return dp2[i][sum];

    dp2[i][sum] = solve(arr, n, dp, i+1, sum + arr[i], target, dp2) or solve(arr, n, dp, i+1, sum, target, dp2);    
    return dp2[i][sum];
}

int main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++) cin>>arr[i];
    
    int sum = 0;
    for(int i = 0;i<n;i++) {
        sum += arr[i];
    }

    vector<int> ans;
    vector<bool> dp(sum+1);
    vector<vector<int>> dp2(n, vector<int> (sum+1, -1));
    
    for(int i = 1;i<=sum;i++) {
        if(dp[i] or solve(arr, n, dp, 0, 0, i, dp2)) ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(int i = 0;i<ans.size();i++) cout<<ans[i]<<' ';
}