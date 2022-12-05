/*

   Factorial using precomputation. O(N) complexity.

   1<=N<=10^5;
   output mod 10^7+9;

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

const int N = 1e5+10;
const int M = 1e7+9;
vector<ll> v(N, 1);

void solve(){
    ll n;
    cin >> n;
    cout << v[n] << E;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(ll i = 1; i<N; i++){
        v[i] = (v[i-1]*i)%M;
    }
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}