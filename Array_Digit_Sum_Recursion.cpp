/*

Computing array sum and digit sum using recursion.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

ll arrsum(vector<ll> &v, ll n){
    if(n<0){
        return 0;
    }
    return v[n] + arrsum(v, n-1);
}

ll digsum(ll n){
    if(n==0){
        return 0;
    }
    return n%10 + digsum(n/10);
}

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i<n; i++){
        cin >> v[i];
    }
    cout << arrsum(v, n-1) << E;
    ll d;
    cin >> d;
    cout << digsum(d) << E;
    return 0;
}