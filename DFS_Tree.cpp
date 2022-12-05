/*

DFS in a Tree:
Height and Depth of Tree using DFS

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll N = 1e5+10;
vector<ll> depth(N, 0);
vector<ll> height(N, 0);
vector<vector<ll> > g(N);

//Modified DFS for tree as trees do not have cycles, so we only have to avoid child calling parent.
//No need for visited array
void dfs(ll vertex, ll parent){
    for(ll child : g[vertex]){
        if(child == parent) continue; //if child == parent then skip it as it is already computed
        depth[child] = depth[vertex] + 1;   //before entring child, assign its depth
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1); //after exiting child, find height of parent
    }
}

int main(){
    ll n;
    cin >> n;
    for(ll i = 0; i < n-1; i++){ //trees have n vertices and n-1 edges
        ll v1, v2;
        cin >> v1 >> v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    dfs(1, 0);
    ll q;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        cout << height[x] sp depth[x] << E;
    }
    return 0;
}
