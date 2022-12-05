/*

Lowest Common Ancestor:
Step 1: Store the Path of both the nodes from the root in an array.(do this by storing the parent)
Step 2: Traverse both the arrays. The last common element is the answer.

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
vector<ll> p(N, -1);

void dfs(ll vertex, ll parent = -1){
    p[vertex] = parent;
    for(ll child : g[vertex]){
        if(child == parent) continue;
        dfs(child, vertex);
    }
}

vector<ll> path(ll n){
    vector<ll> ans;
    while(n != -1){
        ans.pb(n);
        n = p[n];
    }
    reverse(ans.begin(), ans.end()); //storage was in reverse order so reverse it before returning
    return ans;
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
    ll x, y;
    cin >> x >> y;
    vector<ll> px = path(x);
    vector<ll> py = path(y);
    ll lca = -1, min_ln = min(px.size(), py.size());
    for(ll i = 0; i<min_ln; i++){
        if(px[i] != py[i]) break;
        lca = px[i];
    }
    cout << lca << E;
    return 0;
}