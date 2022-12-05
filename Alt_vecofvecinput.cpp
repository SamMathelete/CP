/*

Alternate way of inputting vector of vectors.

*/
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

int main(){
    vector<vector<ll> > v;
    ll n, m, inp;
    cin >> n >> m;
    for(ll i = 0; i<n; i++){
        v.pb(vector<ll> ());     //pushbacks empty vector. Empty vector declaration can be done using vector<_type_> ().
        for(ll j = 0; j<m; j++){
            cin >> inp;
            v[i].pb(inp);
        }
    }
    for(auto &it : v){
        for(auto &it1 : it){
            cout << it1 << " ";
        }
        cout << E;
    }
    return 0;
}