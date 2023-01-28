#include <bits/stdc++.h>

using namespace std;


#define endl "\n"
typedef vector<int> vi;
# define int long long

int32_t main(){
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int x; cin>>x;
        if(x % 2 == 0) {
            bool is_possible = 1;
            int a = 0, b = 0;
            int xr = x;
            int ad = x/2;
            int i = 31;
            while((x&(1<<i)) == 0) i--;

            while(i>-1) {
                int k1 = xr&(1<<i);
                int k2 = ad&(1<<i);
                if(!k1 and k2) {
                    
                    a += 1<<i;
                    b += 1<<i;
                }   
                else if(k1 and !k2) {
                    
                    a += 1<<i;
                }
                
                else if(k1 and k2){
                    is_possible = 0; break;
                }
                i--;
            }
            if(is_possible) cout<<a<<' '<<b<<endl;
            else cout<<-1<<endl;
        }
        else cout<<-1<<endl;
    }
}