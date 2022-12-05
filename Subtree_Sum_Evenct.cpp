/*

Given Q Queries and in each query given V,
print subtree sum of V and number of even numbers in subtree of V.

Logic: Precomputing Subtree sums and even count of subtree using dfs

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
vector<ll> stsum(N, 0);
vector<ll> evct(N, 0);

void dfs(ll vertex, ll parent = 0){
    stsum[vertex] += vertex;
    evct[vertex] += (vertex % 2 ? 0 : 1);
    for(ll child : g[vertex]){
        if(child == parent) continue;
        dfs(child, vertex);
        stsum[vertex] += stsum[child];
        evct[vertex] += evct[child];
    }
}

int main(){
    ll n, q, z;
    cin >> n;
    for(ll i = 0; i<n-1; i++){
        ll v1, v2;
        cin >> v1 >> v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    dfs(1);
    cin >> q;
    while(q--){
        cin >> z;
        cout << stsum[z] sp evct[z] << E;
    }
    return 0;
}