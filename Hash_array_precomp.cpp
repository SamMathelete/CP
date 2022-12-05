/*

Given an array of n integers and q queries, print the count of integer x in each query.

1<=N<=10^5
1<=Ai<=10^7, as it is 10^7 we can use hash array declared globally.
1<=Q<=10^5

*/
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

const ll N = 1e7+10;
vector<ll> v(N, 0);

int main(){
    ll n, q, x, inp;
    cin >> n;
    for(ll i = 0; i<n; i++){
        cin >> inp;
        v[inp]++;
    }
    cin >> q;
    for(ll i = 0; i<q; i++){
        cin >> x;
        cout << v[x] << E;
    }
    return 0;
}