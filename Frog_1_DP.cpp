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

ll jump(ll i){
    if(dp[i] + 1) return dp[i];
    ll cost = 1e9;
    cost = min(cost, jump(i-1) + abs(ht[i-1] - ht[i]));
    if(i > 1) cost = min(cost, jump(i-2) + abs(ht[i-2] - ht[i]));
    return dp[i] = cost;
}



int main(){
    dp[0] = 0;
    ll n; 
    cin >> n;
    for(ll i = 0; i<n; i++){
        cin >> ht[i];
    }
    cout << jump(n-1) << E;
    return 0;
}