/*

Question At: https://atcoder.jp/contests/dp/tasks/dp_a

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll N = 1e5+10;
vector<ll> dp(N, -1);
vector<ll> ht(N, 0);

ll jump(ll i, ll k){
    if(dp[i] + 1) return dp[i];
    ll cost = 1e9;
    for(ll j = 1; j<=k && i-j >= 0; j++){
        cost = min(cost, jump(i-j, k) + abs(ht[i] - ht[i-j]));
    }
    return dp[i] = cost;
}

int main(){
    dp[0] = 0;
    ll n, k; 
    cin >> n >> k;
    for(ll i = 0; i<n; i++){
        cin >> ht[i];
    }
    cout << jump(n-1, k) << E;
    return 0;
}