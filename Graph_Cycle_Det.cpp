/*

Cycle Detection in a Graph

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
vector<bool> vis(N, 0);

bool dfs(ll vertex, ll parent){
    vis[vertex] = 1;
    bool isLoopExists = 0;
    for(ll child : g[vertex]){
        if(vis[child] && child == parent) continue;
        else if(vis[child]){
            return 1;
        }
        isLoopExists |= dfs(child, vertex);
    }
    return isLoopExists;
}

int main(){
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i<m; i++){
        ll v1, v2;
        cin >> v1 >> v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    for(ll i = 1; i<=n; i++){
        if(vis[i]) continue;
        if(dfs(i, i)){
            cout << "YES" << E;
            return 0;
        }
    }
    cout << "NO" << E;
    return 0;
}
