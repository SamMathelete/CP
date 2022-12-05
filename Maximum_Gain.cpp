/*

    author: SamTheMathlete
    submitted on: 2022-07-10 15:30:37

*/

/*
Great One on Prefix and Suffix Sum
*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

void solve(ll t){
    ll n, m, k, ans = 0;
    cin >> n;
    vector<ll> v1(n);
    for(auto &it: v1){
        cin >> it;
    }
    cin >> m;
    vector<ll> v2(m);
    for(auto &it : v2){
        cin >> it;
    }
    cin >> k;
    vector<ll> ps1(n+1, 0), ss1(n+1, 0);
    vector<ll> ps2(m+1, 0), ss2(m+1, 0);
    for(ll i = 1; i<=n; i++){
        ps1[i] = v1[i-1] + ps1[i-1];
        ss1[i] = v1[n-i] + ss1[i-1];
    }
    for(ll i = 1; i<=m; i++){
        ps2[i] = v2[i-1] + ps2[i-1];
        ss2[i] = v2[m-i] + ss2[i-1];
    }
    for(ll i = 0; i<=k; i++){
        ll ter1, ter2;
        ter1 = (i > n ? n : i);
        ter2 = (k-i > m ? m : k-i);
        if(ter1 + ter2 < k){
            continue;
        }
        ll maxa = 0, maxb = 0;
        for(ll j = 0; j<=i; j++){
            ll a11 = ps1[j]+ss1[i-j];
            maxa = max(a11, maxa);
        }
        for(ll j = 0; j<=k-i; j++){
            ll a22 = ps2[j]+ss2[k-i-j];
            maxb = max(a22, maxb);
        }
        ans = max(ans, maxa+maxb);
    }
    cout << "Case #"<< t << ": " << ans << E;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    for(ll j = 0; j<t; j++){
        solve(j+1);
    }
    return 0;
}
