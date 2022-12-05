/*

Knapsack 1 (0/1 knapsack):
Question at: https://atcoder.jp/contests/dp/tasks/dp_d

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

vector<pair<ll, ll> > v;
vector<vector<ll> > dp;

ll maxm(ll ind, ll W){
    if(ind < 0 || W == 0) return 0;
    if(dp[ind][W] + 1) return dp[ind][W];
    ll sum = 0;
    sum = maxm(ind-1, W);
    if(W - v[ind].first >= 0)
    sum = max(sum, v[ind].second + maxm(ind-1, W-v[ind].first));
    return dp[ind][W] = sum;
}

int main(){
    ll n, w;
    cin >> n >> w;
    v.resize(n, {0,0});
    dp.resize(n, vector<ll>(w+1, -1));
    for(auto &it : v){
        cin >> it.first >> it.second;
    }
    cout << maxm(n-1, w) << E;
    return 0;
}