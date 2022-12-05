/*

    author: SamTheMathlete
    submitted on: "<cmd + k> on me"
    Question at: https://codeforces.com/problemset/problem/295/B

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    const ll N = 511, INF = 1e9;
    vector<vector<ll> > v(N, vector<ll>(N, INF));
    vector<ll> inp(n);
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<n; j++){
            cin >> v[i][j];
        }
    }
    for(ll i = 0; i<n; i++){
        cin >> inp[i];
        inp[i]--;
    }
    reverse(inp.begin(), inp.end());
    vector<ll> ans;
    for(ll k = 0; k<n; k++){
        ll sum = 0;
        for(ll i = 0; i<n; i++){
            for(ll j = 0; j<n; j++){
                v[i][j] = min(v[i][j], v[i][inp[k]]+v[inp[k]][j]);
            }
        }
        for(ll i = 0; i<=k; i++){ //for remaining vertices as others are gone
            for(ll j = 0; j<=k; j++){
                sum += v[inp[i]][inp[j]];
            }
        }
        ans.pb(sum);
    }
    reverse(ans.begin(), ans.end());
    for(auto &it : ans){
        cout << it << " ";
    }
    cout << E;
    return 0;
}