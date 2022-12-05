/*

Bipartite Graphs:
1. All vertices can be divided into two disjoint sets such that
   all edges connect vertex from one set to another.
2. These are useful to check for odd length cycles in graphs.
3. Checking is done by two coloring method.

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
vector<ll> color(N, -1);

bool bipartite_check(ll n){
    bool ans = true;
    queue<ll> q;
    for(ll start = 1; start<=n; start++){   //This line helps us check for disconnected components as well
        if(color[start] == -1){
            q.push(start);
            color[start] = 0;
            while(!q.empty()){
                ll x = q.front();
                q.pop();
                for(ll child : g[x]){
                    if(color[child] == -1){
                        color[child] = color[x]^1;
                        q.push(child);
                    }
                    else{
                        ans &= (color[child] != color[x]);
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i<m; i++){
        ll v1, v2;
        cin >> v1 >> v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    cout << (bipartite_check(n) ? "YES" : "NO") << E;
    return 0;
}