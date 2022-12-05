#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

vector<ll> coins;
vector<ll> dp;

ll minc(ll amt){
    if(amt == 0) return 0;
    if(dp[amt] + 1) return dp[amt];
    ll ans = 1e9;
    for(auto &it : coins){
        if(amt - it >= 0) ans = min(ans, 1+minc(amt-it));
    }
    return dp[amt] = ans;
}

int main(){
    ll n, k;
    cin >> n >> k;
    coins.resize(n, 0);
    dp.resize(k+1, -1);
    dp[0] = 0;
    for(auto &it : coins){
        cin >> it;
    }
    ll ans = minc(k);
    cout << (ans == 1e9 ? -1 : ans) << E;
    return 0;
}