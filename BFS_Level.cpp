/*

Breadth First Search Implementation to find level of a node in a graph or tree w.r.t a root node.

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

void bfs(ll vertex){
    queue<ll> q;
    q.push(vertex);
    vis[vertex] = 1;
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
        bfs(i);
    }
    for(ll i = 1; i<=n; i++){
        cout << i sp level[i] << E;
    }
    return 0;
}

