#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

const ll N = 1e5+10;
vector<vector<ll> > g(N);
vector<ll> subsum(N, 0);
vector<ll> val(N);

void subtreesum(ll vertex, ll parent = -1){
    subsum[vertex] += val[vertex];
    for(ll child : vertex){
        if(child == parent) continue;
        subtreesum(child, vertex);
        subsum[vertex] += subsum[child];
    }
}

int main(){
    ll n;
    cin >> n;
    for(ll i = 1; i<=n; i++){
        cin >> val[i];
    }
    for(ll i = 0; i < n; i++){
        ll v1, v2;
        cin >> v1 >> v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    subtreesum(1);
    ll ans = 0;
    for(ll i = 2; i<=n; i++){
        ans = max(ans, subsum[i]*(subsum[1]-subsum[i]));
    }
    cout << ans << E;
    return 0;
}