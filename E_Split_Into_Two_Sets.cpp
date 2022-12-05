/*

    author: SamTheMathlete
    submitted on: "<cmd + k> on me"

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;
vector<vector<ll> > g(2e5 + 5);
vector<ll> color(2e5 + 5, -1);
ll ans = 1;

void bipartite_check(ll n){
    queue<ll> q;
    for(ll start = 1; start<=n; start++){
        if(color[start] == -1){
            q.push(start);
            color[start] = 0;
            while(!q.empty()){
                ll x = q.front();
                q.pop();
                for(ll child : g[x]){
                    if(color[child] == -1){
                        color[child] = !color[x];
                        q.push(child);
                    }
                    else{
                        ans &= (color[child] != color[x]);
                    }
                }
            }
        }
    }
}

void solve(){
    ans = 1;
    ll n;
    cin >> n;
    for(ll i = 1; i<=n; i++){
        g[i].clear();
        color[i] = -1;
    }
    for(ll i = 0; i<n; i++){
        ll v1, v2;
        cin >> v1 >> v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    bipartite_check(n);
    for(ll i = 1; i<=n; i++){
        if(g[i].size() > 2){
            ans = 0;
            break;
        }
    }
    cout << (ans ? "YES" : "NO") << E;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}