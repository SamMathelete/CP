#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

int main(){
    ll n, inp1, inp2;
    cin >> n;
    vector<pair<ll, ll> > v;
    vector<pair<ll, ll> > :: iterator it; // declaring iterator
    for(ll i = 0; i<n; i++){
        cin >> inp1 >> inp2;
        v.pb(mp(inp1, inp2));
    }
    for(it = v.begin(); it != v.end(); it++){
        cout << it->first << " " << it->second << E; //Here 'it' is a pure iterator, so use '->' operator.
    }
    return 0;
}