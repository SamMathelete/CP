/*

Floyd's Tortoise and Hare(Two Pointers) algorithm for array Traversal in 
O(N) Time Complexity and O(1) Space Complexity:

1. We use two pointers, one slow and another fast:
2. Slow Pointer: 
    Initiation: sp = arr[0];
    Traversal: sp = arr[sp];
3. Fast Pointer:
    Initiation: fp = arr[arr[fp]]
    Traversal: fp = arr[arr[fp]]
4. We use this for finding duplicates in an array:
So, when fp == sp, reset fp = 0 and now traverse fp as sp and again where they meet,
that number is duplicate.

IMP: This can detect only one duplicate at a time. So remove previously found duplicates to find multiple.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &it : v){
        cin >> it;
    }
    ll t = v[0], h = v[v[0]];
    while(t != h){
        t = v[t];
        h = v[v[h]];
    }
    h = 0;
    while(t != h){
        t = v[t];
        h = v[h];
    }
    cout << t << E;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}