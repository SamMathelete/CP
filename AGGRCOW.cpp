/*

Question at: https://www.spoj.com/problems/AGGRCOW/

*/


#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

ll c;
ll n;
vector<ll> stalls;

bool iscowplaced(ll mindist){
    ll c1 = c;
    ll last_pos = -1;
    for(auto &it : stalls){
        if(it - last_pos >= mindist || last_pos == -1){
            c1--;
            last_pos = it;
        }
        if(c1 == 0) break;
    }
    return c1 == 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll inp;
        cin >> n >> c;
        for(ll i = 0; i<n; i++){
            cin >> inp;
            stalls.pb(inp);
        }
        sort(stalls.begin(), stalls.end());
        ll lo = 0, hi = 1e9, mid;
        while(hi - lo > 1){
            mid = (hi+lo)/2;
            if(iscowplaced(mid)){
                lo = mid;
            }
            else{
                hi = mid-1;
            }
        }
        if(iscowplaced(hi)){
            cout << hi << E;
        }
        else{
            cout << lo << E;
        }
        stalls.clear();
    }
    return 0;
}