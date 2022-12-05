/*

Dijkstra's Algorithm for Shortest Path:
Step 1: Initiate multiset of pairs
Step 2: Insert root node with distance 0
Step 3: With each child, insert it with distance as its weight if it was minimised
Step 4: On exit from the queue, mark the node visited
Step 5: If distance can be minimised, minimise it.

pair: {distance, node}

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll N = 1e5+10;
vector<vector<pair<ll, ll> > > g(N);
vector<ll> vis(N, 0);
vector<ll> dist(N, 1e9);

void djks(ll start, ll end){
    multiset<pair<ll, ll> > ms;
    ms.insert({0, start});
    dist[start] = 0;
    while(!ms.empty()){
        auto x = *ms.begin();
        ms.erase(ms.find(x));
        if(vis[x.second]) continue;
        vis[x.second] = 1;              //post processing mark visited
        for(auto &child : g[x.second]){
            if(dist[x.second] + child.first < dist[child.second]){ //check distance minimisation
                dist[child.second] = dist[x.second] + child.first;
                ms.insert({dist[child.second], child.second});  //if distance can be minimised minimise it.
            }
        }
    }
    cout << dist[end] << E;
    return;
}

int main(){
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        g[v1].pb({wt, v2});
    }
    ll st, e;
    cin >> st >> e;
    djks(st, e);
    return 0;
}