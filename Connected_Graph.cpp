/*

Question at: https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const int N = 1e5+10;
vector<vector<ll> > g(N);
vector<bool> vis(N, 0);
vector<vector<ll> > connc;
vector<ll> temp;

void dfs(ll vertex){
    if(vis[vertex]) return;
    temp.pb(vertex);
    vis[vertex] = 1;
    for(ll child : g[vertex]){
        dfs(child);
    }
}

int main(){
    ll n, m, ans = 0;
    cin >> n >> m;
    for(ll i = 0; i<m; i++){
        ll v1, v2;
        cin >> v1 >> v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    for(ll i = 1; i<=n; i++){
        if(vis[i] == 0){
            temp.clear();
            ans++;
            dfs(i);
            connc.pb(temp);
        }
    }
    cout << ans << E;
    /*for(auto &it : connc){
        for(auto &it1 : it){
            cout << it1 << " ";
        }
        cout << E;
    }*/
    return 0;
}
