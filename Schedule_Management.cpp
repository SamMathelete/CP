/*
Question at: https://codeforces.com/contest/1701/problem/C
*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

bool istimepossible(vector<ll> &ct, ll n, ll t){ //predicate function
    ll restt = 0, restw = 0;
    for(ll i = 0; i<n; i++){
        if(ct[i] <= t){
            restt += (t - ct[i])/2;
        }
        else{
            restw += (ct[i] - t);
        }
    }
    return restt >= restw;
}

void solve(){
    ll n, m, inp;
    cin >> n >> m;
    vector<ll> ct(n, 0);
    for(ll i = 0; i<m; i++){
        cin >> inp;
        ct[inp-1]++;
    }
    ll lo = 0, hi = m;
    while(hi - lo>1){
        ll mid = (hi+lo)/2;
        if(!(istimepossible(ct, n, mid))){
            lo = mid+1;
        }
        else{
            hi = mid;
        }
    }
    if(istimepossible(ct, n, lo)){
        cout << lo << E;
        return;
    }
    cout << hi << E;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}