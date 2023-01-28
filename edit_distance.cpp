#include <bits/stdc++.h>

using namespace std;


#define endl "\n"
typedef vector<int> vi;
# define int long long

int solve(string a, string b, int i, int j, vector<vector<int>> &dp) {
    int n1 = a.length(), n2 = b.length();
    if(i == n1 and j == n2) return 0;
    else if(i == n1) return n2-j;
    else if(j == n2) return n1-i; 
    
    if(dp[i][j] != -1) return dp[i][j];

    int ans;
    if(a[i] == b[j]) ans = solve(a, b, i+1, j+1, dp);
    else {
        int repl = 1 + solve(a, b, i+1, j+1, dp);
        int del = 1 + solve(a, b, i+1, j, dp);
        int add = 1 + solve(a, b, i,j+1, dp);
        ans = min(repl, min(del, add));
    }
    dp[i][j] = ans;
    return ans;
     
}
int solveTab(string a, string b) {
    int n1 = a.length(), n2 = b.length();
    vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, 0));
    for(int j = 0;j<n2;j++) dp[n1][j] = n2-j;
    for(int i = 0;i<n1;i++) dp[i][n2] = n1-i;

    for(int i = n1-1;i>=0;i--) {
        for(int j = n2-1;j>=0;j--) {
            int ans;
            if(a[i] == b[j]) ans = dp[i+1][j+1];
            else {
                int repl = 1 + dp[i+1][j+1];
                int del = 1 + dp[i+1][j];
                int add = 1 + dp[i][j+1];
                ans = min(repl, min(del, add));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int32_t main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a, b;
    cin>>a>>b; 
    cout<<solveTab(a, b);
}