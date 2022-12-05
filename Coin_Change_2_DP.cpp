/*

Coin Change 2
Question at: https://leetcode.com/problems/coin-change-2/submissions/

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

vector<ll> coins;
vector<vector<ll> > dp(301, vector<ll>(5001, -1));

ll ways(ll ind, ll amt){
    if(amt == 0) return 1;
    if(ind < 0) return 0;
    if(dp[ind][amt] + 1) return dp[ind][amt];
    ll ans = 0;
    for(ll i = 0; i<=amt; i+=coins[ind]){       //to prevent multiple permutations of the same combination, we use ordered combinations
        ans += ways(ind-1, amt - i);
    }
    return dp[ind][amt] = ans;
}

int main(){
    ll n;
    cin >> n;
    coins.resize(n, 0);
    for(auto &it : coins){
        cin >> it;
    }
    ll amt;
    cin >> amt;
    cout << ways(n-1, amt) << E;
    return 0;
}