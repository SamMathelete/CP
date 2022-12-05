/*
Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each the array element between two given indices, inclusive. 
Once all operations have been performed, return the maximum value in the array.
*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n, 0);
    while(m--){
        ll a, b, k;
        cin >> a >> b >> k;
        v[a-1] += k;
        v[b] -= k;
    }
    for(ll i = 1; i<n; i++){
        v[i] += v[i-1];
    }
    ll m1 = *max_element(v.begin(), v.end());
    cout << m1 << E;
}