/*
To find the sum of elements of an array from index l to index r

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

int main(){
    ll n, inp;
    cin >> n;
    vector<ll> v(n+1, 0);
    for(ll i = 1; i<=n; i++){
        cin >> inp;
        v[i] = inp+v[i-1];
    }
    ll q;
    cin >> q;
    while (q--){
        ll l, r;
        cin >> l >> r;
        cout << v[r] - v[l-1] << E;
    }
    return 0;
}