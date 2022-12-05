/*

Breadth First Search:
1. Traversal as per level.
2. Implemented using Queue as it requires First In First Out.
3. First input root node in queue and mark it visited.
4. Then, Start emptying queue. For each element exiting from queue, enter all its children into queue and mark them visited.
5. Continue until all are visited.

Breadth first search can be used to find the shortest path to a vertex from a root vertex given all vertices are
equal weighted.

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

void bfs(ll vertex){
    queue<ll> q;
    q.push(vertex);
    vis[vertex] = 1;
    while(!q.empty()){
        ll x = q.front();
        cout << x << E;
        q.pop();
        for(ll child : g[x]){
            if(vis[child]) continue;
            q.push(child);
            vis[child] = 1;
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
    return 0;
}


