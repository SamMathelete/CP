/*

0-1 BFS Implementation

Question at : https://www.codechef.com/problems/REVERSE

Hint: Consider 1 weighted edge for opposite direction and 1 weight is push front 
Use Double Ended Queues

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
vector<ll> level(N, 1e9);

ll bfs(ll start, ll end){
    deque<ll> q;
    q.push_back(start);
    level[start] = 0;
    while(!q.empty()){
        ll x = q.front();
        q.pop_front();
        for(auto &child : g[x]){
            if(level[x] + child.second < level[child.first]){
                level[child.first] = level[x] + child.second;
                if(child.second){
                    q.push_front(child.first);
                }
                else{
                    q.push_back(child.first);
                }
            }
        }
    }
    return (level[end] == 1e9 ? -1 : level[end]);
}

int main(){
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i<m; i++){
        ll v1, v2;
        cin >> v1 >> v2;
        if(v1 == v2) continue;
        g[v1].pb({v2, 0});
        g[v2].pb({v1, 1});
    }
    cout << bfs(1, n) << E;
    return 0;
}
