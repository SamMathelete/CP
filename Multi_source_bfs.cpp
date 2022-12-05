/*

Multi Source BFS
(Initiate all sources into the queue)

Question at: https://www.codechef.com/problems/SNSOCIAL

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll N = 501;
ll n, m;
vector<vector<ll> > g(N, vector<ll>(N, 0));
vector<vector<ll> > vis(N, vector<ll>(N, 0));
vector<pair<ll, ll> > start;
vector<vector<ll> > level(N, vector<ll>(N, 1e9));
vector<pair<ll, ll> > mvmts = {
    {0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}
};

bool isValid(ll x, ll y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

void reset(){
    start.clear();
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            vis[i][j] = 0;
            level[i][j] = 1e9;
        }
    }
}

void bfs(){
    ll maxe = 0;
    queue<pair<ll, ll> > q;
    for(auto &it : start){
        q.push(it);
        vis[it.first][it.second] = 1;
        level[it.first][it.second] = 0;
    }
    while(!q.empty()){
        auto x = q.front();
        ll xx = x.first;
        ll yy = x.second;
        q.pop();
        for(auto &it1 : mvmts){
            ll x1 = xx + it1.first;
            ll y1 = yy + it1.second;
            if(!isValid(x1, y1)) continue;
            if(vis[x1][y1]) continue;
            q.push({x1, y1});
            vis[x1][y1] = 1;
            level[x1][y1] = level[xx][yy] + 1;
            maxe = max(maxe, level[x1][y1]);
        }
    }
    cout << maxe << E;
}

void solve(){
    ll maxee = -1;
    cin >> n >> m;
    reset();
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            cin >> g[i][j];
            if(g[i][j] > maxee){
                maxee = g[i][j];
            }
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(g[i][j] == maxee){
                start.pb({i, j});
            }
        }
    }
    bfs();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

