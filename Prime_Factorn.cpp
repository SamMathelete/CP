/*

Prime Factorisation:

Some Extra Observations:
1. The smallest divisor(excluding 1) of any natural number is always prime.

*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<
 
using namespace std;

//Brute Force Approach to find prime Factorisation

vector<pair<ll, ll> > pf_bf(ll n){
    vector<pair<ll, ll> > v;
    if(n == 0){
        v.pb(mp(0, 0));
        return v;
    }
    if(n == 1){
        v.pb(mp(1, 1));
        return v;
    }
    for(ll i = 2; i*i<=n; i++){
        ll ct = 0;
        while(n % i == 0){
            ct++;
            n /= i;
        }
        if(ct > 0){
            v.pb(mp(i, ct));
        }
    }
    if(n>1){
        v.pb(mp(n, 1));
    }
    return v;
}

int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll> > v = pf_bf(n);
    for(auto &it : v){
        cout << it.first sp it.second << E;
    }
    return 0;
}
