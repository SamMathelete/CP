/*

Check if a given integer can be formed by sum of some elements of a set.

Hint: Choose the element or not.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

vector<ll> v;
vector<vector<ll> > dp;

bool check(ll ind, ll sum){
    if(sum == 0) return 1;
    if(ind < 0) return 0;
    if(dp[ind][sum] + 1) return dp[ind][sum];
    ll ans = 0;
    ans = check(ind-1, sum);
    if(sum - v[ind] >= 0) ans = ans | check(ind - 1, sum - v[ind]);
    return dp[ind][sum] = ans;
}

int main(){
    ll n, sum, totsum = 0;
    cin >> n >> sum;
    v.resize(n, 0);
    dp.resize(n, vector<ll>(sum+1, -1));
    for(auto &it : v){
        cin >> it;
    }
    cout << (check(n-1, sum) ? "YES" : "NO") << E;
    return 0;
}