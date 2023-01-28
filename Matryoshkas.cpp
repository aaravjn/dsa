#include <bits/stdc++.h>

using namespace std;


#define endl "\n"
typedef vector<int> vi;

int32_t main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n; cin>>n;
        int arr[n];
        map<int, int> mp;
        for(int i = 0;i<n;i++){ 
            cin>>arr[i];
            mp[arr[i]]++;
        }
        auto i = mp.begin();
        int cnt = i->second;
        int prev_val = i->first, prev_freq = i->second;
        i++;
        for(;i!=mp.end();i++) {
            if(i->first - prev_val == 1){
                if(i->second > prev_freq) {
                    cnt += i->second - prev_freq;
                }
            }
            else cnt += i->second;
            prev_val = i->first;
            prev_freq = i->second;
        }
        cout<<cnt<<endl;
    }
}