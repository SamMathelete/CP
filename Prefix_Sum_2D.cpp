#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

int main(){
    ll n, m, inp;
    cin >> n >> m;
    vector<vector<ll> > v(n+1, vector<ll>(m+1, 0));
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=m; j++){
            cin >> inp;
            v[i][j] = inp + v[i-1][j] + v[i][j-1] - v[i-1][j-1]; 
        }
    }
    ll q, a, b, c, d;
    cin >> q;
    while(q--){
        cin >> a >> b >> c >> d;
        cout << v[c][d] - v[a-1][d] - v[c][b-1] + v[a-1][b-1] << E;
    }
    return 0;
}