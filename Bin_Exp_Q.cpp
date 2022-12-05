#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll M = 1e9+7;
const ll N = 1e5+10;
vector<ll> fact(N,1);

ll bin_exp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

void solve(){
    ll n, k, k1, k2;
    cin >> n >> k;
    k1 = fact[k];
    k2 = bin_exp(fact[k-n], M-2);
    cout << ((k1 % M) * (k2 % M)) % M << E;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(ll i = 1; i<N; i++){
        fact[i] = (fact[i-1] * i) % M;
    }
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}