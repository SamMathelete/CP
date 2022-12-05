/*

    author: SamTheMathlete
    submitted on: "<cmd + k> on me"

    Logic: Using kruskal's Algorithm, empty node for power station and minimum spanning tree and dsu.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

const ll N = 1e4;
vector<ll> parent(N, 0);
vector<ll> siz(N, 0);

void make(ll v){
    parent[v] = v;
    siz[v] = 1;
}

ll fin(ll v){
    return (v == parent[v] ? v : parent[v] = fin(parent[v]));
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<ll, vector<ll> > ms; 
    ll n, inp;
    cin >> n;
    for(ll i = 1; i<=n; i++){
        make(i);
    }
    vector<ll> x(n+1, 0);
    vector<ll> y(n+1, 0);
    for(ll i = 1; i<=n; i++){
        cin >> x[i] >> y[i];
    }
    vector<pair<ll, pair<ll, ll> > > edges;
    for(ll i = 1; i<=n; i++){
        cin >> inp;
        edges.pb({inp, {0, i}});
    }
    vector<ll> cost(n+1, 0);
    for(ll i = 1; i<=n; i++){
        cin >> cost[i];
    }
    ll cst;
    for(ll i = 1; i<n; i++){
        for(ll j = i+1; j<=n; j++){
            cst = (cost[i]+cost[j])*(abs(x[i] - x[j]) + abs(y[i] - y[j]));
            edges.pb({cst, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    ll totcost = 0, conn = 0;
    for(auto &edge : edges){
        ll wt = edge.first, v1 = edge.second.first, v2 = edge.second.second;
        if(fin(v1) == fin(v2)) continue;
        join(v1, v2);
        totcost += wt;
        if(v1 != 0) conn++;
        ms[v1].pb(v2);
    }
    cout << totcost << E;
    cout << ms[0].size() << E;
    for(auto &it : ms[0]){
        cout << it << " ";
    }
    cout << E;
    cout << conn << E;
    for(auto &it : ms){
        if(it.first != 0){
            for(auto &it1 : it.second){
                cout << it.first sp it1 << E;
            }
        }
    }
    return 0;
}