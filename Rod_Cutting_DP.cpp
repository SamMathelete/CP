/*

Rod Cutting using Dynamic Programming
Hint: Cut all possible lengths and find the maximum of it.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

vector<ll> prices;
vector<ll> dp;

ll maxm(ll length){
    if(dp[length] + 1) return dp[length];
    ll ans = 0;
    for(ll i = 1; i<=length; i++){
        ans = max(ans, maxm(length - i) + prices[i-1]);
    }
    return dp[length] = ans;
}

int main(){
    ll n;
    cin >> n;
    prices.resize(n, 0);
    dp.resize(n+1, -1);
    for(auto &it : prices){
        cin >> it;
    }
    cout << maxm(n) << E;
    return 0;
}
