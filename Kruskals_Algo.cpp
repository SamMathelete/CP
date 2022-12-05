/*

Kruskal's Algorithm for minimum spanning tree
(using dsu, avoid cycles(equal roots), and keep lowest weighted edges, 
finally connecting all vertices.)

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

const ll N = 1e5+10;
vector<ll> parent(N, 0);
vector<ll> siz(N, 0);

void make(ll a){
    parent[a] = a;
    siz[a] = 1;
}

ll fin(ll a){
    return(a == parent[a] ? a : parent[a] = fin(parent[a]));
}

void join(ll a, ll b){
    a = fin(a);
    b = fin(b);
    if(a != b){
        if(siz[a] < siz[b]) swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}

int main(){
    map<ll, vector<pair<ll, ll> > > ms;
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i<=n; i++){
        make(i);
    }
    vector<pair<ll, pair<ll, ll> > > edges;
    for(ll i = 0; i<m; i++){
        ll v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        edges.pb({wt, {v1, v2}});
    }
    sort(edges.begin(), edges.end());
    ll totwt = 0;
    for(auto &edge : edges){
        ll wt1 = edge.first, v1 = edge.second.first, v2 = edge.second.second;
        if(fin(v1) == fin(v2)) continue;
        join(v1, v2);
        ms[v1].pb({v2, wt1});
        totwt += wt1;
    }
    cout << totwt << E;
    for(auto &it : ms){
        for(auto &it1 : it.second){
            cout << it.first sp it1.first sp it1.second << E;
        }
    }
}