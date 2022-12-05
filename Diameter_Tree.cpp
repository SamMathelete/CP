/*

Diameter of a Tree:
The Maximum number of edges between 2 vertices.

Step 1: With any root, find max depth node. This will always be one end of the diameter.
Step 2: With the previously found node taken as root, find the depth.
This depth is called the diameter of the tree.

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
vector<ll> depth(N, 0);

void dfs(ll vertex, ll parent = -1){
    for(ll child : g[vertex]){
        if(child == parent) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}

int main(){
    ll n;
    cin >> n;
    for(ll i = 0; i<n-1; i++){
        ll v1, v2;
        cin >> v1 >> v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    dfs(1);
    ll maxd = -1, maxdn = -1;
    for(ll i = 1; i<=n; i++){
        if(depth[i] > maxd){
            maxd = depth[i];
            maxdn = i;
        }
        depth[i] = 0;
    }
    dfs(maxdn);
    cout << *max_element(depth.begin(), depth.end()) << E;
    return 0;
}