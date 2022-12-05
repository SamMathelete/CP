/*

Floyd Warshall Algorithm:
1. Used to find shortest path between any pair of vertices.
2. Can compute for negative weighted edges but no negative weighted cycles.

Hint: d[i][j] = min(d[i][j], d[i][k]+d[k][j]) for (k+1)th level 

*/

//Implementing for a directed graph using adjacency matrix

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

const ll N = 510;
const ll INF = 1e9;
vector<vector<ll> > dist(N, vector<ll>(N, INF)) ;

int main(){
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i<m; i++){
        ll v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        dist[v1][v2] = wt;
    }
    for(ll k = 1; k<=n; k++){
        for(ll i = 1; i<=n; i++){
            for(ll j = 1; j<=n; j++){
                if(i == j) dist[i][j] = 0;
                else if(dist[i][k] != INF && dist[k][j] != INF){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    //O(N^3)
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=n; j++){
            cout << (dist[i][j] == INF ? -1 : dist[i][j]) << " ";
        }
        cout << E;
    }
    return 0;
}