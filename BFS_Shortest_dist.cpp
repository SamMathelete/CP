/*

Implementing BFS to find shortest distance between two vertices where all edges have equal weight

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll N = 1e5+10;
vector<vector<ll> > g(N);
vector<ll> vis(N, 0);
vector<ll> level(N, 0);

ll shortestdistance(ll v1, ll v2){
    vector<ll> vis(N, 0);
    vector<ll> level(N, 0);
    queue<ll> q;
    q.push(v1);
    vis[v1] = 1;
    while(!q.empty()){
        ll x = q.front();
        q.pop();
        for(ll child : g[x]){
            if(vis[child]) continue;
            q.push(child);
            vis[child] = 1;
            level[child] = level[x] + 1;
        }
    }
    return level[v2];
}

int main(){
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll v1, v2;
        cin >> v1 >> v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    ll qr;
    cin >> qr;
    while(qr--){
        ll v1, v2;
        cin >> v1 >> v2;
        ll sd = shortestdistance(v1, v2);
        cout << sd << E;
    }
    return 0;
}