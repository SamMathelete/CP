/*

There are N students and K toffees. (K < N)
Count the number of ways to distribute toffee among N students
such that each student gets one toffee only.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

const ll M = 1e9+7;
const ll N = 1e7+10;
vector<ll> fact(N);


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

ll mmi(ll n){
    return bin_exp(n, M-2);
}

int main(){
    fact[0] = 1;
    for(ll i = 1; i<N; i++){
        fact[i] = (fact[i-1] * i) % M;
    }
    ll n, k, k1, k2;
    cin >> n >> k;
    k1 = fact[n] % M;
    k2 = (fact[n-k] * fact[k]) % M;
    cout << (k1 * mmi(k2)) % M << E;
    return 0;
}
