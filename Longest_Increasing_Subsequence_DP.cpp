/*

Longest Increasing Subsequence
Question at: https://leetcode.com/problems/longest-increasing-subsequence/submissions/

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

vector<ll> v;
vector<ll> dp;

ll lis(ll n){
    if(dp[n] + 1) return dp[n];
    ll ans = 1;
    for(ll k = n-1; k>=0; k--){
        if(v[n] > v[k]){
            ans = max(lis(k)+1, ans);
        }
    }
    return dp[n] = ans;
}

int main(){
    ll n; 
    cin >> n;
    v.resize(n, 0);
    dp.resize(n, -1);
    dp[0] = 1;
    for(auto &it : v){
        cin >> it;
    }
    ll ans = 0;
    for(ll i = 0; i<n; i++){
        ans = max(ans, lis(i));
    }
    cout << ans << E;
    return 0;
}
